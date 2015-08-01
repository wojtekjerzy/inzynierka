#ifndef LOG_FORMATTER_H
#define LOG_FORMATTER_H

#include "Dir_Maintainer.h"
#include <Daemon/Base_Log_Formatter.h>

#include <memory>
#include <boost/date_time/posix_time/posix_time.hpp>

class Log_Formatter: public Base_Log_Formatter
{
public:
	Log_Formatter(std::shared_ptr <Base_Dir_Maintainer_Interface> dir_maintainer_);

	void make_log(const std::string& message) override;
	void make_errlog(const std::string& message) override;

private:
	std::string get_date();
	std::string get_time();
	void midnight_watch();

	std::shared_ptr <Base_Dir_Maintainer_Interface> dir_maintainer;
	std::string last_date;
};

#endif
