#ifndef TEST_DAEMON_H
#define TEST_DAEMON_H

#include "Daemon.h"
#include "Mock_System_Interface.h"

#include <gtest/gtest.h>

class Test_Daemon : public ::testing::Test
{
protected:
	Test_Daemon()
	{
	}

	Daemon uut;
};

#endif
