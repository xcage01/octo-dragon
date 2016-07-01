#ifndef LIB_SERVER
#define LIB_SERVER

#include <microhttpd.h>
#include <cstring>
#include <stdio.h>
#include <list>
#include <regex>
#include "logs.cc"
#include "defs.h"
#include "urls.cc"

struct appMeta
{
	const char * appName;
	std::list<url *> urls;
};


typedef appMeta * (*applicationInit)(void);

class HttpServer
{
	public:
		HttpServer();
		void serve();
		~HttpServer();
		void registerApp(applicationInit);
		static logger * baseLogger;
		static route notFound;
		static std::list<url *> urls;
	private:
		struct MHD_Daemon * mhdDaemon;
		static int clbHandle (void *cls, struct MHD_Connection *con,
			const char *url, const char *method,
			const char *version, const char *upload_data,
			size_t *upload_data_size, void **con_cls);
};

#endif