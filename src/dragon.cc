#include "server/server.cc"


namespace testApp
{
        const char * appName = "testApp";  
        urlDispatch * urls = new urlDispatch;

        std::list<url *> urlPattern;

        request * hello(request * req)
        {
                req->resp = "Testing hello";
                return req;
        }

        request * hello2(request * req)
        {
                req->resp = "Testing hello2";
                return req;
        }
  
        request * notFound(request * req)
        {
                req->resp = "Page not found";
                return req;
        }

        appMeta * init()
        {
                urlPattern.push_back(new url("/",hello));
                urlPattern.push_back(new url("/h",hello2));
                appMeta * application = new appMeta;
                application -> appName = appName;
                application -> urls = urlPattern;
                return application;
        }


}


int main()
{
        HttpServer * baseServer = new HttpServer();
        baseServer -> registerApp("/testApp",testApp::init);
        baseServer -> notFound = testApp::notFound;
        baseServer -> serve();
}