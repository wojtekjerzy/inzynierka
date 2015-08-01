#ifndef CONNECTION_FACTORY_H
#define CONNECTION_FACTORY_H

#include <Connection/Base_Connection_Factory_Interface.h>

class Connection_Factory : public Base_Connection_Factory_Interface
{
public:
	Connection_Factory() = default;

	boost::shared_ptr <Base_Connection_Interface> create_connection(std::shared_ptr <Base_Log_Formatter> logger_pointer_,
		std::shared_ptr <Base_Asio_For_Server_Interface> asio_for_serv_,
		std::shared_ptr <Base_HTTP_Maintainer_Interface> http_maintainer_) override;
};

#endif
