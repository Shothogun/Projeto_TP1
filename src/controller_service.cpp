#include "../include/controller_service.hpp"
#include <string>

Feedback ServAuthentication::authenticate(const Identifier &identifier, const Password &password) throw(runtime_error)
{
  // Show input data

  

  cout << "Identificador = " <<  identifier.get_value() << std::endl;
  cout << "Senha         = " <<  password.get_value() << std::endl;

  FeedbackAuthentication feedback;

  SQLReadPassword command(identifier);

  try
  {
    command.execute();
    std::string DB_password;
    DB_password = command.get_data();
    
    // Compare password

    if(DB_password == password.get_value())
    {
      feedback.set_value(Feedback::kSuccess_);
    }
    
    else
    {
      feedback.set_value(Feedback::kFail_);
      cout << endl << endl << "Digite algo para continuar." << endl;
      getchar();
    }
  }
  catch(StorageError exp)
  {
    std::cout << std::endl << exp.What();
    cout << endl << endl << "Digite algo para continuar."<< endl;
    getchar();
  }

  return feedback;
}

Feedback ServUser::include(const User& user) throw(runtime_error)
{
  Feedback feedback;

  SQLSigninUser command(user);

  try
  {
    feedback.set_value(Feedback::kSuccess_);
    command.execute();
  }

  catch(StorageError exp)
  {
    feedback.set_value(Feedback::kFail_);
    cout << endl << "Erro no acesso ao banco de dados.";
    cout << endl << endl << "Digite algo para continuar." << endl;
    getchar();
  }

  return feedback;
}

Feedback ServUser::remove(const Identifier& identifier) throw(runtime_error)
{
  Feedback feedback;

  SQLDeleteUser command(identifier);

  try
  {
    feedback.set_value(Feedback::kSuccess_);
    command.execute();
  }
  catch(StorageError exp)
  {
    feedback.set_value(Feedback::kFail_);
    cout << endl << "Erro no acesso ao banco de dados.";
    cout << endl << endl << "Digite algo para continuar." << endl;
    getchar();
  }

  return feedback;
}

FeedbackUser ServUser::seek(const Identifier &identifier) throw(runtime_error)
{
  FeedbackUser feedback;

  User user;

  SQLSeekUser command(identifier);

  try
  {
    feedback.set_value(Feedback::kSuccess_);
    command.execute();
  }
  catch(StorageError exp)
  {
    feedback.set_value(Feedback::kFail_);
    cout << endl << "Erro no acesso ao banco de dados.";
    cout << endl << endl << "Digite algo para continuar." << endl;
    getchar();

    return feedback; 
  }

  try
  {
    user = command.get_data();

    cout << endl << "Resultados obtidos." << endl << endl;
    cout << "Nome : " << user.get_name()->get_value() << endl;
    cout << "Identificador : " << user.get_identifier()->get_value() << endl;
    cout << "Senha : " << user.get_password()->get_value() << endl;
    cout << "Digite algo para continuar" << endl;
    getchar();
  }

  catch(StorageError exp)
  {
    feedback.set_value(Feedback::kFail_);
    cout << endl << exp.What();
    cout << endl << endl << "Digite algo para continuar." << endl;
    getchar(); 
  }

  return feedback; 
}

Feedback ServUser::update(const Identifier &identifier) throw(runtime_error)
{
  Feedback feedback;

  std::string name_input;
  std::string identifier_input;
  std::string password_input;

  Name new_name;
  Identifier new_identifier;
  Password new_password;

  SQLSeekUser command_seek(identifier);

  try
  {
    feedback.set_value(Feedback::kSuccess_);
    command_seek.execute();
  }
  catch(StorageError exp)
  {
    feedback.set_value(Feedback::kFail_);
    cout << endl << "Erro no acesso ao banco de dados.";
    cout << endl << endl << "Digite algo para continuar." << endl;
    getchar();

    return feedback;
  }

  User DB_user = command_seek.get_data();

  cout << endl << "Dados atuais." << endl << endl;
  cout << "Nome : " << DB_user.get_name()->get_value() << endl;
  cout << "Identificador : " << DB_user.get_identifier()->get_value() << endl;
  cout << "Senha : " << DB_user.get_password()->get_value() << endl;

  cout << "Digite os novos dados.\n" << endl;

  cout << "Nome : ";
  getchar();
  getline(std::cin, name_input);

  cout << "Identificador : ";
  getline(std::cin,identifier_input);

  cout << "Senha : ";
  getline(std::cin, password_input);
  
  try
  {
    new_name.set_value(name_input);
    new_identifier.set_value(identifier_input);
    new_password.set_value(password_input);
  }

  catch(invalid_argument)
  {
    feedback.set_value(Feedback::kFail_);
    cout << endl << "Dado informado incorretamente." << endl << endl;
    cout << "Digite algo para continuar :" << endl;
    getchar(); 
    return feedback;
  }

  User user;

  user.set_name(&new_name);
  user.set_identifier(&new_identifier);
  user.set_password(&new_password);

  SQLUpdateUser command_update(user);

  try
  {
    command_update.execute();
  }

  catch(StorageError exp)
  {
    feedback.set_value(Feedback::kFail_);
    cout << endl << "Erro no acesso ao banco de dados.";
    cout << endl << endl << "Digite algo para continuar." << endl;
    getchar(); 
  }

  return feedback;
}