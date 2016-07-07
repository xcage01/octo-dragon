#include <dragon.h>

using namespace dragon;

namespace mod1
{
        std::string appName = "Module 1";

        void hello(httpRequest * request)
        {
                std::cout<<request->HEADER.get("username")<<std::endl;
                request->reply("Simple hello in mod1",200);
        }

        void notFound(httpRequest * request)
        {
                request->reply("Woops page not found",404);
        }

        appMeta * init()
        {
                appMeta* meta = new appMeta;
                meta->name = appName;
                url pattern;
                pattern.insert(std::pair<std::string,requestHandle>("/h",hello));
                meta->urlPattern = pattern;
                return meta;
        }
}
int main()
{
        engine * d = new engine();
        d->registerMod("/b",mod1::init);
        d->Handle4XX(mod1::notFound);
        d->run();
        return 0;
}