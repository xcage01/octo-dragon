#ifndef ORM_CLASS
#define ORM_CLASS

#include <map>
#include <string>
#include <iostream>
#include <mysql.h>

struct modelMeta
{
  std::string name;
};

struct fieldVal
{
  int int_data;
  bool bool_data;
  std::string string_data;

  enum {NONE_PROP, INT_PROP, BOOL_PROP, STRING_PROP} m_type;
};

struct validatedData
{
  bool isValid;
  fieldVal value;
};

class modelField
{
public:
  modelField(int size)
  {
    __size__ = size;
  };
  modelField() {};
  virtual ~modelField() {};
  virtual std::string __type__() = 0;
  virtual void set(std::string) = 0;
  virtual void set(int) = 0;
  virtual validatedData is_valid(std::string data) = 0;
  int __size__ = -1;
};


class charField : public modelField
{
public:
  charField(int value) : modelField(value) {};
  charField() : modelField() {};
  virtual void set(std::string val)
  {
    __value__ = val;
  };
  virtual void set(int) {};
  virtual validatedData is_valid(std::string data);
  std::string __type__();
private:
  int size;
  std::string __value__;
};

class integerField : public modelField
{
public:
  integerField(int value) : modelField(value) {};
  integerField() : modelField() {};
  virtual void set(std::string) {};
  virtual void set(int val)
  {
    __value__ = val;
  };
  virtual validatedData is_valid(std::string data);
  std::string __type__();
private:
  int size;
  int __value__;
};


class bigIntegerField : public modelField
{
public:
  bigIntegerField(int value) : modelField(value) {};
  bigIntegerField() : modelField() {};
  virtual void set(std::string) {};
  virtual void set(int val)
  {
    __value__ = val;
  };
  virtual validatedData is_valid(std::string data);
  std::string __type__();
private:
  int size;
  int __value__;
};

class tinyInt : public modelField
{
public:
  tinyInt(int value) : modelField(value) {};
  tinyInt() : modelField() {};
  virtual void set(std::string) {};
  virtual void set(int val)
  {
    __value__ = val;
  };
  virtual validatedData is_valid(std::string data);
  std::string __type__();
private:
  int size;
  int __value__;
};

class textField : public modelField
{
public:
  textField(int value) : modelField(value) {};
  textField() : modelField() {};
  virtual void set(std::string val)
  {
    __value__ = val;
  };
  virtual validatedData is_valid(std::string data);
  virtual void set(int) {};
  std::string __type__();
private:
  int size;
  std::string __value__;
};

class longTextField : public modelField
{
public:
  longTextField(int value) : modelField(value) {};
  longTextField() : modelField() {};
  virtual void set(std::string val)
  {
    __value__ = val;
  };
  virtual void set(int) {};
  virtual validatedData is_valid(std::string data);
  std::string __type__();
private:
  int size;
  std::string __value__;
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
  void data(std::map<std::string, std::string> data)
  {
    field = data;
  };
  virtual ~models();
  virtual void migrate();
  virtual void save();
  virtual bool is_valid();
  modelMeta __meta__;
protected:
  std::map<std::string, modelField *> m_fields;
  std::map<std::string, std::string> field;
  std::map<std::string, validatedData> clean_data;
  std::string primary = "pk";
  std::list<std::string> notNull;
  std::list<std::string> unique;
  std::map<std::string, std::list<std::string> > m_params;
};

#endif
