#include "Server.h"
#include "Asio_For_Server.h"

#include <boost/bind.hpp>
#include <utility>
#include <iostream>

Server::Server(Logger_Pointer logger_ptr_,
	HTTP_Maintainer_Pointer http_maintainer_,
	Daemon_Pointer daemon_ptr_,
	Connection_Factory_Pointer conn_factory_ptr_,
	Asio_For_Server_Pointer asio_ptr_)
	:
	logger_ptr(logger_ptr_),
	http_main_ptr(http_maintainer_),
	daemon_ptr(std::move(daemon_ptr_)),
	conn_factory_ptr(std::move(conn_factory_ptr_)),
	asio_ptr(std::move(asio_ptr_)),
	port(8080)
{
	if (asio_ptr == nullptr) {
		asio_ptr = std::make_shared <Asio_For_Server>(port);	
	}

	start_accept();
}

void Server::run()
{
	asio_ptr->run();
}

void Server::start_accept()
{
	try {
		if (daemon_ptr->get_stop()) {
			return;
		}

		connection_ptr.reset();
		connection_ptr = conn_factory_ptr->create_connection
			(logger_ptr, asio_ptr, http_main_ptr);
		logger_ptr->make_log(Const_Strings::ready_to_serve_clients +
					std::to_string(port));
		asio_ptr->accept(connection_ptr->get_asio(), this);
	} catch (std::exception& e) {
		logger_ptr->make_errlog(e.what());
		raise(SIGTERM);
	}
}

void Server::handle_accept(Error e)
{
	if (not asio_ptr->is_open()) {
		return;
	}

	if (!e) {
		connection_ptr->receiving_request();
	} else {
		logger_ptr->make_errlog(e.message());	
	}

	start_accept();
}
