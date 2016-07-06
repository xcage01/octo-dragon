#ifndef SERVER_CLASS
#define SERVER_CLASS

#include <microhttpd.h>
#include <string>
#include <cstring>

struct httpResponse{
        const char * resp = "Simply hello world";
        int respCode = 200;
};

struct httpRequest{
        httpResponse response;
        std::string url;
        std::string method;
        std::string version;
        void reply(const char * resp,int code)
        {
                response.resp = resp;
                response.respCode = code;
        }
};

typedef void (*requestHandle)(httpRequest*);

class server{
        public:
                server(int);
                ~server();
                static void setHandle(requestHandle);
                int getPort();
        private:
                int port;
                struct MHD_Daemon* daemon;
                static requestHandle handle;
                static int clbHandle(void* cls, struct MHD_Connection* con,
                        const char* url, const char* method,
                        const char* version, const char* upload_data,
                        size_t* upload_data_size, void** con_cls);
};

#endif