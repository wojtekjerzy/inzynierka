#ifndef BASE_SYSTEM_INTERFACE_H
#define BASE_SYSTEM_INTERFACE_H

#include <csignal>
#include <cstdio>
#include <sys/types.h>

class Base_System_Interface
{
public:
	virtual ~Base_System_Interface() = default;

	virtual sighandler_t signal(int signum, sighandler_t handler) = 0;
	virtual pid_t fork() = 0;
	virtual pid_t getpid() = 0;
	virtual pid_t setsid() = 0;
	virtual unsigned sleep(unsigned seconds) = 0;
	virtual unsigned chdir(char* dir) = 0;
	virtual std::FILE* freopen(const char* filename, const char* mode, std::FILE* stream) = 0;
	virtual mode_t umask(mode_t mask) = 0;
};

#endif
