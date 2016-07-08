#include <orm.h>

void models::migrate()
{
        for(auto& f : m_fields)
                f.second->migrate();
}

void models::save()
{
        std::cout << "Table name : " << __meta__.name << std::endl;
        for(auto& f : m_fields)
                f.second->save();
}

models::models()
{
        m_fields["pk"] = new intField(12);
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

void intField::save()
{
        std::cout << "Save value " << m_value << std::endl;
}

void intField::migrate()
{
        std::cout << "migrate value " << m_value << std::endl;
}