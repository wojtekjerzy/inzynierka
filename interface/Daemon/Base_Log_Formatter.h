#ifndef BASE_LOG_FORMATTER_H
#define BASE_LOG_FORMATTER_H

#include <string>
#include <sys/types.h>

class Base_Log_Formatter
{
public:
	virtual ~Base_Log_Formatter() = default;

	virtual void make_log(const std::string& message) = 0;
	virtual void make_errlog(const std::string& message) = 0;
};

#endif
