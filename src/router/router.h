#ifndef ROUTER_CLASS
#define ROUTER_CLASS

#include <server.h>

class router
{
        public:
                router();
                ~router();
                static void route(httpRequest*);
        private:
};
#endif