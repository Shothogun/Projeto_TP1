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
  const static std::string kTriggerFail_;
  const static std::string KSystemError_;

  Feedback authenticate(const Identifier&, const Password&) throw(runtime_error);
};

const std::string StubServAuthentication::kTriggerFail_ = "abcde";
const std::string StubServAuthentication::KSystemError_ = "syser";

// Interface's IServUser stub

class StubServUser: public IServUser
{
  public:

  // Error's notification trigger

  const static int kEqual_ = 0;
  const static std::string kTriggerFail_;
  const static std::string KSystemError_;

  Feedback include(const User&) throw(runtime_error);
  Feedback remove(const Identifier&) throw(runtime_error);
  FeedbackUser seek(const Identifier&) throw(runtime_error);
  Feedback update(const User&) throw(runtime_error);
};

const std::string StubServUser::kTriggerFail_ = "abcde";
const std::string StubServUser::KSystemError_ = "syser";
#endif