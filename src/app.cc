#include <dragon.h>

using namespace dragon;

namespace mod1
{
        std::string appName = "Module 1";

        void hello(httpRequest * request)
        {
                request->reply("Simple hello in mod1",200);
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
        // HttpServer * baseServer = new HttpServer(logging);
        // baseServer -> registerApp("/testApp",testApp::init);
        // baseServer -> notFound = testApp::notFound;
        // baseServer -> serve();
        return 0;
}

// namespace testApp
// {
//         const char * appName = "testApp";  
//         urlDispatch * urls = new urlDispatch;

//         std::list<url *> urlPattern;

//         request * hello(request * req)
//         {
//                 req->log("[/] New request");
//                 req->resp = "Testing hello";
//                 return req;
//         }

//         request * hello2(request * req)
//         {
//                 req->log("[/h] New request");
//                 req->resp = "Testing hello2";
//                 return req;
//         }
  
//         request * notFound(request * req)
//         {
//                 req->resp = "Page not found";
//                 return req;
//         }

//         appMeta * init()
//         {
//                 urlPattern.push_back(new url("/",hello));
//                 urlPattern.push_back(new url("/h",hello2));
//                 appMeta * application = new appMeta;
//                 application -> appName = appName;
//                 application -> urls = urlPattern;
//                 return application;
//         }


// }


