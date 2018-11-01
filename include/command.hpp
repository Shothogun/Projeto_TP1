#ifndef PROJETO_TP1_COMMANDS_H
#define PROJETO_TP1_COMMANDS_H

#include "../include/controller.hpp"
#include "../include/domain.hpp"
#include "../include/entity.hpp"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

class CommandIUUser
{
  public:

  // Command service's solicitation method 

  virtual void execute(IServUser) throw(runtime_error) = 0;

  // Virtual destructor method

  virtual ~CommandIUUser(){}
};

class CommandIUUSerInclude:  public CommandIUUser
{
  public:

  // Include service's solicitation method

  void execute(IServUser*) throw(runtime_error);
};

class CommandIUUSerRemove: public CommandIUUser
{
  public:

  // Remove service's solicitation method

  void execute(IServUser*) throw(runtime_error);
};

class CommandIUUSerSeek: public CommandIUUser
{
  public:

  // Seek service's solicitation method

  void execute(IServUser*) throw(runtime_error);
};

class CommandIUUSerUpdate: public CommandIUUser
{
  public:

  // Update service's solicitation method

  void execute(IServUser*) throw(runtime_error);
};
#endif