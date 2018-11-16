#ifndef PROJETO_TP1_CONTROLLER_SERVICE_H
#define PROJETO_TP1_CONTROLLER_SERVICE_H

#include "../include/interfaces.hpp"
#include "../include/DataBase.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

// Authentication Server's layer controller

class ServAuthentication:public IServAuthentication
{
  public:

  Feedback authenticate(const Identifier&, const Password&) throw(runtime_error);
};

// User entity's controller(service layer)
class ServUser: public IServUser
{
  public:

  Feedback include(const User&) throw(runtime_error);
  Feedback remove(const Identifier&) throw(runtime_error);
  FeedbackUser seek(const Identifier&) throw(runtime_error);
  Feedback update(const Identifier&) throw(runtime_error);
};
#endif