#ifndef BASE_ASIO_FOR_CONNECTION_INTERFACE_H
#define BASE_ASIO_FOR_CONNECTION_INTERFACE_H

#include "Base_Connection_Interface.h"

#include <boost/asio.hpp>

typedef boost::asio::ip::tcp boost_socket;

class Base_Connection_Interface;

class Base_Asio_For_Connection_Interface
{
public:
	virtual ~Base_Asio_For_Connection_Interface() = default;

	virtual boost_socket::socket& get_socket() = 0;
	virtual std::string get_ip() = 0;
	virtual std::string get_port() = 0;
	virtual void read(boost::shared_ptr <Base_Connection_Interface> conn_ptr) = 0;
	virtual std::string convert_request_to_string(std::size_t bytes_transferred) = 0;
	virtual void write(boost::shared_ptr <Base_Connection_Interface> conn_ptr,
				const std::string& response) = 0;
	virtual void close() = 0;
	virtual void shutdown() = 0;
};

#endif


