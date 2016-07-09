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
        for(const auto & data:field)
        {
                std::cout<<data.first<<":"<<data.second<<std::endl;
        }
}

bool models::is_valid()
{
        bool validFlag = true;
        for(auto& f : m_fields)
        {
                validatedData data = f.second->is_valid(field[f.first]);
                if (!data.isValid)
                {
                        validFlag = false;
                        break;
                }else
                {
                      clean_data[f.first] = data;  
                }
        }
        return validFlag;
}

models::models()
{
        m_fields["pk"] = new pk();
        m_params["pk"] = {"AUTO_INCREMENT"};
}

models::~models()
{

}


std::string charField::__type__()
{
        return "VARCHAR";
}

std::string integerField::__type__()
{
        return "INT";
}

std::string bigIntegerField::__type__()
{
        return "BIGINT";
}

std::string tinyInt::__type__()
{
        return "TINYINT";
}

std::string textField::__type__()
{
        return "TEXT";
}

std::string longTextField::__type__()
{
        return "LONGTEXT";
}


validatedData charField::is_valid(std::string data)
{
        validatedData vData;
        vData.isValid = true;
        vData.value.m_type = fieldVal::STRING_PROP;
        vData.value.string_data = data;
        return vData;
}

validatedData integerField::is_valid(std::string data)
{
        validatedData vData;
        vData.isValid = true;
        vData.value.m_type = fieldVal::INT_PROP;
        vData.value.int_data = std::stoi(data);
        return vData;
}

validatedData bigIntegerField::is_valid(std::string data)
{
        validatedData vData;
        vData.isValid = true;
        vData.value.m_type = fieldVal::INT_PROP;
        vData.value.int_data = std::stoi(data);
        return vData;
}

validatedData tinyInt::is_valid(std::string data)
{
        validatedData vData;
        vData.isValid = true;
        vData.value.m_type = fieldVal::INT_PROP;
        vData.value.int_data = std::stoi(data);
        return vData;
}

validatedData textField::is_valid(std::string data)
{
        validatedData vData;
        vData.isValid = true;
        vData.value.m_type = fieldVal::STRING_PROP;
        vData.value.string_data = data;
        return vData;
}

validatedData longTextField::is_valid(std::string data)
{
        validatedData vData;
        vData.isValid = true;
        vData.value.m_type = fieldVal::STRING_PROP;
        vData.value.string_data = data;
        return vData;
}