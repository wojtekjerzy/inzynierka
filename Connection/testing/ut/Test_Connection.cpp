#include "Test_Connection.h"
#include <Connection/Const_Strings.h>

TEST_F(Test_Connection, receiving_message_is_called__read_method_on_asio_ptr_is_called)
{
	EXPECT_CALL(*test_asio_for_conn, read(::testing::_))
			.WillOnce(testing::Return());

	uut->receiving_request();
}

TEST_F(Test_Connection, handle_read_is_called__response_is_send)
{
	EXPECT_CALL(*test_log_formatter, make_log(Const_Strings::client_ip
				+ local_host
				+ Const_Strings::colon
				+ port_numb));

	EXPECT_CALL(*test_asio_for_conn, get_ip())
			.WillOnce(testing::Return(local_host));

	EXPECT_CALL(*test_asio_for_conn, get_port())
			.WillOnce(testing::Return(port_numb));

	EXPECT_CALL(*test_asio_for_conn, convert_request_to_string(numb_of_bytes))
			.WillOnce(testing::Return(test_request));

	EXPECT_CALL(*test_log_formatter, make_log(Const_Strings::receiving_request));

	EXPECT_CALL(*test_http_maintainer, 
			parse_http_protocol_and_create_response
				(test_request))
			.WillOnce(testing::Return(test_response));

	EXPECT_CALL(*test_asio_for_conn, 
			write(::testing::_, test_response))
			.WillOnce(testing::Return());

	uut->handle_read(e, numb_of_bytes);
}

TEST_F(Test_Connection, handle_read_is_called__corresponding_log_is_made)
{
	EXPECT_CALL(*test_asio_for_conn, get_ip())
			.WillOnce(testing::Return(local_host));

	EXPECT_CALL(*test_asio_for_conn, get_port())
			.WillOnce(testing::Return(port_numb));

	EXPECT_CALL(*test_log_formatter, make_log
		(Const_Strings::client_ip + local_host 
					+ Const_Strings::colon 
					+ port_numb))
			.WillOnce(testing::Return());

	EXPECT_CALL(*test_log_formatter, 
			make_log(Const_Strings::receiving_request))
			.WillOnce(testing::Return());

	EXPECT_CALL(*test_asio_for_conn, convert_request_to_string(numb_of_bytes))
			.WillOnce(testing::Return(test_request));

	EXPECT_CALL(*test_http_maintainer, 
			parse_http_protocol_and_create_response
					(test_request))
			.WillOnce(testing::Return(test_response));

	EXPECT_CALL(*test_asio_for_conn, 
			write(::testing::_, test_response))
			.WillOnce(testing::Return());

	uut->handle_read(e, numb_of_bytes);
}

TEST_F(Test_Connection, handle_write_is_called__socket_is_closed)
{	
	EXPECT_CALL(*test_asio_for_conn, shutdown())
			.WillOnce(testing::Return());

	EXPECT_CALL(*test_asio_for_conn, close())
			.WillOnce(testing::Return());

	uut->handle_write(e);
	
}

TEST_F(Test_Connection, get_asio_is_called__Asio_For_Connection_pointer_is_returned)
{	
	EXPECT_EQ(uut->get_asio(), test_asio_for_conn);
}

