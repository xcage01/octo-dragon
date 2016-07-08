#ifndef ORM_CLASS
#define ORM_CLASS

#include <map>
#include <string>
#include <iostream>
#include <mysql.h>

struct modelMeta{
        std::string name;
};

class modelField
{
        public:
                virtual ~modelField() {};
                virtual void save() = 0;
                virtual std::string __type__() = 0;
};


class stringField : public modelField
{
        public:
                stringField(const std::string& value) : m_value(value) {};
                stringField(){};
                virtual void save();
                virtual std::string __type__();
        private:
                std::string m_value;
};

class intField : public modelField
{
        public:
                intField(int value) : m_value(value) {};
                intField(){};
                virtual void save();
                virtual std::string __type__();
        private:
                int m_value;
};

class pk : public modelField
{
        public:
                pk(){};
                virtual void save();
                virtual std::string __type__();
};

class models
{
        public:
                models();
                virtual ~models();
                virtual void migrate();
                virtual void save();
                static sqlDriver* driver;
        protected:
                std::map<std::string, modelField*> m_fields;
                std::string primary = "pk";
                std::list<std::string> notNull;
                std::list<std::string> unique;
                std::map<std::string,std::list<std::string>> m_params;
                modelMeta __meta__;
};

#endif