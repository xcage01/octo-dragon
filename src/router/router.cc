#include <router.h>

router::router()
{

}

router::~router()
{

}

void router::route(httpRequest* request)
{
        request->reply("Simple router case",200);
}