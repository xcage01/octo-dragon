#ifndef MIDDLEWARE_LIB
#define MIDDLEWARE_LIB

#include <list>
#include <server.h>

class middleware
{
        public:
                static void push(requestHandle);
                static void handle(httpRequest*);
        private:
                static std::list<requestHandle> middlewareStack;
};
#endif