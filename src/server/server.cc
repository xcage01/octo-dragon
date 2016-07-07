#include <server.h>

server::server(int port)
{
        this->port = port;
        this->daemon = MHD_start_daemon (MHD_USE_SELECT_INTERNALLY, 
                this->port, NULL, NULL,
                &this->clbHandle, NULL, MHD_OPTION_END);
}

server::~server()
{
        MHD_stop_daemon(this->daemon);
}

void server::setHandle(requestHandle handle)
{
        server::handle = handle;
}

int server::getPort()
{
        return this->port;
}

int server::clbHandle (void* cls, struct MHD_Connection* con,
        const char* url, const char* method,
        const char* version, const char* upload_data,
        size_t* upload_data_size, void** con_cls)
{
        httpRequest* request;
        request = (httpRequest*)*con_cls;
        if(NULL == request){
                request = new httpRequest;
                request->url = url;
                request->method = method;
                request->version = version;
                *con_cls = request;
                if (0 == strcmp (method, MHD_HTTP_METHOD_POST))
                {
                        request->postProcessor = MHD_create_post_processor (con
                                , 1024,&server::post_iterator, request);
                        if(NULL == request)
                        {
                                return MHD_NO;
                        }
                }

                return MHD_YES;
        }

        if (0 == strcmp (method, MHD_HTTP_METHOD_POST))
        {
                MHD_post_process (request->postProcessor,
                        upload_data,
                        *upload_data_size);
                if (0 != *upload_data_size)
                {
                        *upload_data_size = 0;
                        return MHD_YES;
                }
                MHD_destroy_post_processor (request->postProcessor);
                request->postProcessor = NULL;
        }

        server::handle(request);

        const char *page = request->response.resp;

        struct MHD_Response* response;
        int ret;
        response =
        MHD_create_response_from_buffer(strlen(page), (void*) page,  
                MHD_RESPMEM_PERSISTENT);
        MHD_add_response_header(response, "Server", "dragon");
        ret = MHD_queue_response(con, request->response.respCode, response);
        MHD_destroy_response(response);
        return ret;
}

int server::post_iterator (void *cls,
        enum MHD_ValueKind kind,
        const char *key,
        const char *filename,
        const char *content_type,
        const char *transfer_encoding,
        const char *data, uint64_t off, size_t size)
{
        httpRequest* request = (httpRequest*)cls;
        request->POST.content.insert(std::pair<std::string,std::string>(key,data));
        return MHD_YES;
}


requestHandle server::handle;
