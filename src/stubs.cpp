#include "../include/stubs.hpp"

Feedback StubServAuthentication::authenticate(const Identifier &identifier, const Password &password) throw(runtime_error)
{
  // Show input data

  cout << std::endl << "StubServAuthentication::authenticate" << std::endl;

  cout << "Identificador = " <<  identifier.get_value() << std::endl;
  cout << "Senha         = " <<  password.get_value() << std::endl;

  FeedbackAuthentication feedback;

  // Actions according to identifier value

  if(identifier.get_value().compare(kTriggerFail_) == kEqual_)
  {
    feedback.set_value(FeedbackAuthentication::kSuccess_);
  }

  else if(identifier.get_value().compare(KSystemError_) == kEqual_)
  {
    throw runtime_error("Erro de sistema");
  }

  else
  {
    feedback.set_value(FeedbackAuthentication::kSuccess_);
  }
  
  return feedback;
}

Feedback StubServUser::include(const User &user) throw(runtime_error)
{
  // Show input data

  cout << std::endl << "StubServUser::include" << std::endl;

  Feedback feedback;

  feedback.set_value(Feedback::kSuccess_);

  // Actions according to identifier value

  if(user.get_identifier()->get_value().compare(kTriggerFail_) == kEqual_)
  {
    feedback.set_value(FeedbackAuthentication::kSuccess_);
  }

  else if(user.get_identifier()->get_value().compare(KSystemError_) == kEqual_)
  {
    throw runtime_error("Erro de sistema");
  }

  else
  {
    feedback.set_value(FeedbackAuthentication::kSuccess_);
  }

  return feedback;
}

Feedback StubServUser::remove(const Identifier &identifier) throw (runtime_error)
{
   // Show input data

  cout << std::endl << "StubServUser::remove" << std::endl;

  Feedback feedback;

  feedback.set_value(Feedback::kSuccess_);

  // Actions according to identifier value

  if(identifier.get_value().compare(kTriggerFail_) == kEqual_)
  {
    feedback.set_value(FeedbackAuthentication::kSuccess_);
  }

  else if(identifier.get_value().compare(KSystemError_) == kEqual_)
  {
    throw runtime_error("Erro de sistema");
  }

  else
  {
    feedback.set_value(FeedbackAuthentication::kSuccess_);
  }

  return feedback;
}

FeedbackUser StubServUser::seek(const Identifier &identifier) throw (runtime_error)
{
  // Show input data

  cout << std::endl << "StubServUser::seek" << std::endl;

  FeedbackUser feedback;

  feedback.set_value(Feedback::kSuccess_);

  // Actions according to identifier value

  if(identifier.get_value().compare(kTriggerFail_) == kEqual_)
  {
    feedback.set_value(FeedbackAuthentication::kSuccess_);
  }

  else if(identifier.get_value().compare(KSystemError_) == kEqual_)
  {
    throw runtime_error("Erro de sistema");
  }

  else
  {
    feedback.set_value(FeedbackAuthentication::kSuccess_);
  }

  return feedback;
}

Feedback StubServUser::update(const User &user) throw (runtime_error)
{
  // Show input data

  cout << std::endl << "StubServUser::update" << std::endl;

  FeedbackUser feedback;

  feedback.set_value(Feedback::kSuccess_);

  // Actions according to identifier value

  if(user.get_identifier()->get_value().compare(kTriggerFail_) == kEqual_)
  {
    feedback.set_value(FeedbackAuthentication::kSuccess_);
  }

  else if(user.get_identifier()->get_value().compare(KSystemError_) == kEqual_)
  {
    throw runtime_error("Erro de sistema");
  }

  else
  {
    feedback.set_value(FeedbackAuthentication::kSuccess_);
  }

  return feedback;

}