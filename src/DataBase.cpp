#include "../include/DataBase.hpp"
#include <string>

list<DBData> SQLCommand::data_list_;

//---------------------------------------------------------------------------
// Storage Error methods
StorageError::StorageError(std::string report)
{
  this->report_ = report;
}

std::string StorageError::What()
{
  return this->report_;
}

//---------------------------------------------------------------------------
// DBData Error methods
void DBData::set_column_name(const std::string &column_name)
{
  this->column_name_ = column_name;
}

void DBData::set_column_value(const std::string &column_value)
{
  this->column_value_ = column_value;
}

//---------------------------------------------------------------------------
// SQL Command methods
void SQLCommand::connect() throw (StorageError)
{
  this->rc_ = sqlite3_open(this->DBName_, &(this->db_));

  if( this->rc_ != SQLITE_OK)
  {
    throw StorageError("Erro na conexao ao Banco de Dados.");
  }
}

void SQLCommand::disconnect() throw (StorageError)
{
  this->rc_ = sqlite3_close(this->db_);

  if( this->rc_ != SQLITE_OK)
  {
    throw StorageError("Erro de desconexao ao Banco de Dados.");
  }
}

void SQLCommand::execute() throw (StorageError)
{
  this->connect();
  this->rc_ = sqlite3_exec(this->db_, this->commandSQL_.c_str(), callback, 0, &(this->report_));

  if(this->rc_ != SQLITE_OK)
  {
    if(this->report_)
    {
      free(this->report_);
    }

    throw StorageError("Erro na execucao do comando SQL.");
  }

  this->disconnect();
}

int SQLCommand::callback(void *NotUsed, int argc, char **column_value, char **column_name)
{
  NotUsed = 0;
  DBData data;
  int i;
  for(i=0; i < argc; i++)
  {
    data.set_column_name(column_name[i]);
    data.set_column_value(column_value[i] ? column_value[i]: "NULL");
    data_list_.push_front(data);
  }
  return 0;
}

//---------------------------------------------------------------------------
// SQL User Read methods
SQLReadPassword::SQLReadPassword(Identifier identifier)
{
  this->commandSQL_ = "SELECT password FROM users WHERE identifier = ";
  this->commandSQL_ += "'" + identifier.get_value() + "'" + ";";
}

std::string SQLReadPassword::get_data() throw(StorageError)
{
  DBData data;
  std::string password;

  if(this->data_list_.empty())
  {
    throw StorageError("Lista de resultados vazia.");
  }

  data = this->data_list_.back();
  this->data_list_.pop_back();
  password = data.get_column_value();

  return password;
}

//---------------------------------------------------------------------------
// SQL User Seek methods

SQLSeekUser::SQLSeekUser(Identifier identifier)
{
  this->commandSQL_ = "SELECT * FROM users WHERE identifier = ";
  this->commandSQL_ += "'" + identifier.get_value() + "'" + ";";
}

User SQLSeekUser::get_data() throw(StorageError)
{
  DBData data;
  User user;

  // Remove identifier  
  if(this->data_list_.empty())
  {
    throw StorageError("Lista de resultado vazia.");
  }
  data = this->data_list_.back();
  this->data_list_.pop_back();
  Identifier *identifier = new Identifier(data.get_column_value());
  user.set_identifier(identifier);

  // Remove name
  if(this->data_list_.empty())
  {
    throw StorageError("Lista de resultado vazia.");
  }
  data = this->data_list_.back();
  this->data_list_.pop_back();
  Name* name = new Name(data.get_column_value());
  user.set_name(name);
  
  // Remove password
  if(this->data_list_.empty())
  {
    throw StorageError("Lista de resultado vazia.");
  }
  data = this->data_list_.back();
  this->data_list_.pop_back();
  Password *password = new Password(data.get_column_value());
  user.set_password(password);

  return user;
}

//---------------------------------------------------------------------------
// SQL User Signin methods

SQLSigninUser::SQLSigninUser(User user)
{
  this->commandSQL_ = "INSERT INTO users(name,identifier,password) VALUES (";
  this->commandSQL_ += "'" + user.get_name()->get_value() + "', ";
  this->commandSQL_ += "'" + user.get_identifier()->get_value() + "', ";
  this->commandSQL_ += "'" + user.get_password()->get_value() + "')" + ";";
}

//---------------------------------------------------------------------------
// SQL User Delete methods

SQLDeleteUser::SQLDeleteUser(Identifier identifier)
{
  this->commandSQL_ = "DELETE FROM users WHERE identifier = ";
  this->commandSQL_ += "'" + identifier.get_value() + "'" + ";";
}

//---------------------------------------------------------------------------
// SQL User Update methods

SQLUpdateUser::SQLUpdateUser(User user)
{
  this->commandSQL_ = "UPDATE users ";
  this->commandSQL_ += "SET name = '" + user.get_name()->get_value();
  this->commandSQL_ += "', password = '" + user.get_password()->get_value();
  this->commandSQL_ += "' WHERE identifier = '" + user.get_identifier()->get_value() + "';";
}