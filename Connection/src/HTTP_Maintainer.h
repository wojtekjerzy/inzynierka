#ifndef HTTP_MAINTAINER_H
#define HTTP_MAINTAINER_H

#include <Daemon/Base_Log_Formatter.h>
#include <Base_HTTP_Maintainer_Interface.h>
#include <map>
#include <memory>

class Base_Log_Formatter;

typedef std::shared_ptr<Base_Log_Formatter> Logger_Pointer;
typedef std::map <std::string, std::string> Special_Symbols_Converter;

class HTTP_Maintainer : public Base_HTTP_Maintainer_Interface
{
public:
	HTTP_Maintainer(Logger_Pointer Log_Formatter_ptr_);

	std::string parse_http_protocol_and_create_response
		(const std::string& http);

private:
	Special_Symbols_Converter symbol_converter;

	void prepare_map_containers();
	std::string cut_resource_request(const std::string& http);
	const std::string get_welcome_page();
	const std::string create_header_for_html();

	Logger_Pointer Log_Formatter_ptr;
};

#endif
