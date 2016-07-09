#ifndef DRAGONX_LIB
#define DRAGONX_LIB

#include <config.h>
#include <server.h>
#include <router.h>
#include <middleware.h>
#include <orm.h>
#include <getopt.h>

struct appMeta{
        std::string name;
        url urlPattern;
};

typedef appMeta*(*appInit)();

typedef void (*pluginInit)(void*);

/*! octo-dragon api namespace */
namespace dragon{
        class engine
        {
                public:
                        //! core engine constructor.
                        /*!
                        initializes the octo dragon http server
                        */
                        engine(int,const char **);
                        //! core engine destructor.
                        /*!
                        closes and cleans up the http server
                        */
                        ~engine();
                        //! Run the engine
                        /*!

                        Start running the http server as a daemon
                        */
                        void run();
                        //! Register new mod
                        /*!
                        \param baseUri std::string that contains base uri that
                        is used to access the app from browser
                        \param appConf function pointer that returns the config
                        for the entire app

                        Used to register new modules into the engine
                        */
                        void registerMod(std::string baseUri,appInit appConf);
                        void registerPlugin(std::string,pluginInit);
                        void Handle4XX(requestHandle handeler);
                        void Handle5XX(requestHandle handeler);
                private:
                        //! base server
                        /*!
                        The actual instance of the http server
                        */
                        server* base;
                        std::string baseCommand;
                        std::map<std::string,pluginInit> plugins;
                        std::string migrationsFolder = "./migrations/";
                        std::map<std::string,appInit> modsList;
        };
};

#endif