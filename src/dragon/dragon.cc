#include <dragon.h>

using namespace dragon;

engine::engine()
{
        this->base = new server(9090);
        this->base->setHandle(router::route);
}

void engine::run()
{
        getchar();
        delete this->base;
}

engine::~engine()
{
        
}

void engine::registerMod(std::string baseUri,appInit appConf)
{
        appMeta* meta = appConf();
        router::add(baseUri,meta->urlPattern);
}

void engine::Handle4XX(requestHandle handeler)
{
        router::Handle4XX = handeler;
}

void engine::Handle5XX(requestHandle handeler)
{
        router::Handle5XX = handeler;
}