#include <middleware.h>

void middleware::push(middlewareHandle handle)
{
        middlewareStack.push_back(handle);
}

middlewareHandle get(int index)
{
        return middleware::middlewareStack.at(index);
}

void middleware::handle(httpRequest* request)
{
        middlewareHandle func;
        func = middleware::middlewareStack.at(0);
        func(request,middleware::middlewareStack.size()-1);
}

std::vector<middlewareHandle> middleware::middlewareStack;