#ifndef PROJETO_TP1_DATABASE_H
#define PROJETO_TP1_DATABASE_H

#include "../include/entity.hpp"
#include "../include/domain.hpp"
#include <stdio.h>
#include <iostream>
#include <list>
#include "../framework/sqlite3.h"

using namespace std;

// Report DB access Class 
class StorageError{
  private:
    std::string report_;
  public:
    StorageError(string);
    std::string What();
};

// DB data Class 
class DBData{ 
  private:
    std::string column_name_;
    std::string column_value_;
  public:
    void set_column_name(const string&);
    std::string get_column_name() const;
    void set_column_value(const string&);
    std::string get_column_value() const;
};

inline std::string DBData::get_column_name() const
{
  return this->column_name_;
}

inline std::string DBData::get_column_value() const
{
  return this->column_value_;
}

class SQLCommand
{
  private:
    const char *DBName_;
    sqlite3 *db_;
    char *report_;
    int rc_;
    void connect() throw (StorageError);
    void disconnect() throw (StorageError);
    static int callback(void *, int, char **, char **);

  protected:
    static list<DBData> data_list_;
    std::string commandSQL_;

  public:
    SQLCommand()
    {
      // Nome do arquivo Banco de dados
      DBName_ = "projeto.db";
    }
    void execute() throw (StorageError);
};

class SQLReadPassword:public SQLCommand
{
  public:
    SQLReadPassword(Identifier);
    std::string get_data() throw(StorageError);
};

class SQLSeekUser:public SQLCommand
{
  public:
    SQLSeekUser(Identifier);
    User get_data() throw(StorageError);
};

class SQLSigninUser:public SQLCommand
{
  public:
    SQLSigninUser(User);
};

class SQLUpdateUser:public SQLCommand
{
  public:
    SQLUpdateUser(User);
};

class SQLDeleteUser:public SQLCommand
{
  public:
    SQLDeleteUser(Identifier);
};

#endif 