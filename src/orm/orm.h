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
                virtual std::string __type__() = 0;
                int __size__ = -1;
};


class charField : public modelField
{
        public:
                charField(int value) : modelField(value) {};
                charField() : modelField() {};
                std::string __type__();
        private:
                int size;
};

class integerField : public modelField
{
        public:
                integerField(int value) : modelField(value) {};
                integerField() : modelField() {};
                std::string __type__();
        private:
                int size;
};


class bigIntegerField : public modelField
{
        public:
                bigIntegerField(int value) : modelField(value) {};
                bigIntegerField() : modelField() {};
                std::string __type__();
        private:
                int size;
};

class tinyInt : public modelField
{
        public:
                tinyInt(int value) : modelField(value) {};
                tinyInt() : modelField() {};
                std::string __type__();
        private:
                int size;
};

class textField : public modelField
{
        public:
                textField(int value) : modelField(value) {};
                textField() : modelField() {};
                std::string __type__();
        private:
                int size;
};

class longTextField : public modelField
{
        public:
                longTextField(int value) : modelField(value) {};
                longTextField() : modelField() {};
                std::string __type__();
        private:
                int size;
};

class booleanField : public tinyInt
{
        public:
                booleanField(int value) : tinyInt(value) {};
                booleanField() : tinyInt() {};
        private:
                int size;
};




class pk : public bigIntegerField
{
        public:
                pk(int value) : bigIntegerField(value) {};
                pk() : bigIntegerField() {};
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