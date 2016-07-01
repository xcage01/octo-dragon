#ifndef LIB_URLS
#define LIB_URLS

#include "defs.h"

class url
{
	public:
		url();
		~url();
	private:
		const char * regexUrl;

};

class urlDispatch
{
	public:
		urlDispatch();
		~urlDispatch();
};

#endif