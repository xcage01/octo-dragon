#include <logger.h>
#include <dragon.h>

using namespace dragon;

int main()
{
        engine * d = new engine();
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


