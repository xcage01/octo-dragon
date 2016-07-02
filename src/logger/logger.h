#ifndef LIB_LOGGER
#define LIB_LOGGER

#include <string>
#include <easylogging++.h>

INITIALIZE_EASYLOGGINGPP

void logging(std::string message) {
   LOG(INFO) << message;
}

#endif