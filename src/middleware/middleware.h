#ifndef MIDDLEWARE_LIB
#define MIDDLEWARE_LIB

#include <vector>
#include <server.h>

typedef void (*middlewareHandle)(httpRequest*,int);

class middleware
{
        public:
                static void push(middlewareHandle);
                static middlewareHandle get(int);
                static void handle(httpRequest*);
                static std::vector<middlewareHandle> middlewareStack;
};
#endif