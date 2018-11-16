#include "../include/controller_user.hpp"
#include "../include/command_user.hpp"
#include <string>


FeedbackAuthentication CntrIUAuthentication::authenticate() throw(runtime_error)
{
  Identifier identifier;
  Password password;
  FeedbackAuthentication authentication_feedback;
  Feedback feedback;
  std::string id_input;
  std::string password_input;
  

  // ====================================
  //    Solicitar Identificador e senha
  // ====================================

  
  while (true)
  {
    try
    {
      cout << "Digite o identificador: ";
      cin >> id_input;

      identifier.set_value(id_input);

      cout << "Digite a senha: ";
      cin >> password_input;

      password.set_value(password_input);
      break;      
    }

    catch(const invalid_argument *exp)
    {
      cout << std::endl << "Dado em formato incorreto." << std::endl;
    }
  }

  // Authentication solicitation

  feedback = this->cntr_serv_authentication_->authenticate(identifier, password);

  // Authentication result

  if(feedback.get_value() == FeedbackAuthentication::kFail_)
  {
    cout << std::endl << "Falha na autenticação." << std::endl;
  }

  authentication_feedback.set_value(feedback.get_value());
  authentication_feedback.set_identifier(identifier);

  return authentication_feedback;
}

void CntrIUUser::execute(const Identifier &identifier) throw(runtime_error)
{
  CommandIUUser *command;

  int option;

  while(true)
  {

    // Show options

    cout << std::endl << "Gerenciamento de Usuario" << endl;

    cout << "Incluir    - " << this->kInclude_ << endl;
    cout << "Remover    - " << this->kRemove_ << endl;
    cout << "Pesquisar  - " << this->kSeek_ << endl;
    cout << "Editar     - " << this->kUpdate_ << endl;
    cout << "Retornar   - " << this->kReturn_ << endl;
    cout << "Selecione uma opcao : ";

    cin >> option;
    getchar();

    switch(option)
    {
      case kInclude_:  command = new CommandIUUserInclude();
                       command->execute(this->cntrServUser);
                       delete command;
                       break;
        
      case kRemove_:   command = new CommandIUUserRemove();
                       command->execute(this->cntrServUser);
                       delete command;
                       break;

      case kSeek_:     command = new CommandIUUserSeek();
                       command->execute(this->cntrServUser);
                       delete command;
                       break;

      case kUpdate_:   command = new CommandIUUserUpdate();
                       command->execute(this->cntrServUser);
                       delete command;
                       break;

    }
  
    if(option == kReturn_)
    {
      break;
    } 


  }

  return;
}


