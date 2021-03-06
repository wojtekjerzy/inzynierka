#ifndef DIR_MAINTAINER_H
#define DIR_MAINTAINER_H

#include <Daemon/Base_Dir_Maintainer_Interface.h>

#include <dirent.h>

class Dir_Maintainer : public Base_Dir_Maintainer_Interface
{
public:
	Dir_Maintainer();

	std::string set_time_and_path() override;
	void redirect_streams() override;
	std::string get_last_date() override;

private:
	std::string current_time();
	std::string last_date;
	std::string last_time;
	std::string last_filepath;
	std::string make_dir();

	std::string choose_dirname();
};

#endif
