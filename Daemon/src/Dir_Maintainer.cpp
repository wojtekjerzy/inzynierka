#include "Dir_Maintainer.h"

#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <utility>

Dir_Maintainer::Dir_Maintainer()
{
}	

std::string Dir_Maintainer::current_time()
{
	using namespace boost::posix_time;
	using namespace boost::gregorian;

	ptime now = second_clock::local_time();

	std::stringstream time_formatted;
	time_formatted << to_simple_string(now.date()) << "_" << to_simple_string(now.time_of_day());

	return time_formatted.str();
}

std::string Dir_Maintainer::set_time_and_path()
{
	std::string now = current_time();
	last_date = now.substr(0, now.find_last_of("_"));
	last_time = now;
	std::stringstream filename;
	filename << "log_"<< getpid() << "_" << last_time;
	std::stringstream filepath;
	std::string dirpath = make_dir();
	filepath << dirpath << "/" << filename.str();
	last_filepath = filepath.str();
	return last_filepath;
}

std::string Dir_Maintainer::make_dir()
{
	std::stringstream dirname;
	dirname << choose_dirname();
	dirname << "/logs_" << last_date;
	boost::filesystem::create_directories (dirname.str());

	return dirname.str();
}

void Dir_Maintainer::redirect_streams()
{
	const std::string& filepath = set_time_and_path();

	std::freopen(filepath.c_str(), "wa", stdout);
	std::freopen(filepath.c_str(), "wa", stderr);
	std::freopen("/dev/null", "r", stdin);
}

std::string Dir_Maintainer::get_last_date()
{
	return last_date;
}

std::string Dir_Maintainer::choose_dirname(){

	std::string user_path = "/Desktop/inzynierka/logs";
	std::string return_dirname = getenv("HOME");

	return return_dirname + user_path;
}
