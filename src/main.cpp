#include <stdexcept>
#include <iostream>
#include<string>

#include "../include/domain.hpp"
#include "../include/entity.hpp"
#include "../include/interfaces.hpp"
#include "../include/controller_user.hpp"
#include "../include/controller_service.hpp"
#include "../include/stubs.hpp"

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

  // cout << endl << "VALORES DOS TRIGGERS:" << endl << endl;
  // cout << "Trigger de falha            = " << "abcde"  << endl;
  // cout << "Trigger de erro de sistema  = " << "syser" << endl;

  FeedbackAuthentication feedback;

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