#ifndef BASE_SERVER_INTERFACE_H
#define BASE_SERVER_INTERFACE_H

#include <boost/system/error_code.hpp>

typedef const boost::system::error_code& Error;

class Base_Server_Interface
{
public:
	virtual ~Base_Server_Interface() = default;

	virtual void run() = 0;
	virtual void handle_accept(Error e) = 0;
};

#endif
