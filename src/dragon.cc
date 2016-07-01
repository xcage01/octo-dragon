#include "server/server.cc"

int main()
{
  HttpServer * baseServer = new HttpServer();
  baseServer -> serve();
}