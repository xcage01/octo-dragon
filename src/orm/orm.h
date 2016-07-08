#ifndef ORM_CLASS
#define ORM_CLASS

#include <map>
#include <string>
#include <iostream>

struct modelMeta{
        std::string name;
};

class modelField
{
        public:
                virtual ~modelField() {};
                virtual void save() = 0;
                virtual void migrate() = 0;
};


class stringField : public modelField
{
        public:
                stringField(const std::string& value) : m_value(value) {};
                
                virtual void save();
                virtual void migrate();
        private:
                std::string m_value;
};

class intField : public modelField
{
        public:
                intField(int value) : m_value(value) {};
                
                virtual void save();
                virtual void migrate();
        private:
                int m_value;
};

class models
{
        public:
                models();
                virtual ~models();
                virtual void migrate();
                virtual void save();
        protected:
                std::map<std::string, modelField*> m_fields;
                modelMeta __meta__;
};

#endif