#include "Daemon.h"

#include <unistd.h>
#include <sstream>

unsigned Daemon::server_port;

Daemon::Daemon(unsigned server_port_, std::shared_ptr <Base_System_Interface> base_s_i_pointer)
{
	if (base_s_i_pointer == nullptr) {
		ptr_system_interface = std::make_shared <POSIX_System_Interface>();
	} else {
		ptr_system_interface = base_s_i_pointer;
	}
	server_port = server_port_;
}

bool Daemon::stop = false;

void Daemon::signal_handler(sig_atomic_t param)
{
	stop = true;
	std::stringstream call;
	call << "wget -q -T1 -t1 --no-http-keep-alive localhost:" << server_port;
	system (call.str().c_str());
}

const bool Daemon::get_stop()
{
	return stop;
}

EExitStatus Daemon::launch()
{
	pid_t cpid = ptr_system_interface->fork();

	if (cpid>0) {
		return EExitStatus::EExitStatus_Stop;
	}

	else if (cpid<0) {
		return EExitStatus::EExitStatus_Fail;
	}

	pid_t sid = ptr_system_interface->setsid();

	if (sid<0) {
		return EExitStatus::EExitStatus_Fail;
	}

	ptr_system_interface->signal(SIGTERM, Daemon::signal_handler);
	ptr_system_interface->signal(SIGCHLD, SIG_IGN);
	ptr_system_interface->signal(SIGHUP, SIG_IGN);

	cpid = ptr_system_interface->fork();

	if (cpid>0) {
		return EExitStatus::EExitStatus_Stop;
	}

	else if (cpid<0) {
		return EExitStatus::EExitStatus_Fail;
	}

	ptr_system_interface->umask(0);
	ptr_system_interface->chdir(getenv("HOME"));

	return EExitStatus::EExitStatus_Remain;
}
