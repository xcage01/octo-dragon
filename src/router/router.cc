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
        std::cout << "Size of urlPattern init "<< router::baseController.size()<<std::endl;
}

void router::route(httpRequest* request)
{
        std::cout << "Size of urlPattern end "<< router::baseController.size()<<std::endl;
        request->reply("Simple router case",200);
}

// Defination of all static members of class
urlController router::baseController;