#ifndef PROJETO_TP1_CONTROLLER_HPP
#define PROJETO_TP1_CONTROLLER_HPP

#include "../include/interfaces.hpp"
#include "../include/domain.hpp"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

// Authentication User's layer controller

class CntrIUAuthentication : public IUAuthentication
{
  public:
    FeedbackAuthentication authenticate() throw(runtime_error);
    void setCntrServAuthentication(IServAuthentication*);

  private:
    // Controller reference
    IServAuthentication* cntr_serv_authentication_;
};

void inline CntrIUAuthentication::setCntrServAuthentication(IServAuthentication* cntr_serv_authentication)
{
  this->cntr_serv_authentication_= cntr_serv_authentication; 
}

// User entity's controller 
class CntrIUUser : public IUUser
{
  public:
    // Interface's declared method.
    // User entity's controller service solicitation method.
    void execute(const Identifier&) throw(runtime_error);

    // Establish relationship with User entity's service layer.
    void setCntrServUser(IServUser* cntr_serv_user);

  private:
    const static int kInclude_ = 1;
    const static int kRemove_ = 2;
    const static int kSeek_ = 3;
    const static int kUpdate_ = 4;
    const static int kReturn_ = 5;

    // User entity's controller reference 
    IServUser* cntrServUser;

};

void inline CntrIUUser::setCntrServUser(IServUser* cntr_serv_user)
{
  this->cntrServUser = cntr_serv_user;
}

#endif