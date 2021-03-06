#ifndef SERVER_H
#define SERVER_H

#include "Connection.h"

#include <Connection/Const_Strings.h>
#include <Daemon/Base_Log_Formatter.h>
#include <Daemon/Base_Daemon_Interface.h>
#include <Connection/Base_Server_Interface.h>
#include <Connection/Base_Connection_Factory_Interface.h>
#include <Connection/Base_HTTP_Maintainer_Interface.h>
#include <boost/enable_shared_from_this.hpp>

typedef std::shared_ptr <Base_Daemon_Interface> Daemon_Pointer;
typedef std::shared_ptr <Base_Connection_Factory_Interface> Connection_Factory_Pointer;
typedef boost::shared_ptr <Base_Connection_Interface> Connection_Pointer;

class Base_Asio_For_Server_Interface;
class Base_Connection_Factory_Interface;

class Server : public Base_Server_Interface, public boost::enable_shared_from_this <Server>
{
public:

	Server(Logger_Pointer logger_ptr_,
	HTTP_Maintainer_Pointer http_maintainer_,
	Daemon_Pointer daemon_ptr_,
	Connection_Factory_Pointer conn_factory_ptr_,
	Asio_For_Server_Pointer asio_ptr_ = nullptr);
	~Server() throw() {}

	void run() override;
	void handle_accept(Error e) override;

private:
	void start_accept();

	Logger_Pointer logger_ptr;
	HTTP_Maintainer_Pointer http_main_ptr;
	Daemon_Pointer daemon_ptr;
	Connection_Factory_Pointer conn_factory_ptr;
	Asio_For_Server_Pointer asio_ptr;	
	Connection_Pointer connection_ptr;
	unsigned short int port;	
};

#endif
