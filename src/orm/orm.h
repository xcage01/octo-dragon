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
                modelField(int size) {__size__=size;};
                modelField() {};
                virtual ~modelField() {};
                virtual void save() = 0;
                virtual std::string __type__() = 0;
                int __size__ = -1;
};


class stringField : public modelField
{
        public:
                stringField(int value) : modelField(value) {};
                stringField() : modelField() {};
                virtual void save();
                std::string __type__();
        private:
                int size;
                std::string m_value;
};

class intField : public modelField
{
        public:
                intField(int value) : modelField(value) {};
                intField() : modelField() {};
                virtual void save();
                std::string __type__();
        private:
                int size;
                int m_value;
};

class pk : public intField
{
        public:
                pk(int value) : intField(value) {};
                pk() : intField() {};
                virtual void save();
        private:
                int size;
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