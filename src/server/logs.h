#ifndef LIB_LOGS
#define LIB_LOGS

class logger
{
        public:
                logger();
                void commit(const char*);
                ~logger();
};
#endif