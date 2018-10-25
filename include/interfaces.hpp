#ifndef PROJETO_TP1_INTERFACES_HPP
#define PROJETO_TP1_INTERFACEX_HPP

#include <stdexcept>
#include "../include/domain.hpp"
#include "../include/entity.hpp"


using namespace std;

class IUAuthentication
{
  public:
    virtual int authenticate() = 0;
    virtual void setCntrServAutenticate(IServAuthentication *server) = 0;
    virtual ~IUAuthentication(){};
};

class IServAuthentication
{
  public:
    virtual int authenticate(const Identifier&, const Password&) = 0;
    virtual ~IServAuthentication();
};

class IUAccommodation;
class IServAccommodation;

#endif 