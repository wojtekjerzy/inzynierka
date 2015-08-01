#ifndef TEST_DIR_MAINTAINER_H
#define TEST_DIR_MAINTAINER_H

#include "Dir_Maintainer.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

class Test_Dir_Maintainer : public ::testing::Test
{
public:
	Test_Dir_Maintainer()
	{
	}

	Dir_Maintainer uut;
};

#endif
