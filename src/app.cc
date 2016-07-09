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
                std::map<std::string,std::string> userData;
                userData["username"] = "xander";
                userData["email"] = "xander01@hotmail.com";
                User* user = new User();
                user->data(userData);
                if (user->is_valid())
                        user->save();
                user->migrate();
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