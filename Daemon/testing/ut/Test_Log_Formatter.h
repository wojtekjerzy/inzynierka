#ifndef TEST_LOG_FORMATTER_H
#define TEST_LOG_FORMATTER_H

#include "Log_Formatter.h"
#include "../testing/mocks/Mock_Dir_Maintainer.h"

#include <gtest/gtest.h>

class Test_Log_Formatter : public ::testing::Test
{
protected:
	Test_Log_Formatter():
		uut(test_dir_maintainer)
	{
	}

	std::shared_ptr <Base_Dir_Maintainer_Interface> test_dir_maintainer =
		std::make_shared<Mock_Dir_Maintainer> ();
	Log_Formatter uut;
};

#endif
