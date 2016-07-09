#include <dragon.h>

using namespace dragon;

engine::engine(int argc, const char* argv[])
{
        //parse the positional argument
        if(argc > 1)
        {
                this->baseCommand = argv[1];
        }else
        {
                std::cout << "No operation specified";
        }

        // Probably not needed now
        // this->base = new server(5000);
        // this->base->setHandle(middleware::handle);
        // middleware::push(router::route);
        // bool status = DB::connect("tcp://127.0.0.1:3306","testing",
        //         "root","Rahul@123");
        // if (!status)
        // {
        //         std::cout << "Error connecting to dbs"<<std::endl;
        // }else
        // {
        //         std::cout << "Successfully connected to db"<<std::endl;
        // }
}

void engine::run()
{
        for(const auto& operation : this->plugins)
        {
                if(operation.first == baseCommand)
                {
                        operation.second((void*)this);
                }
        }
}

engine::~engine()
{
}

void engine::registerMod(std::string baseUri,appInit appConf)
{
        appMeta* meta = appConf();
        router::add(baseUri,meta->urlPattern);
}

void engine::registerPlugin(std::string cmd,pluginInit pluginHandle)
{
        plugins[cmd] = pluginHandle;
}

void engine::Handle4XX(requestHandle handeler)
{
        router::Handle4XX = handeler;
}

void engine::Handle5XX(requestHandle handeler)
{
        router::Handle5XX = handeler;
}