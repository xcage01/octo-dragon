#include "server/server.cc"


namespace testApp
{
  const char * appName = "testApp";  
  urlDispatch * urls = new urlDispatch;

  void init()
  {

  }

  request * hello(request * req)
  {
    HttpResponse("Testing if macros are good")
  }

}





int main()
{
  HttpServer * baseServer = new HttpServer();
  baseServer -> registerApp(testApp::init);
  baseServer -> serve();
}