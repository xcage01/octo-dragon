#ifndef CONFIG_LIB
#define CONFIG_LIB

#include <libconfig.h>
#include <string>
#include <iostream>

struct configVal
{
  int intVal;
  std::string stringVal;
  bool boolVal;
  bool status = true;
};

class config
{
public:
  config(std::string fileName);
  ~config();
  configVal *getInt(std::string key);
  configVal *getStr(std::string key);
private:
  config_t cfgConf;
};
#endif
