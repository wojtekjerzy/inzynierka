#ifndef CONNECTION_H
#define CONNECTION_H

#include "HTTP_Maintainer.h"

#include <Daemon/Base_Log_Formatter.h>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <Connection/Base_Connection_Interface.h>

class Base_Asio_For_Connection_Interface;
class Base_Asio_For_Server_Interface;

typedef std::shared_ptr <Base_Asio_For_Server_Interface> Asio_For_Server_Pointer;
typedef std::shared_ptr <Base_HTTP_Maintainer_Interface> HTTP_Maintainer_Pointer;

class Connection
	: public boost::enable_shared_from_this<Connection>,
	public Base_Connection_Interface
{
public:
	Connection(Logger_Pointer logger_pointer_,
		Asio_For_Server_Pointer asio_for_serv_ptr_,
		HTTP_Maintainer_Pointer http_maintainer_,
		Asio_For_Connection_Pointer asio_ptr_ = nullptr);
	~Connection() throw() {}

	Asio_For_Connection_Pointer get_asio() override;
	void receiving_request() override;
	void handle_read(Error e, std::size_t bytes_transferred) override;
	void handle_write(Error e) override;

private:
	std::string get_client_ip();
	std::string get_client_port();
	std::string create_response(const std::string& receiving_message);
	void send_response();

	std::string response;
	Logger_Pointer logger_ptr;
	HTTP_Maintainer_Pointer ptr_http_maintainer;
	Asio_For_Connection_Pointer asio_ptr;
};

#endif
