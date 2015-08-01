#ifndef MOCK_SYSTEM_INTERFACE_H
#define MOCK_SYSTEM_INTERFACE_H

#include "Base_System_Interface.h"

#include <gmock/gmock.h>

class Mock_System_Interface : public Base_System_Interface
{
public:
	~Mock_System_Interface() throw() {}

	MOCK_METHOD2(signal, sighandler_t(int, sighandler_t));
	MOCK_METHOD0(fork, pid_t());
	MOCK_METHOD0(getpid, pid_t());
	MOCK_METHOD0(setsid, pid_t());
	MOCK_METHOD1(sleep, unsigned int(unsigned int));
	MOCK_METHOD1(chdir, unsigned int(char*));
	MOCK_METHOD3(freopen, std::FILE*(const char*, const char*, std::FILE*));
	MOCK_METHOD1(umask, mode_t(mode_t));
};

#endif
