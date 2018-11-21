#include "../include/command_user.hpp"
#include <string>


// -------Command service's solicitation methods -------

void CommandIUUserInclude::execute(IServUser* cntr_serv_user) throw(runtime_error)
{
  cout << "Cadastrar" << std::endl << std::endl;

  Feedback feedback;
  User* user = new User();

  Name       *name = new Name();
  Identifier *identifier = new Identifier();
  Password   *password = new Password();

  std::string input_name;
  std::string input_identifier;
  std::string input_password;

  while(true)
  {
    try
    {
      cout << "Digite o nome: ";
      getline(cin, input_name);

      cout << "Digite o identificador: ";
      getline(cin, input_identifier);

      cout << "Digite a senha: ";
      getline(cin,input_password) ;

      name->set_value(input_name);
      identifier->set_value(input_identifier);
      password->set_value(input_password);

      user->set_name(name);
      user->set_identifier(identifier);
      user->set_password(password);

      break;
    }

    catch (const invalid_argument *exp)
    {
      cout << std::endl<< "Dado com formato incorreto"<< std::endl;
    }    
  }

  // -------Method solicitation-------

  feedback = cntr_serv_user->include(*user);

  if(feedback.get_value() == Feedback::kSuccess_)
  {
    cout << "Sucesso na execucao da operacao" << std::endl;
  }

  else
  {
    cout << "Falha na execucao da operacao" << std::endl;
  }

  delete user;
}

void CommandIUUserRemove::execute(IServUser* cntr_serv_user) throw(runtime_error)
{

  cout << "Remover usuario." << std::endl << std::endl;

  Feedback feedback;
  Identifier* identifier = new Identifier();

  while(true)
  {
    try
    {
      std::string input;
      cout << "Digite o identificador: ";
      cin >> input;
      identifier->set_value(input);
      break;
    }
    catch(invalid_argument &exp)
    {
      cout << std::endl<< "Identificador com formato incorreto"<< std::endl;
    }
  }

  // -------Method solicitation-------

  feedback = cntr_serv_user->remove(*identifier);

  if(feedback.get_value() == Feedback::kSuccess_)
  {
    cout << "Sucesso na execucao da operacao" << std::endl;
  }

  else
  {
    cout << "Falha na execucao da operacao" << std::endl;
  }

  delete identifier;
}

void CommandIUUserSeek::execute(IServUser* cntr_serv_user) throw (runtime_error)
{
  FeedbackUser feedback;

  Identifier* identifier = new Identifier();

  cout << std::endl<< "Procurar usuario" << std::endl << std::endl;

  // User interaction message

  while(true)
  {
    try
    {
      std::string input;
      cout << "Digite o identificador: ";
      cin >> input;

      identifier->set_value(input);

      break;
    }

    catch(invalid_argument &exp)
    {
      cout << std::endl << "Identificador com formato incorreto"<< std::endl;
    }
  }

  feedback = cntr_serv_user->seek(*identifier);

   if(feedback.get_value() == Feedback::kSuccess_)
  {
    cout << "Sucesso na execucao da operacao" << std::endl;
  }

  else
  {
    cout << "Falha na execucao da operacao" << std::endl;
  }

  delete identifier;
}


void CommandIUUserUpdate::execute(IServUser* cntr_serv_user) throw(runtime_error)
{
  Feedback feedback;

  Identifier* identifier = new Identifier();

  cout << "Editar usuario." << std::endl << std::endl;

  while(true)
  {
    try
    {
      std::string input;
      cout << "Digite o identificador: ";
      cin >> input;
      identifier->set_value(input);
      break;
    }
    catch(invalid_argument &exp)
    {
      cout << std::endl<< "Identificador com formato incorreto" << std::endl;
    }
  }

  feedback.set_value(Feedback::kSuccess_);

  // -------Method solicitation-------

  cntr_serv_user->update(*identifier);

  if(feedback.get_value() == Feedback::kSuccess_)
  {
    cout << "Sucesso na execucao da operacao" << std::endl;
  }

  else
  {
    cout << "Falha na execucao da operacao" << std::endl;
  }

  delete identifier;
}