#ifndef MOCK_CONNECTION_FACTORY
#define MOCK_CONNECTION_FACTORY

#include "Base_Connection_Factory_Interface.h"

class Mock_Connection_Factory : public Base_Connection_Factory_Interface
{
public:
	~Mock_Connection_Factory() throw() {}

	MOCK_METHOD3(create_connection, boost::shared_ptr <Base_Connection_Interface>
		(std::shared_ptr <Base_Log_Formatter> logger_pointer_,
		std::shared_ptr <Base_Asio_For_Server_Interface> asio_for_serv_ptr_,
		std::shared_ptr <Base_HTTP_Maintainer_Interface> http_maintainer_));
};

#endif
