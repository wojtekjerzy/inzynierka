#ifndef MOCK_CONNECTION_H
#define MOCK_CONNECTION_H

#include "Base_Connection_Interface.h"

#include <gmock/gmock.h>

class Mock_Connection : public Base_Connection_Interface
{
public:
	~Mock_Connection() throw() {}

	MOCK_METHOD0(get_asio, std::shared_ptr <Base_Asio_For_Connection_Interface>());
	MOCK_METHOD0(receiving_request, void());
	MOCK_METHOD2(handle_read, void(const boost::system::error_code& e, std::size_t bytes_transferred));
	MOCK_METHOD1(handle_write, void(const boost::system::error_code& e));
};

#endif

