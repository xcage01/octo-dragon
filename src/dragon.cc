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

  request * hello2(request * req)
  {
    HttpResponse("testing another url")
  }
  
  request * notFound(request * req)
  {
    HttpResponse(req->url)
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


namespace testApp2
{
  const char * appName = "testApp2";  
  urlDispatch * urls = new urlDispatch;

  std::list<url *> urlPattern;

  request * hello(request * req)
  {
    HttpResponse("Testing if macros are good")
  }

  request * hello2(request * req)
  {
    HttpResponse("testing another url")
  }
  
  request * notFound(request * req)
  {
    HttpResponse(req->url)
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
  baseServer -> registerApp("/testApp2",testApp2::init);
  baseServer -> notFound = testApp::notFound;
  baseServer -> serve();
}