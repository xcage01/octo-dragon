#ifndef SERVER_CLASS
#define SERVER_CLASS

#include <microhttpd.h>
#include <string>
#include <cstring>
#include <iostream>
#include <map>

typedef std::map<std::string,std::string> data;

struct httpResponse{
        const char * resp = "";
        int respCode = 200;
};

struct params{
        data content;
        std::string get(std::string key)
        {
                std::map<std::string,std::string>::iterator it;
                it=content.find(key);
                if (it != content.end())
                        return it->second;
                return "";
        }
};

struct httpRequest{
        httpResponse response;
        std::string url;
        std::string method;
        std::string version;
        params GET;
        params POST;
        params HEADER;
        void reply(const char * resp,int code)
        {
                response.resp = resp;
                response.respCode = code;
        }

        struct MHD_PostProcessor* postProcessor;
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
                static int post_iterator (void *cls,
                       enum MHD_ValueKind kind,
                       const char *key,
                       const char *filename,
                       const char *content_type,
                       const char *transfer_encoding,
                       const char *data, uint64_t off, size_t size);
                static int get_iterator (void *cls, enum MHD_ValueKind kind,
                        const char *key,const char *value);
                static int header_iterator (void *cls, enum MHD_ValueKind kind,
                        const char *key,const char *value);
};

#endif