#include "server/server.cc"


namespace testApp
{
  const char * appName = "testApp";  
  urlDispatch * urls = new urlDispatch;

  std::list<url *> urlPattern;

  request * hello(request * req)
  {
    HttpResponse("Testing if macros are good")
  }
  
  request * dummy(request * req)
  {
    HttpResponse("dummy no regex")
  }

  appMeta * init()
  {
    urlPattern.push_back(new url("/",hello));
    appMeta * application = new appMeta;
    application -> appName = appName;
    application -> urls = urlPattern;
    return application;
  }


}





int main()
{
  HttpServer * baseServer = new HttpServer();
  baseServer -> registerApp(testApp::init);
  baseServer -> defz = testApp::dummy;
  baseServer -> serve();
}