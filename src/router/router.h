#ifndef ROUTER_CLASS
#define ROUTER_CLASS

#include <server.h>
#include <regex>
#include <map>
#include <list>
#include <iostream>
#include <middleware.h>

typedef std::map<std::string,requestHandle> url;
typedef std::map<std::string,url> urlController;

class router
{
        public:
                router();
                ~router();
                static void add(std::string,url);
                static void route(httpRequest*,int);
                static requestHandle Handle4XX;
                static requestHandle Handle5XX;
        private:
                static urlController baseController;
};
#endif
