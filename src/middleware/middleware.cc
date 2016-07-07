#include <middleware.h>

void middleware::push(requestHandle handle)
{
        middlewareStack.push_back(handle);
}

void middleware::handle(httpRequest* request)
{
        std::list<requestHandle>::const_iterator iterator;
        for(iterator = middleware::middlewareStack.begin(); iterator != middleware::middlewareStack.end(); ++iterator)
        {
                requestHandle func;
                func = *iterator;
                func(request);
        }
}

std::list<requestHandle> middleware::middlewareStack;