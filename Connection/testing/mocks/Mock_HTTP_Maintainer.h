#ifndef MOCK_HTTP_MAINTAINER_H
#define MOCK_HTTP_MAINTAINER_H

#include "Base_HTTP_Maintainer_Interface.h"

#include <gmock/gmock.h>

class Mock_HTTP_Maintainer : public Base_HTTP_Maintainer_Interface
{
public:
	~Mock_HTTP_Maintainer() throw() {}
	MOCK_METHOD1(parse_http_protocol_and_create_response, std::string(const std::string&));
};

#endif
