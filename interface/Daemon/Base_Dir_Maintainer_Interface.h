#ifndef BASE_DIR_MAINTAINER_INTERFACE_H
#define BASE_DIR_MAINTAINER_INTERFACE_H

#include <iostream>

class Base_Dir_Maintainer_Interface
{
public:
	virtual ~Base_Dir_Maintainer_Interface() = default;

	virtual std::string set_time_and_path() = 0;
	virtual void redirect_streams() = 0;
	virtual std::string get_last_date() = 0;
};

#endif
