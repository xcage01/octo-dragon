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
                        User(const std::string,const std::string);
                
        };

        User::User(const std::string username,const std::string email)
        {
                m_fields["username"] = new stringField(username);
                m_fields["email"] = new stringField(email);
        }

        appMeta * init()
        {
                User * sudo = new User("xander","xander01@hotmail.com");
                sudo->save();
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
        engine * d = new engine();
        d->registerMod("/b",mod1::init);
        d->Handle4XX(mod1::notFound);
        d->run();
        return 0;
}