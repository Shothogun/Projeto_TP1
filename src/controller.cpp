#include "../include/controller.hpp"
#define ERROR 23

int CntrIUAuthentication::authenticate() throw(runtime_error)
{
  Identifier* identifier = new Identifier();
  Password* password = new Password();
  int authentication_feedback = 0;
  int feedback = 0;
  std::string id_input;
  std::string password_input;
  
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

  return authentication_feedback;
}


