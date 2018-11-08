#include "../include/controller_user.hpp"
#include "../include/command_user.hpp"


FeedbackAuthentication CntrIUAuthentication::authenticate() throw(runtime_error)
{
  Identifier* identifier = new Identifier();
  Password* password = new Password();
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

      identifier->set_value(id_input);

      cout << "Digite a senha: ";
      cin >> password_input;

      password->set_value(password_input);
      break;      
    }

    catch(const invalid_argument *exp)
    {
      cout << std::endl << "Dado em formato incorreto." << std::endl;
    }
  }

  // Authentication solicitation

  feedback = this->cntr_serv_authentication_->authenticate(*identifier, *password);

  // Authentication result

  if(feedback.get_value() == FeedbackAuthentication::kFail_)
  {
    cout << std::endl << "Falha na autenticação." << std::endl;
  }

  authentication_feedback.set_value(feedback.get_value());
  authentication_feedback.set_identifier(*identifier);

  return authentication_feedback;
}

void CntrIUUser::execute(const Identifier &identifier) throw(runtime_error)
{
  CommandIUUser *comand;

  int option;

  while(true)
  {
    // Clean terminal's screen

    // system("CLS");

    // Show options

    cout << std::endl << "Gerenciamento de Usuario" << endl;

    cout << "Incluir    - " << this->kInclude_ << endl;
    cout << "Remover    - " << this->kRemove_ << endl;
    cout << "Pesquisar  - " << this->kSeek_ << endl;
    cout << "Editar     - " << this->kUpdate_ << endl;
    cout << "Retornar   - " << this->kReturn_ << endl;
    cout << "Selecione uma opcao : ";

    cin >> option;

    switch(option)
    {
      case kInclude_:  comand = new CommandIUUserInclude();
                       comand->execute(this->cntrServUser);
                       delete comand;
                       break;
        
      case kRemove_:   comand = new CommandIUUserRemove();
                       comand->execute(this->cntrServUser);
                       delete comand;
                       break;

      case kSeek_:     comand = new CommandIUUserSeek();
                       comand->execute(this->cntrServUser);
                       delete comand;
                       break;

      case kUpdate_:   comand = new CommandIUUserUpdate();
                       comand->execute(this->cntrServUser);
                       delete comand;
                       break;

    }
  
    if(option == kReturn_)
    {
      break;
    } 


  }

  return;
}


