#ifndef PROJETO_TP1_INTERFACES_HPP
#define PROJETO_TP1_INTERFACEX_HPP

#include "../include/domain.hpp"
#include "../include/entity.hpp"
#include <stdexcept>

using namespace std;

// Authentication User's interface. Communicates with user
// by interaction through text interface in the user layer.
//=========================================================

class IUAuthentication;
class IServAuthentication;

class IUAuthentication
{
  public:
    // Authentication service's solicitation method 
    virtual int authenticate() throw(runtime_error) = 0;

    // Service's layer Authentication controller linking method
    virtual void setCntrServAuthentication(IServAuthentication *server) = 0;

    // Virtual Destructor method
    virtual ~IUAuthentication(){};
};

// Authentication Service's interface. Executes
// User's authentication in the Service's layer.
//=========================================================


class IServAuthentication
{
  public:
    // Authentication service's solicitation method 
    virtual int authenticate(const Identifier&, const Password&) throw(runtime_error) = 0;
    
    // Virtual Destructor method
    virtual ~IServAuthentication();
};

// User entity User's interface. Communicates
// by interaction through text interface in the user layer.
//=========================================================

class IUUSer;
class IServUser;

class IUUser
{
  public:
    // User entity service's solicitation method
    virtual void execute(const Identifier&) throw(runtime_error) = 0;

    // Service's layer User controller linking method
    virtual void setCntrUser(IServUser* ) = 0;

    // Virtual Destructor method
    virtual ~IUUser();

};

// User entity Service's interface. Executes
// User entity's command in the Service's layer.
//=========================================================
class IServUser
{
  public:
    // User entity service's solicitation method
    virtual int include(const User&) throw(runtime_error) = 0;
    virtual int remove(const Identifier&) throw(runtime_error) = 0;
    virtual int seek(const Identifier&) throw(runtime_error) = 0;
    virtual int update(const User&) throw(runtime_error)= 0;

    // Virtual Destructor method
    virtual ~IServUser();
};

class IUAccommodation
{

};

class IServAccommodation
{

};

#endif 