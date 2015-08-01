#include "HTTP_Maintainer.h"
#include "Const_Strings.h"

using UTF8_And_Unicode = std::pair <std::string, std::string>;

HTTP_Maintainer::HTTP_Maintainer(Logger_Pointer Log_Formatter_ptr_)
	:
	Log_Formatter_ptr(Log_Formatter_ptr_)
{
	prepare_map_containers();
}

void HTTP_Maintainer::prepare_map_containers()
{
	symbol_converter.insert(UTF8_And_Unicode("%20", " "));
	symbol_converter.insert(UTF8_And_Unicode("%27", "'"));
	symbol_converter.insert(UTF8_And_Unicode("%5B", "["));
	symbol_converter.insert(UTF8_And_Unicode("%5D", "]"));
}

std::string HTTP_Maintainer::parse_http_protocol_and_create_response
	(const std::string& http)
{
	return get_welcome_page();
}

const std::string HTTP_Maintainer::get_welcome_page()
{
	return (create_header_for_html() + Const_Strings::welcome_page);
}

const std::string HTTP_Maintainer::create_header_for_html()
{
	return Const_Strings::header_for_html;
}
