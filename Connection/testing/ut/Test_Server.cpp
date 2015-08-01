#include "Test_Server.h"
#include <Connection/Const_Strings.h>

TEST_F(Test_Server, Server_is_created__accept_method_is_called)
{
	EXPECT_CALL(*test_daemon, get_stop())
			.WillOnce(testing::Return(false));

	EXPECT_CALL(*mock_connection_factory, create_connection(::testing::_, ::testing::_, ::testing::_))
			.WillOnce(testing::Return(test_connection));

	EXPECT_CALL(*test_log_formatter, make_log(Const_Strings::ready_to_serve_clients +
			std::to_string(port)));

	EXPECT_CALL(*test_connection, get_asio())
			.WillOnce(testing::Return(test_asio_for_conn));

	EXPECT_CALL(*test_asio_for_serv, accept(::testing::_, ::testing::_))
			.WillOnce(testing::Return());

	Server uut(test_log_formatter,
	test_http_maintainer,
	test_daemon,
	mock_connection_factory,
	test_asio_for_serv);
}

TEST_F(Test_Server, Server_is_created__corresponding_log_is_made)
{	
	EXPECT_CALL(*test_daemon, get_stop())
			.WillOnce(testing::Return(false));

	EXPECT_CALL(*mock_connection_factory, create_connection(::testing::_, ::testing::_, ::testing::_))
			.WillOnce(testing::Return(test_connection));


	EXPECT_CALL(*test_log_formatter, make_log(Const_Strings::ready_to_serve_clients +
						std::to_string(port)))
			.WillOnce(testing::Return());

	EXPECT_CALL(*test_connection, get_asio())
			.WillOnce(testing::Return(test_asio_for_conn));

	EXPECT_CALL(*test_asio_for_serv, accept(::testing::_, ::testing::_))
			.WillOnce(testing::Return());

	Server uut(test_log_formatter,
	test_http_maintainer,
	test_daemon,
	mock_connection_factory,
	test_asio_for_serv);

	EXPECT_CALL(*test_asio_for_serv, is_open())
			.WillOnce(testing::Return(false));

	uut.handle_accept(e);
}

TEST_F(Test_Server, when_Daemon_method_get_stop_is_true__Server_method_start_accept_is_out)
{
	EXPECT_CALL(*test_daemon, get_stop())
			.WillOnce(testing::Return(true));

	Server uut(test_log_formatter,
	test_http_maintainer,
	test_daemon,
	mock_connection_factory,
	test_asio_for_serv);
}


TEST_F(Test_Server, run_method_is_called__asio_ptr_run_method_is_called)
{
	EXPECT_CALL(*test_daemon, get_stop())
			.WillOnce(testing::Return(false));

	EXPECT_CALL(*mock_connection_factory, create_connection(::testing::_, ::testing::_, ::testing::_))
			.WillOnce(testing::Return(test_connection));
	
	EXPECT_CALL(*test_log_formatter, make_log(Const_Strings::ready_to_serve_clients +
			std::to_string(port)));

	EXPECT_CALL(*test_connection, get_asio())
			.WillOnce(testing::Return(test_asio_for_conn));

	EXPECT_CALL(*test_asio_for_serv, accept(::testing::_, ::testing::_))
			.WillOnce(testing::Return());

	Server uut(test_log_formatter,
	test_http_maintainer,
	test_daemon,
	mock_connection_factory,
	test_asio_for_serv);

	EXPECT_CALL(*test_asio_for_serv, run())
			.WillOnce(testing::Return());

	uut.run();
}

TEST_F(Test_Server, handle_accept_is_called_and_acceptor_isnt_open__method_is_out)
{
	EXPECT_CALL(*test_daemon, get_stop())
			.WillOnce(testing::Return(false));

	EXPECT_CALL(*mock_connection_factory, create_connection(::testing::_, ::testing::_, ::testing::_))
			.WillOnce(testing::Return(test_connection));

	EXPECT_CALL(*test_log_formatter, make_log(Const_Strings::ready_to_serve_clients +
			std::to_string(port)));

	EXPECT_CALL(*test_connection, get_asio())
			.WillOnce(testing::Return(test_asio_for_conn));

	EXPECT_CALL(*test_asio_for_serv, accept(::testing::_, ::testing::_))
			.WillOnce(testing::Return());

	Server uut(test_log_formatter,
	test_http_maintainer,
	test_daemon,
	mock_connection_factory,
	test_asio_for_serv);

	EXPECT_CALL(*test_asio_for_serv, is_open())
			.WillOnce(testing::Return(false));

	uut.handle_accept(e);
}


TEST_F(Test_Server, handle_accept_is_called_without_errors__receiving_request_and_start_accept_are_called)
{
	EXPECT_CALL(*test_daemon, get_stop())
			.WillOnce(testing::Return(false));

	EXPECT_CALL(*mock_connection_factory, create_connection(::testing::_, ::testing::_, ::testing::_))
			.WillOnce(testing::Return(test_connection));

	EXPECT_CALL(*test_log_formatter, make_log(Const_Strings::ready_to_serve_clients +
			std::to_string(port)));

	EXPECT_CALL(*test_connection, get_asio())
			.WillOnce(testing::Return(test_asio_for_conn));

	EXPECT_CALL(*test_asio_for_serv, accept(::testing::_, ::testing::_))
			.WillOnce(testing::Return());

	Server uut(test_log_formatter,
	test_http_maintainer,
	test_daemon,
	mock_connection_factory,
	test_asio_for_serv);

	EXPECT_CALL(*test_asio_for_serv, is_open())
			.WillOnce(testing::Return(true));

	EXPECT_CALL(*test_connection, receiving_request())
			.WillOnce(testing::Return());

	EXPECT_CALL(*test_daemon, get_stop())
			.WillOnce(testing::Return(true));

	uut.handle_accept(e);

}

