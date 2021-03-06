#ifndef TEST_SERVER_H
#define TEST_SERVER_H

#include "Mock_Log_Formatter.h"
#include "Mock_HTTP_Maintainer.h"
#include "Mock_Daemon.h"
#include "Mock_Connection_Factory.h"
#include "Mock_Asio_For_Server.h"
#include "Mock_Asio_For_Connection.h"
#include "Mock_Connection.h"
#include "Server.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <boost/make_shared.hpp>

class Test_Server : public ::testing::Test
{
protected:
	Test_Server()
	{
	}

	std::shared_ptr <Mock_Log_Formatter> test_log_formatter { std::make_shared  <Mock_Log_Formatter> ()};
	std::shared_ptr <Mock_HTTP_Maintainer> test_http_maintainer { std::make_shared <Mock_HTTP_Maintainer>()};
	std::shared_ptr <Mock_Daemon> test_daemon { std::make_shared <Mock_Daemon>()};
	std::shared_ptr <Mock_Connection_Factory> mock_connection_factory { std::make_shared <Mock_Connection_Factory> ()};
	std::shared_ptr <Mock_Asio_For_Server> test_asio_for_serv { std::make_shared <Mock_Asio_For_Server> ()};
	std::shared_ptr <Mock_Asio_For_Connection> test_asio_for_conn { std::make_shared <Mock_Asio_For_Connection> ()};
	boost::shared_ptr <Mock_Connection> test_connection { boost::make_shared <Mock_Connection> ()};
	unsigned short int port = 8080;
	const boost::system::error_code e;
};
#endif

