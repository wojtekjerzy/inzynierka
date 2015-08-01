#include "Asio_For_Server.h"

#include <boost/bind.hpp>

Asio_For_Server::Asio_For_Server(int port_number)
	:
	io_service(),
	endpoint(boost_socket::v4(), port_number),
	acceptor(io_service, endpoint)
{
}

boost::asio::io_service& Asio_For_Server::get_io_service()
{
	return io_service;
}

void Asio_For_Server::run()
{
	io_service.run();
}

void Asio_For_Server::accept(std::shared_ptr <Base_Asio_For_Connection_Interface> asio_conn_ptr,
								Base_Server_Interface* server_ptr)
{
	acceptor.async_accept(asio_conn_ptr->get_socket(),
			boost::bind(&Base_Server_Interface::handle_accept, server_ptr, ignored_error));
}

bool Asio_For_Server::is_open()
{
	return acceptor.is_open();
}

