#include <iostream>
#include "../include/domain.hpp"

void Agency::set_value(std::string in_value)
{
  this->validate(in_value);
  this->value_ = in_value;
}

void Agency::validate(std::string in_value)
{
  if(in_value.length() != this->kSize_)
  {
    throw std::invalid_argument("Argumento invalido.");
  }
}

