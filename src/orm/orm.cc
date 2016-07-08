#include <orm.h>

void models::migrate()
{
        std::map<std::string,dbColumn> tableColumnConfiguration;
        for(auto& f : m_fields)
        {
                dbColumn col;
                col.__type__ = f.second->__type__();
                col.__size__ = f.second->__size__;
                tableColumnConfiguration[f.first] = col;
        }
        tableColumnConfiguration[this->primary].__params__.push_back("PRIMARY KEY");
        for(const auto& notNullable : this->notNull)
        {
                tableColumnConfiguration[notNullable].__params__.push_back("NOT NULL");
        }
        for(const auto& unique : this->unique)
        {
                tableColumnConfiguration[unique].__params__.push_back("UNIQUE");
        }
        for(const auto& addParams : this->m_params)
        {
                for(const auto paramIter:addParams.second)
                {
                        tableColumnConfiguration[addParams.first].__params__.push_back(paramIter);
                }
        }
        DB::table(__meta__.name)->addColumns(tableColumnConfiguration)->create();
}

void models::save()
{
        std::cout << "Table name : " << __meta__.name << std::endl;
        for(auto& f : m_fields)
                f.second->save();
}

models::models()
{
        m_fields["pk"] = new pk();
        m_params["pk"] = {"AUTO_INCREMENT"};
}

models::~models()
{

}

void stringField::save()
{
        std::cout << "Save value " << m_value << std::endl;
}

void intField::save()
{
        std::cout << "Save value " << m_value << std::endl;
}

void pk::save()
{

}

std::string stringField::__type__()
{
        return "VARCHAR";
}

std::string intField::__type__()
{
        return "INT";
}

sqlDriver* models::driver;