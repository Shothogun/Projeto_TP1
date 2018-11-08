#include "../include/stubs.hpp"

Feedback StubServAuthentication::authenticate(const Identifier &identifier, const Password &password) throw(runtime_error)
{
  // Show input data

  cout << std::endl << "StubServAuthentication::authenticate" << std::endl;

  cout << "Identificador = " <<  identifier.get_value() << std::endl;
  cout << "Senha         = " <<  password.get_value() << std::endl;

  FeedbackAuthentication feedback;

  // Actions according to identifier value

  if(identifier.get_value().compare(kTriggerFail_))
  {
    feedback.set_value(FeedbackAuthentication::kSuccess_);
  }

  else if(identifier.get_value().compare(KSystemError_))
  {
    throw runtime_error("Erro de sistema");
  }

  else
  {
    feedback.set_value(FeedbackAuthentication::kSuccess_);
  }
  
  return feedback;
}