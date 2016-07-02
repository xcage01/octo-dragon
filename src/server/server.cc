#include "server.h"

HttpServer::HttpServer(loggingHook logger)
{
        HttpServer::log = logger;
        this->mhdDaemon = MHD_start_daemon (MHD_USE_SELECT_INTERNALLY, 
                8888, NULL, NULL,
                &this->clbHandle, NULL, MHD_OPTION_END);
        HttpServer:log("Http server started");
}

HttpServer::~HttpServer()
{
        MHD_stop_daemon(this->mhdDaemon);
        HttpServer::log("Http server terminated");
}

void HttpServer::serve()
{
        getchar();
        delete this;
}


void HttpServer::registerApp(const char * appBaseUrl,applicationInit hook)
{
        appMeta* appData = hook();
        std::string modLoadMsg = "Loading module ";
        modLoadMsg.append(appData->appName);
        HttpServer::log(modLoadMsg);
        HttpServer::urls = appData->urls;
        appConf* conf = new appConf;
        conf->meta = appData;
        conf->baseUrl = appBaseUrl;
        activeApps.push_back(conf);
}


int HttpServer::clbHandle (void* cls, struct MHD_Connection* con,
        const char* url, const char* method,
        const char* version, const char* upload_data,
        size_t* upload_data_size, void** con_cls)
{
        request* curRequest = new request;
        curRequest->connId = con;
        curRequest->url = url;
        curRequest->method = method;
        curRequest->version = version;
        curRequest->log = HttpServer::log;

        bool endpointFound = false;
        for (auto &app : HttpServer::activeApps) {
                const char* base = app->baseUrl;
                for (auto& it: app->meta->urls) {
                        char* regexEndpoint = (char*)malloc(strlen(base)+strlen(it->regexUrl)+1);
                        strcpy(regexEndpoint, base);
                        strcat(regexEndpoint, it->regexUrl);
                        if (std::regex_match(url, std::regex(regexEndpoint))) {
                               endpointFound = true;
                               curRequest = it->endpointHandle(curRequest);
                        }
                        free(regexEndpoint);
                }
        }

        if (!endpointFound) {
                curRequest->respCode = 404;
                curRequest = HttpServer::notFound(curRequest);
        }


        const char* page = curRequest->resp;
        struct MHD_Response* response;
        int ret;
        response =
        MHD_create_response_from_buffer(strlen(page), (void*) page, 
                MHD_RESPMEM_PERSISTENT);
        MHD_add_response_header(response, "Server", "Octo-dragon");
        ret = MHD_queue_response(con, curRequest -> respCode, response);
        MHD_destroy_response(response);
        return ret;
}

route HttpServer::notFound;
std::list<url*> HttpServer::urls;
std::list<appConf*> HttpServer::activeApps;
loggingHook HttpServer::log;