#ifndef LIB_SERVER
#define LIB_SERVER

#include <microhttpd.h>
#include <cstring>
#include <stdio.h>
#include "logs.cc"
#include "urls.cc"
#include "defs.h"

class HttpServer
{
	public:
		HttpServer();
		void serve();
		~HttpServer();
		void registerApp(applicationHook);
		static logger * baseLogger;
		static route defz;
	private:
		struct MHD_Daemon * mhdDaemon;
		static int clbHandle (void *cls, struct MHD_Connection *con,
			const char *url, const char *method,
			const char *version, const char *upload_data,
			size_t *upload_data_size, void **con_cls);
};

#endif