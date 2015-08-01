#ifndef CONST_STRINGS_H
#define CONST_STRINGS_H

#include <string>

namespace Const_Strings
{
const std::string welcome_page = "<html><body>Strona powitalna. </br> Projekt realizowany w ramach pracy inzynierskiej.</br>Wojciech Wojciechowski</body></html>";
const std::string header_for_html = "HTTP/1.0 200 OK\r\n\r\n";
const std::string request_type = "GET /";
const std::string protocol_type = " HTTP/1.1";
const std::string start_log = "Initialize process: ";
const std::string end_log = "Terminated process: ";
const std::string ready_to_serve_clients = "Ready to serve clients at port: ";
const std::string receiving_request = "Receiving request from client";
const std::string client_ip = "client IP: ";

const std::string space = " ";
const std::string dot = ".";
const std::string colon = ":";
const std::string home_directory = "/";
const std::string double_endline = "\n\n";
}

#endif
