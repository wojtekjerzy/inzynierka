#ifndef TEST_HTTP_MAINTAINER_H
#define TEST_HTTP_MAINTAINER_H

#include "Mock_Log_Formatter.h"
#include "HTTP_Maintainer.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

using ::testing::NiceMock;

class Test_HTTP_Maintainer : public ::testing::Test
{
protected:
	Test_HTTP_Maintainer()
		:uut(test_log_formatter)
	{}
	std::shared_ptr <Mock_Log_Formatter> test_log_formatter
				{ std::make_shared <Mock_Log_Formatter> ()};
	HTTP_Maintainer uut;
};

#endif

