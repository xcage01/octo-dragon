#include <orm.h>

void models::migrate()
{
        for(auto& f : m_fields)
                f.second->migrate();
}

void models::save()
{
        for(auto& f : m_fields)
                f.second->save();
}

models::~models()
{

}

void stringField::save()
{
        std::cout << "Save value " << m_value << std::endl;
}

void stringField::migrate()
{
        std::cout << "migrate value " << m_value << std::endl;
}