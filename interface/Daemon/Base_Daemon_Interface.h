#ifndef BASE_DAEMON_INTERFACE_H
#define BASE_DAEMON_INTERFACE_H

enum class EExitStatus : int
{
	EExitStatus_Remain = 0,
	EExitStatus_Stop = 1,
	EExitStatus_Fail = 2,
};

class Base_Daemon_Interface
{
public:
	virtual ~Base_Daemon_Interface() = default;

	virtual EExitStatus launch() = 0;
	virtual const bool get_stop() = 0;
};

#endif
