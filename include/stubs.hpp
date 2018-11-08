#ifndef PROJETO_TP1_STUBS_HPP
#define PROJETO_TP1_STUBS_HPP

#include "../include/interfaces.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

// Interface's IServAuthentication stub

class StubServAuthentication:public IServAuthentication
{
  public:

  // Error's notification trigger

  const static int kEqual_ = 0;
  const std::string kTriggerFail_ = "abcde";
  const std::string KSystemError_ = "syser";

  Feedback authenticate(const Identifier&, const Password&) throw(runtime_error);
};

// Interface's IServUser stub

class StubServUser: public IServUser
{
  public:

  // Error's notification trigger

  const static int kEqual_ = 0;
  const std::string kTriggerFail_ = "abcde";
  const std::string KSystemError_ = "syser";

  Feedback include(const User&) throw(runtime_error);
  Feedback remove(const Identifier&) throw(runtime_error);
  FeedbackUser seek(const Identifier&) throw(runtime_error);
  Feedback update(const User&) throw(runtime_error);
};

#endif