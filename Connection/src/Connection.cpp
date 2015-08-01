#include "Connection.h"
#include "Const_Strings.h"
#include "Asio_For_Connection.h"

#include <iostream>
#include <chrono>
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sstream>
#include <iostream>
#include <boost/exception/diagnostic_information.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>

Connection::Connection(Logger_Pointer logger_pointer_,
		Asio_For_Server_Pointer asio_for_serv_ptr_,
		HTTP_Maintainer_Pointer http_maintainer_,
		Asio_For_Connection_Pointer asio_ptr_)
	:
	logger_ptr(logger_pointer_),
	ptr_http_maintainer(http_maintainer_),
	asio_ptr(asio_ptr_)
{
	if (asio_ptr == nullptr) {
		asio_ptr = std::make_shared <Asio_For_Connection> (asio_for_serv_ptr_);
	}
}

Asio_For_Connection_Pointer Connection::get_asio()
{
	return asio_ptr;
}

std::string Connection::get_client_ip()
{
	return asio_ptr->get_ip();
}

std::string Connection::get_client_port()
{
	return asio_ptr->get_port();
}

void Connection::receiving_request()
{
	try {
		asio_ptr->read(shared_from_this());
	}

	catch (boost::exception& ex) {
		std::cerr << boost::diagnostic_information(ex);
	}
}

void Connection::handle_read(Error e, std::size_t bytes_transferred)
{
	logger_ptr->make_log(Const_Strings::client_ip
				+ get_client_ip()
				+ Const_Strings::colon
				+ get_client_port());
	logger_ptr->make_log(Const_Strings::receiving_request);

	std::string receiving_message = asio_ptr->convert_request_to_string(bytes_transferred);

	response = create_response(receiving_message);
	send_response();
}

std::string Connection::create_response(const std::string& receiving_message)
{
	return ptr_http_maintainer->
		parse_http_protocol_and_create_response(receiving_message);
}

void Connection::send_response()
{
	asio_ptr->write(shared_from_this(), response);
}

void Connection::handle_write(Error e)
{
	if (!e) {
		asio_ptr->shutdown();
	}

	if (e != boost::asio::error::operation_aborted) {
		asio_ptr->close();
	}
}
