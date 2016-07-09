#include <dragon.h>

using namespace dragon;

engine::engine()
{
        this->baseConfig = new config("app.cfg");
        configVal * port = this->baseConfig->getInt("port");
        if(port->status)
        {
                this->base = new server(port->intVal);
                this->base->setHandle(middleware::handle);
                middleware::push(router::route);
        }else
        {
                std::cout << "No port found in configuration"<<std::endl;
        }
        // this->databaseDriver = new databaseDriver();
        bool status = DB::connect("tcp://127.0.0.1:3306","testing",
                "root","Rahul@123");
        if (!status)
        {
                std::cout << "Error connecting to dbs"<<std::endl;
        }else
        {
                std::cout << "Successfully connected to db"<<std::endl;
        }
}

void engine::run()
{
        getchar();
        delete this->base;
}

engine::~engine()
{
        delete this->baseConfig;
}

void engine::registerMod(std::string baseUri,appInit appConf)
{
        appMeta* meta = appConf();
        router::add(baseUri,meta->urlPattern);
}

void engine::Handle4XX(requestHandle handeler)
{
        router::Handle4XX = handeler;
}

void engine::Handle5XX(requestHandle handeler)
{
        router::Handle5XX = handeler;
}