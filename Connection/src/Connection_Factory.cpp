#include "Connection_Factory.h"
#include "Connection.h"

#include <boost/make_shared.hpp>

boost::shared_ptr <Base_Connection_Interface> Connection_Factory::create_connection(std::shared_ptr <Base_Log_Formatter> logger_pointer_,
		std::shared_ptr <Base_Asio_For_Server_Interface> asio_for_serv_,
		std::shared_ptr <Base_HTTP_Maintainer_Interface> http_maintainer_)
{
	return boost::make_shared <Connection>
		(logger_pointer_, asio_for_serv_, http_maintainer_);
}
