#include <config.h>

config::config(std::string fileName)
{
        config_init(&this->cfgConf);
        if (!config_read_file(&this->cfgConf, fileName.c_str()))
        {
                config_destroy(&this->cfgConf);
                std::cout<< "Error while reading configuration"<<std::endl;
        }
}

configVal* config::getInt(std::string key)
{
        configVal* cfg = new configVal;
        if (!config_lookup_int(&this->cfgConf,key.c_str(), &cfg->intVal))
        {
                cfg->status=false;
        }
        return cfg;
}

configVal* config::getStr(std::string key)
{
        configVal* cfg = new configVal;
        const char * str;
        if (!config_lookup_string(&this->cfgConf,key.c_str(), &str))
        {
                cfg->status=false;
        }else
        {
                cfg->stringVal=str;
        }
        return cfg;
}