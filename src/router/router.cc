#include <router.h>

router::router()
{
        std::cout << "Init router";
}

router::~router()
{

}

void router::add(std::string baseUri,url urlList)
{
        router::baseController.insert(std::pair<std::string,url>(baseUri,urlList));
}

void router::route(httpRequest* request)
{
        bool found = false;
        for (const auto& appUrlConf:router::baseController )
        {
                std::string appBaseUri = appUrlConf.first;
                for (const auto& appUri:appUrlConf.second)
                {
                        std::string regexUri;
                        regexUri.append(appUrlConf.first).append(appUri.first);
                        if(std::regex_match(request->url,std::regex(regexUri)))
                        {
                                appUri.second(request);
                                found = true;
                        }
                }
        }
        if(!found)
                request->reply("Page not found",404);
}

// Defination of all static members of class
urlController router::baseController;