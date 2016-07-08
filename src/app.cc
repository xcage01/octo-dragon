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
                        User(const std::string username,const std::string email)
                        {
                                __meta__.name = "User";
                                m_fields["username"] = new stringField();
                                m_fields["email"] = new stringField(12);
                                notNull = {"username","email"};
                                unique = {"username"};
                        }
                
        };

        appMeta * init()
        {
                bool status = DB::connect("tcp://127.0.0.1:3306","testing",
                        "root","Rahul@123");
                if (!status)
                {
                        std::cout << "Error connecting to dbs"<<std::endl;
                }else
                {
                        std::cout << "Successfully connected to db"<<std::endl;
                }
                User* sudo = new User("xander","xander01@hotmail.com");
                sudo->migrate();
                appMeta* meta = new appMeta;
                meta->name = appName;
                url pattern;
                pattern.insert(std::pair<std::string,requestHandle>("/h",hello));
                meta->urlPattern = pattern;
                return meta;
        }
}
int main()
{
        std::list<std::string> a;
        a = {"a","a"};
        engine * d = new engine();
        d->registerMod("/b",mod1::init);
        d->Handle4XX(mod1::notFound);
        d->run();
        return 0;
}