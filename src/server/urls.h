#ifndef LIB_URLS
#define LIB_URLS

class url {
        public:
                url(const char*, route);
                ~url();
                const char* regexUrl;
                route endpointHandle;
        private:

};

class urlDispatch {
        public:
                urlDispatch();
                ~urlDispatch();
};

#endif