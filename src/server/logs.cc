#include "logs.h"
#include <iostream>
#include <ctime>

logger::logger()
{

}

void logger::commit(const char * log)
{
        time_t now = time(0);
        tm* ltm = localtime(&now);
        std::cout << "[" << ltm->tm_hour << ":" 
                << ltm->tm_min  << ":" << ltm->tm_sec << "] "
                << log << std::endl;
}