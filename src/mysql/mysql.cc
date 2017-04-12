#include <mysql.h>

sqlDriver::sqlDriver(std::string host, std::string username,
                     std::string password, std::string databaseName)
{
  try
  {
    driver = get_driver_instance();
    con = driver->connect(host, username, password);
    stmt = con->createStatement();
    std::string checkDbs = "CREATE DATABASE IF NOT EXISTS ";
    checkDbs.append(databaseName);
    checkDbs.append(";");
    stmt->execute(checkDbs.c_str());
    delete stmt;
    con->setSchema(databaseName.c_str());
  }
  catch (sql::SQLException &e)
  {
    cout << "Some error in sql";
  }
}

bool DB::connect(std::string host, std::string databaseName,
                 std::string username,
                 std::string password)
{
  try
  {
    DB::driver = get_driver_instance();
    DB::con = driver->connect(host, username, password);
    sql::Statement *stmt;
    stmt = DB::con->createStatement();
    std::string checkDbs = "CREATE DATABASE IF NOT EXISTS ";
    checkDbs.append(databaseName);
    checkDbs.append(";");
    stmt->execute(checkDbs.c_str());
    delete stmt;
    con->setSchema(databaseName.c_str());
    return true;
  }
  catch (sql::SQLException &e)
  {
    std::cout << e.what();
    return false;
  }
}

tab *DB::table(std::string tableName)
{
  tab *tableInstance = new tab(tableName);
  return tableInstance;
}

tab::tab(std::string tableName)
{
  this->tableName = tableName;
}

tab::~tab()
{
}

tab *tab::addColumns(std::map<std::string, dbColumn> dbConf)
{
  this->CreateColumnConf = dbConf;
  return this;
}

void tab::create()
{
  for (const auto &col : this->CreateColumnConf)
  {
    std::cout << col.first << "(" << col.second.__type__ << "|" <<
              col.second.__size__ << ")";
    for (const auto &iter : col.second.__params__)
      std::cout << "|" << iter << "|";
    std::cout << std::endl;
  }
}

sql::Driver *DB::driver;
sql::Connection *DB::con;
