#include "./Daemon/src/Daemon.h"
#include "./Daemon/src/Dir_Maintainer.h"
#include "./Daemon/src/Log_Formatter.h"
#include "./Daemon/src/POSIX_System_Interface.h"
#include "./interface/Daemon/Base_System_Interface.h"
#include "./interface/Connection/Const_Strings.h"
#include "./Connection/src/Server.h"
#include "./Connection/src/Connection.h"
#include "./Connection/src/Connection_Factory.h"

#include <boost/thread/thread.hpp>
#include <map>
#include <boost/make_shared.hpp>

void log_with_pid(std::string message_log, std::shared_ptr <Base_Log_Formatter> logger_pointer)
{
	std::stringstream log;
	log << message_log << getpid();
	logger_pointer->make_log(log.str());
}

int main(int argc, char* argv[]) {

	std::shared_ptr <Base_Daemon_Interface> daemon_ptr = std::make_shared <Daemon> (8080);
	EExitStatus status = daemon_ptr->launch();
	if (status == EExitStatus::EExitStatus_Stop) {
		return EXIT_SUCCESS;
	}

	else if (status == EExitStatus::EExitStatus_Fail) {
		return EXIT_FAILURE;
	}

	std::shared_ptr <Dir_Maintainer> f_manager = std::make_shared <Dir_Maintainer> ();

	f_manager->redirect_streams();

	std::shared_ptr <Base_Log_Formatter> logger_pointer = std::make_shared <Log_Formatter> (f_manager);

	log_with_pid(Const_Strings::start_log, logger_pointer);

	std::shared_ptr <Base_HTTP_Maintainer_Interface> http_maintainer_pointer = std::make_shared <HTTP_Maintainer> (
													logger_pointer);
	std::shared_ptr <Base_Connection_Factory_Interface> conn_factory_pointer = std::make_shared <Connection_Factory> ();


	try {
		std::shared_ptr <Base_Server_Interface> ptr_server = std::make_shared <Server> (logger_pointer,
					http_maintainer_pointer, daemon_ptr, conn_factory_pointer);
		ptr_server->run();

	} catch (std::exception& e) {
		logger_pointer->make_errlog(e.what());
	}

	log_with_pid(Const_Strings::end_log, logger_pointer);

	return EXIT_SUCCESS;
}
