#ifndef LIB_DEFS
#define LIB_DEFS

#include <microhttpd.h>

typedef void (*loggingHook)(std::string);

struct request {
        struct MHD_Connection* connId;
        const char* url;
        const char* method;
        const char* version;
        loggingHook log;

        const char* resp;
        int respCode = 200;
};


typedef request* (*route)(request*);

#endif