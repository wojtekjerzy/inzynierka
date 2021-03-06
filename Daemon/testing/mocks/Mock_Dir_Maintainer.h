#ifndef MOCK_DIR_MAINTAINER_H
#define MOCK_DIR_MAINTAINER_H

#include <Daemon/Base_Dir_Maintainer_Interface.h>
#include <gmock/gmock.h>

class Mock_Dir_Maintainer : public Base_Dir_Maintainer_Interface
{
public:
	~Mock_Dir_Maintainer() throw() {}

	MOCK_METHOD1(create_working_dir, void(std::string));
	MOCK_METHOD0(set_time_and_path, std::string());
	MOCK_METHOD0(redirect_streams, void());
	MOCK_METHOD0(get_last_date, std::string());	
};

#endif
