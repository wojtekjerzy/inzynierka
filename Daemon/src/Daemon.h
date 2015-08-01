#ifndef DAEMON_H
#define DAEMON_H

#include "POSIX_System_Interface.h"

#include <Daemon/Base_Daemon_Interface.h>
#include <Daemon/Base_System_Interface.h>
#include <memory>
#include <cstdlib>

class Daemon : public Base_Daemon_Interface
{
public:
	Daemon(unsigned server_port_ = 0, std::shared_ptr <Base_System_Interface> base_s_i_pointer = nullptr);

	EExitStatus launch() override;
	const bool get_stop() override;

private:
	static void signal_handler(sig_atomic_t param);

	std::shared_ptr <Base_System_Interface> ptr_system_interface;
	static Base_System_Interface& system_interface;
	static unsigned server_port;
	static bool stop;
};

#endif
