#include "Asio_For_Connection.h"
#include <boost/bind.hpp>

Asio_For_Connection::Asio_For_Connection(std::shared_ptr <Base_Asio_For_Server_Interface> asio_for_serv_)
	:
	socket(asio_for_serv_->get_io_service())
{
}

boost_socket::socket& Asio_For_Connection::get_socket()
{
	return socket;
}

std::string Asio_For_Connection::get_ip()
{
	return socket.remote_endpoint().address().to_string();
}
std::string Asio_For_Connection::get_port()
{
	return std::to_string(socket.remote_endpoint().port());
}

void Asio_For_Connection::read(boost::shared_ptr <Base_Connection_Interface> conn_ptr)
{
	socket.async_read_some(boost::asio::buffer(buffer),
	boost::bind(&Base_Connection_Interface::handle_read, conn_ptr,
	boost::asio::placeholders::error,
	boost::asio::placeholders::bytes_transferred));
}

std::string Asio_For_Connection::convert_request_to_string(std::size_t bytes_transferred)
{
	return std::string(buffer.begin(), buffer.begin() + bytes_transferred);
}

void Asio_For_Connection::write(boost::shared_ptr <Base_Connection_Interface> conn_ptr,
							 const std::string& response)
{
	boost::asio::async_write(socket, boost::asio::buffer(response),
		boost::bind(&Base_Connection_Interface::handle_write, conn_ptr,
					 boost::asio::placeholders::error));
}

void Asio_For_Connection::shutdown()
{
	boost::system::error_code ignored_ec;
	socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
}

void Asio_For_Connection::close()
{
	socket.close();
}
