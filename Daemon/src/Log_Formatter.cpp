#include "Log_Formatter.h"

Log_Formatter::Log_Formatter(std::shared_ptr <Base_Dir_Maintainer_Interface> dir_maintainer_)
	: dir_maintainer(dir_maintainer_), last_date(dir_maintainer_->get_last_date())
{
}

void Log_Formatter::make_log(const std::string& message)
{
	midnight_watch();
	std::cout << get_time() << " LOG: " << " \"" << message << "\"\n" << std::flush;
}

void  Log_Formatter::make_errlog(const std::string& message)
{
	midnight_watch();
	std::cout << "!-" << get_time() << " ERR: " << " \"" << message << "\"\n" << std::flush;
}

std::string Log_Formatter::get_date()
{
	using namespace boost::posix_time;
	using namespace boost::gregorian;

	ptime now = second_clock::local_time();

	return to_simple_string(now.date());
}

std::string Log_Formatter::get_time()
{
	using namespace boost::posix_time;
	using namespace boost::gregorian;

	ptime now = second_clock::local_time();

	std::stringstream time_formatted;
	time_formatted << to_simple_string(now.date()) << "_" << to_simple_string(now.time_of_day());

	return time_formatted.str();
}

void Log_Formatter::midnight_watch()
{
	std::string current_date = get_date();

	if (strcmp(last_date.c_str(), current_date.c_str())) {

		last_date = current_date;
		make_log("Logs moved to new file: date change " + current_date);
		dir_maintainer->redirect_streams();

		std::stringstream log;
		log << "New day running process: " << getpid();
		make_log(log.str());
	}
}
