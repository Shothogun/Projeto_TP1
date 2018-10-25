#ifndef PROJETO_TP1_CONTROLLER_HPP
#define PROJETO_TP1_CONTROLLER_HPP

#include "../include/domain.hpp"
#include "../include/interfaces.hpp"


using namespace std;

class CntrIUAuthentication : public IUAuthentication
{
  public:
    int autenticar();
    void setCntrServAuthentication(IServAuthentication*);

  private:
    IServAuthentication* cntr_serv_authentication_;
};

void inline CntrIUAuthentication::setCntrServAuthentication(IServAuthentication* cntr_serv_authentication)
{
  this->cntr_serv_authentication_= cntr_serv_authentication; 
};

#endif