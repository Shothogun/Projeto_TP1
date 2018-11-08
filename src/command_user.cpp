#include "../include/command_user.hpp"

// -------Command service's solicitation methods -------

void CommandIUUserInclude::execute(IServUser* cntr_serv_user) throw(runtime_error)
{
  Feedback feedback;
  User* user = new User();

  // User interaction message

  while(true)
  {
    try
    {
      std::string input;
      Identifier* identifier = new Identifier();
      cout << "Digite o identificador: ";
      cin >> input;
      identifier->set_value(input);
      user->set_identifier(identifier);
      break;
    }
    catch (invalid_argument &exp)
    {
      cout << "Identificador com formato incorreto"<< std::endl;
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
  Feedback feedback;
  Identifier* identifier = new Identifier();

  // User interaction message

  while(true)
  {
    try
    {
      std::string input;
      cout << "Digite o identificador";
      cin >> input;
      identifier->set_value(input);
      break;
    }
    catch(invalid_argument &exp)
    {
      cout << "Identificador com formato incorreto";
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

  // User interaction message

  // =========================
  // =========================
  //   Codigo de acesso a BD
  // =========================
  // =========================

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

  User* user = new User();
  Identifier* identifier = new Identifier();


  // User interaction message

  // =========================
  // =========================
  //   Codigo de acesso a BD
  // =========================
  // =========================

  feedback.set_value(Feedback::kSuccess_);

  // -------Method solicitation-------

  cntr_serv_user->update(*user);

  if(feedback.get_value() == Feedback::kSuccess_)
  {
    cout << "Sucesso na execucao da operacao" << std::endl;
  }

  else
  {
    cout << "Falha na execucao da operacao" << endl;
  }

  delete identifier;
}