#include "urls.h"

urlDispatch::urlDispatch()
{

}

urlDispatch::~urlDispatch()
{

}

url::url(const char* regexUrl,route endpointHandle)
{
        this->regexUrl = regexUrl;
        this->endpointHandle = endpointHandle;
}

url::~url()
{

}