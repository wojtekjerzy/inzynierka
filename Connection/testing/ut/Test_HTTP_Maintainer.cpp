#include "Test_HTTP_Maintainer.h"
#include "HTTP_Strings.h"
#include "Const_Strings.h"

TEST_F(Test_HTTP_Maintainer, http_with_empty_protocol__welcome_page_reutrned)
{
	std::string response = uut.parse_http_protocol_and_create_response(HTTP_Strings::http_get_empty_protocol);
	EXPECT_EQ(Const_Strings::header_for_html + Const_Strings::welcome_page, response);
}

TEST_F(Test_HTTP_Maintainer, http_with_no_url_received__welcome_page_reutrned)
{
	std::string response = uut.parse_http_protocol_and_create_response(HTTP_Strings::http_get_empty);
	EXPECT_EQ(Const_Strings::header_for_html + Const_Strings::welcome_page, response);
}

