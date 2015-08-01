#ifndef POSIX_SYSTEM_INTERFACE_H
#define POSIX_SYSTEM_INTERFACE_H

#include <Daemon/Base_System_Interface.h>

class POSIX_System_Interface : public Base_System_Interface
{
public:
	sighandler_t signal(int signum, sighandler_t handler) override;
	pid_t fork(void) override;
	pid_t getpid(void) override;
	pid_t setsid(void) override;
	unsigned int sleep(unsigned int seconds) override;
	unsigned chdir(char* dir) override;
	std::FILE* freopen (const char* filename, const char* mode, std::FILE* stream) override;
	mode_t umask(mode_t mask) override;
};

#endif
