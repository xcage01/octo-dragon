#include <dragon.h>

using namespace dragon;

namespace mod1
{
        std::string appName = "Module 1";

        void hello(httpRequest * request)
        {
                std::cout<<request->POST.get("username")<<std::endl;
                request->reply("Simple hello in mod1",200);
        }

        void notFound(httpRequest * request)
        {
                request->reply("Woops page not found",404);
        }

        class User : public models
        {
                public:
                        User()
                        {
                                __meta__.name = "User";
                                m_fields["username"] = new charField();
                                m_fields["email"] = new charField(12);
                                notNull = {"username","email"};
                                unique = {"username"};
                        };
                
        };

        appMeta * init()
        {
                // std::map<std::string,std::string> userData;
                // userData["username"] = "xander";
                // userData["email"] = "xander01@hotmail.com";
                // User* user = new User();
                // user->data(userData);
                // if (user->is_valid())
                //         user->save();
                // user->migrate();
                appMeta* meta = new appMeta;
                meta->name = appName;
                url pattern;
                pattern.insert(std::pair<std::string,requestHandle>("/h",hello));
                meta->urlPattern = pattern;
                return meta;
        }
}


void runServer(void* dragon)
{
        engine * core = (engine*)dragon;
        std::cout << "Initializing http server on 5000 ..."<<std::endl;
        server * httpServer = new server(5000);
        httpServer->setHandle(middleware::handle);
        middleware::push(router::route);
        std::cout << "Connecting to database server ..."<<std::endl;
        bool status = DB::connect("tcp://127.0.0.1:3306","testing",
                "root","Rahul@123");
        if (!status)
        {
                std::cout << "Unable to connect to database server";
                delete httpServer;
                return;
        }
        std::cout << "Starting daemon process ..."<<std::endl;
        getchar();
}

void migrate(void* dragon)
{
        std::cout << "Running migrations"<<std::endl;
}

void makeMigrations(void* dragon)
{
        std::cout << "making migrations"<<std::endl;
}

int main(int argc, const char* argv[])
{
        engine * d = new engine(argc,argv);
        d->registerMod("/b",mod1::init);
        d->registerPlugin("server",runServer);
        d->registerPlugin("migrate",migrate);
        d->registerPlugin("mm",makeMigrations);
        d->Handle4XX(mod1::notFound);
        d->run();
        return 0;
}