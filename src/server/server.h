#ifndef LIB_SERVER
#define LIB_SERVER

#include <microhttpd.h>
#include <cstring>
#include <stdio.h>
#include "logs.cc"

class HttpServer
{
	public:
		HttpServer();
		void serve();
		~HttpServer();
		static logger * baseLogger;
	private:
		struct MHD_Daemon * mhdDaemon;
		static int clbHandle (void *cls, struct MHD_Connection *con,
			const char *url, const char *method,
			const char *version, const char *upload_data,
			size_t *upload_data_size, void **con_cls);
};

#endif