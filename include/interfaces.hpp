#ifndef PROJETO_TP1_INTERFACES_HPP
#define PROJETO_TP1_INTERFACES_HPP

#include "../include/domain.hpp"
#include "../include/entity.hpp"
#include <stdexcept>

using namespace std;

// Authentication User's interface. Communicates with user
// by interaction through text interface in the user layer.
//=========================================================

class IServAuthentication;
class IServUser;

class IUAuthentication
{
  public:
    // Authentication service's solicitation method 
    virtual FeedbackAuthentication authenticate() throw(runtime_error) = 0;

    // Service's layer Authentication controller linking method
    virtual void setCntrServAuthentication(IServAuthentication *cntr_serv_authentication) = 0;

    // Virtual Destructor method
    virtual ~IUAuthentication(){}
};

// Authentication Service's interface. Executes
// User's authentication in the Service's layer.
//=========================================================


class IServAuthentication
{
  public:
    // Authentication service's solicitation method 
    virtual Feedback authenticate(const Identifier&, const Password&) throw(runtime_error) = 0;
    
    // Virtual Destructor method
    virtual ~IServAuthentication(){}
};

// User entity User's interface. Communicates
// by interaction through text interface in the user layer.
//=========================================================

class IUUser
{
  public:
    // User entity service's solicitation method
    virtual void execute(const Identifier&) throw(runtime_error) = 0;

    // Service's layer User controller linking method
    virtual void setCntrServUser(IServUser* ) = 0;

    // Virtual Destructor method
    virtual ~IUUser(){}

};

// User entity Service's interface. Executes
// User entity's command in the Service's layer.
//=========================================================
class IServUser
{
  public:
    // User entity service's solicitation method
    virtual Feedback include(const User&) throw(runtime_error) = 0;
    virtual Feedback remove(const Identifier&) throw(runtime_error) = 0;
    virtual FeedbackUser seek(const Identifier&) throw(runtime_error) = 0;
    virtual Feedback update(const Identifier&) throw(runtime_error)= 0;

    // Virtual Destructor method
    virtual ~IServUser(){}
};
#endif 