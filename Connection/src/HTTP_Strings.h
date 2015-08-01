#ifndef HTTP_STRINGS_H
#define HTTP_STRINGS_H

#include <string>

namespace HTTP_Strings
{
	const std::string home_path = "./";
	const std::string http_get_empty = "GET / HTTP/1.1 Via: 1.1 FIESPRX006 User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:33.0) Gecko/20100101 Firefox/33.0 Host: 10.154.34.241:8080 Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8 Accept-Language: en-US,en;q=0";
	const std::string http_get_empty_protocol = "";
	const std::string url_no_1 = "test_path.txt";
	const std::string url_no_2 = "image_path.png";
	const std::string http_get_with_url_no_1 = "GET /test_path.txt HTTP/1.1 Via: 1.1 FIESPRX006 User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:33.0) Gecko/20100101 Firefox/33.0 Host: 10.154.34.241:8080 Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8 Accept-Language: en-US,en;q=0.";
	const std::string http_get_with_url_no_2 = "GET /image_path.png HTTP/1.1 Via: 1.1 FIESPRX006 User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:33.0) Gecko/20100101 Firefox/33.0 Host: 10.154.34.241:8080 Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8 Accept-Language: en-US,en;q=0.";
	const std::string http_with_specials_symbols = "GET /image%20path.png HTTP/1.1 Via: 1.1 FIESPRX006 User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:33.0) Gecko/20100101 Firefox/33.0 Host: 10.154.34.241:8080 Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8 Accept-Language: en-US,en;q=0.";
}
#endif
