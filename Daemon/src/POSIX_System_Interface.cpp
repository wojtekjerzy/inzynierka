#include "POSIX_System_Interface.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

sighandler_t POSIX_System_Interface::signal(int signum, sighandler_t handler)
{
	return ::signal(signum, handler);
}

pid_t POSIX_System_Interface::fork(void)
{
	return ::fork();
}

pid_t POSIX_System_Interface::getpid(void)
{
	return ::getpid();
}

pid_t POSIX_System_Interface::setsid(void)
{
	return ::setsid();
}

unsigned int POSIX_System_Interface::sleep(unsigned int seconds)
{
	return ::sleep(seconds);
}

unsigned POSIX_System_Interface::chdir(char* dir)
{
	return ::chdir(dir);
}

std::FILE* POSIX_System_Interface::freopen (const char* filename, const char* mode, std::FILE* stream)
{
	return ::freopen(filename, mode, stream);
}

mode_t POSIX_System_Interface::umask(mode_t mask)
{
	return ::umask(mask);
}
