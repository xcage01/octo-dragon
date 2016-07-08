#ifndef ORM_CLASS
#define ORM_CLASS

#include <map>
#include <string>
#include <iostream>

class modelField
{
        public:
                virtual ~modelField() {};
                virtual void save() = 0;
                virtual void migrate() = 0;
};

class models
{
        public:
                virtual ~models();
                virtual void migrate();
                virtual void save();
        protected:
                std::map<std::string, modelField*> m_fields;
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

#endif