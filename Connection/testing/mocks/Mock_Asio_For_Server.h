#ifndef MOCK_ASIO_FOR_SERVER_H
#define MOCK_ASIO_FOR_SERVER_H

#include "Base_Asio_For_Server_Interface.h"
#include "Base_Server_Interface.h"

#include <gmock/gmock.h>


class Mock_Asio_For_Server : public Base_Asio_For_Server_Interface
{
public:
	~Mock_Asio_For_Server() throw() {};
	MOCK_METHOD0(get_io_service, boost::asio::io_service&());
	MOCK_METHOD0(run, void());
	MOCK_METHOD2(accept, void(std::shared_ptr <Base_Asio_For_Connection_Interface> asio_conn_ptr,
				 Base_Server_Interface* server_ptr));
	MOCK_METHOD0(is_open, bool());
};

#endif
