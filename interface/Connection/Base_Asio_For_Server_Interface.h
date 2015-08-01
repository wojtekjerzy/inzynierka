#ifndef BASE_ASIO_FOR_SERVER_INTERFACE_H
#define BASE_ASIO_FOR_SERVER_INTERFACE_H

#include "Base_Server_Interface.h"
#include "Base_Asio_For_Connection_Interface.h" 

#include <boost/asio.hpp>

class Server;

class Base_Asio_For_Server_Interface
{
public:
	virtual ~Base_Asio_For_Server_Interface() = default;

	virtual boost::asio::io_service& get_io_service() = 0;
	virtual void run() = 0;
	virtual void accept(std::shared_ptr <Base_Asio_For_Connection_Interface> asio_conn_ptr,
						 Base_Server_Interface* server_ptr) = 0;
	virtual bool is_open() = 0;
};

#endif

