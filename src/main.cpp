#include <stdexcept>
#include <iostream>
#include<string>

#include "../include/domain.hpp"
#include "../include/entity.hpp"
#include "../include/interfaces.hpp"
#include "../include/controller_user.hpp"
#include "../include/controller_service.hpp"
#include "../include/stubs.hpp"
#include "../include/command_user.hpp"

using namespace std;

int main()
{
  IUAuthentication *cntr_iu_authentication;
  IUUser           *cntr_iu_user;

  cntr_iu_authentication = new CntrIUAuthentication();
  cntr_iu_user = new CntrIUUser();

  IServAuthentication *serv_authentication;
  IServUser           *serv_user;

  serv_authentication = new ServAuthentication();
  serv_user = new ServUser();

  cntr_iu_authentication->setCntrServAuthentication(serv_authentication);
  cntr_iu_user->setCntrServUser(serv_user);

  std::string account_check;

  // cout << endl << "VALORES DOS TRIGGERS:" << endl << endl;
  // cout << "Trigger de falha            = " << "abcde"  << endl;
  // cout << "Trigger de erro de sistema  = " << "syser" << endl;

  FeedbackAuthentication feedback;

  cout << "Possui cadastro? ";

  while(true)
  {
    cin >> account_check;
    getchar();

    if ((account_check.compare("S") == 0)
        || (account_check.compare("s") == 0) 
        || (account_check.compare("N") == 0)
        || (account_check.compare("n") == 0)
        || (account_check.compare("sim") == 0)
        || (account_check.compare("nao") == 0)
        || (account_check.compare("Nao") == 0)
        || (account_check.compare("Sim") == 0))
    {
      break;
    }

    cout << "Comando nao identificado. Insira novamente a resposta." << endl;;
  }

  if((account_check.compare("N")  == 0) 
     || (account_check.compare("n")  == 0) 
     || (account_check.compare("nao")  == 0)
     || (account_check.compare("Nao")  == 0))
  {
    CommandIUUser *command;
    command = new CommandIUUserInclude();
    command->execute(serv_user);
    delete command;
  }

  while(true)
  {
    cout << endl << "--------- Trabalho TP1 ---------\n" << endl;

    try
    {
      feedback = cntr_iu_authentication->authenticate();

      if(feedback.get_value() == FeedbackAuthentication::kSuccess_)
      {
        break;
      }
    }

    catch(const runtime_error &exp)
    {
      cout << "Erro no sistema" << endl;
    }
  }

  try
  {
    cntr_iu_user->execute(feedback.get_identifier());
  }

  catch(const runtime_error &exp)
  {
    cout << "Erro de sistema." << std::endl;
  }

  delete cntr_iu_authentication;
  delete cntr_iu_user;
  delete serv_authentication;
  delete serv_user;

  return 0;
}