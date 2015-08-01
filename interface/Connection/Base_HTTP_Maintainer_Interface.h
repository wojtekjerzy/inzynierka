#ifndef BASE_HTTP_PARSER_INTERFACE_H
#define BASE_HTTP_PARSER_INTERFACE_H

#include <memory>

class Base_HTTP_Maintainer_Interface
{
public:
	virtual ~Base_HTTP_Maintainer_Interface() = default;

	virtual std::string parse_http_protocol_and_create_response(const std::string &http) = 0;
};

#endif
