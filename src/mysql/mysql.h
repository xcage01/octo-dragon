#ifndef MYSQL_LIB
#define MYSQL_LIB

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <iostream>
#include <vector>

using namespace std;

struct dbColumn
{
  std::string __type__;
  int __size__;
  std::vector<std::string> __params__;
};

class sqlDriver
{
public:
  sqlDriver(std::string, std::string, std::string, std::string);
  ~sqlDriver();
  bool execute();
private:
  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res;
  sql::PreparedStatement *pstmt;
};

class tab
{
public:
  tab(std::string);
  ~tab();

  tab *addColumns(std::map<std::string, dbColumn>);
  void create();
private:
  std::string tableName;
  sql::Statement *stmt;
  std::map<std::string, dbColumn> CreateColumnConf;
};

class DB
{
public:
  DB();
  ~DB();
  static bool connect(std::string, std::string, std::string,
                      std::string);
  static tab *table(std::string);
private:
  static sql::Driver *driver;
  static sql::Connection *con;
};
#endif
