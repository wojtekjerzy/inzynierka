#ifndef TEST_CONNECTION_H
#define TEST_CONNECTION_H

#include "Mock_Log_Formatter.h"
#include "Mock_HTTP_Maintainer.h"
#include "Mock_Asio_For_Server.h"
#include "Mock_Asio_For_Connection.h"
#include "Connection.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <boost/make_shared.hpp>

using ::testing::NiceMock;

class Test_Connection : public ::testing::Test
{
protected:
	Test_Connection()
	{
	}

	std::shared_ptr <Mock_Log_Formatter> test_log_formatter 
			{ std::make_shared  <Mock_Log_Formatter> ()};
	std::shared_ptr <Mock_Asio_For_Server> test_asio_for_serv 
			{ std::make_shared <Mock_Asio_For_Server> ()};
	std::shared_ptr <Mock_HTTP_Maintainer> test_http_maintainer 
			{ std::make_shared <Mock_HTTP_Maintainer> ()};
	std::shared_ptr <Mock_Asio_For_Connection> test_asio_for_conn 
			{ std::make_shared <Mock_Asio_For_Connection> ()};
	boost::system::error_code e;
	std::size_t numb_of_bytes = 44;
	std::string test_request = "test_request";
	std::string test_response = "test_response";
	std::string port_numb = "8080";
	std::string local_host = "127.0.0.1";
	boost::shared_ptr <Base_Connection_Interface> uut {
		boost::make_shared <Connection> (test_log_formatter, test_asio_for_serv, test_http_maintainer, 
		test_asio_for_conn)};
};

#endif
