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
        httpRequest* request = new httpRequest;
        request->url = url;
        request->method = method;
        request->version = version;

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


requestHandle server::handle;
