#ifndef MOCK_LOG_FORMATTER_H
#define MOCK_LOG_FORMATTER_H

#include <Daemon/Base_Log_Formatter.h>
#include <gmock/gmock.h>

class Mock_Log_Formatter : public Base_Log_Formatter
{
public:
	~Mock_Log_Formatter() throw() {}
	MOCK_METHOD0(redirect_streams, void());
	MOCK_METHOD1(make_log, void(const std::string&));
	MOCK_METHOD1(make_errlog, void(const std::string&));
	MOCK_CONST_METHOD0(get_filepath, std::string());
	MOCK_METHOD1(set_userpath, void(const std::string&));
	MOCK_METHOD0(set_Log_Formatter_time_and_paths, std::string());
	MOCK_METHOD0(get_current_date, std::string());
	MOCK_METHOD0(get_current_time, std::string());
};

#endif
