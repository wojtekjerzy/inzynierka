#ifndef BASE_CONNECTION_INTERFACE_H
#define BASE_CONNECTION_INTERFACE_H

#include "Base_Asio_For_Connection_Interface.h"

#include <boost/asio.hpp>

class Base_Asio_For_Connection_Interface;

typedef std::shared_ptr <Base_Asio_For_Connection_Interface> Asio_For_Connection_Pointer;
typedef const boost::system::error_code& Error;
typedef boost::asio::ip::tcp boost_socket;

class Base_Connection_Interface
{
public:
	virtual ~Base_Connection_Interface() = default;

	virtual Asio_For_Connection_Pointer get_asio() = 0;
	virtual void receiving_request() = 0;
	virtual void handle_read(Error e, std::size_t bytes_transferred) = 0;
	virtual void handle_write(Error e) = 0;
};

#endif
