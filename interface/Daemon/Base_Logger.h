#ifndef BASE_LOGGER_H
#define BASE_LOGGER_H

#include <string>

class Base_Logger
{
public:
	virtual ~Base_Logger() = default;

	virtual void redirect_streams() = 0;
	virtual void make_log(const std::string& message) = 0;
	virtual void make_errlog(const std::string& message) = 0;
	virtual std::string get_filepath() const = 0;
	virtual std::string set_logger_time_and_paths() = 0;
	virtual std::string get_current_date() = 0;
	virtual std::string get_current_time() = 0;
};

#endif
