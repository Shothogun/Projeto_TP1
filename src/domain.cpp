#include <iostream>
#include "../include/domain.hpp"

Agency::Agency(std::string in_value)
{
  this->set_value(in_value);
}

void Agency::set_value(std::string in_value)
{
  this->validate(in_value);
  this->value_ = in_value;
}

void Agency::validate(std::string in_value)
{
  if(in_value.length() != this->kSize_)
  {
    throw std::invalid_argument("Argumento invalido. Tamanho incorrespondente");
  }

  for(int i = 0; i < this->kSize_; i++)
  {
    if(in_value[i] >'9' or in_value[i]<'0')
    {
      throw std::invalid_argument("Argumento invalido. Digitos invalidos");
    }
  }
}

Bank::Bank(std::string in_value)
{
  this->set_value(in_value);
}

void Bank::set_value(std::string in_value)
{
  this->validate(in_value);
  this->value_ = in_value;
}

void Bank::validate(std::string in_value)
{
  if(in_value.length() != this->kSize_)
  {
    throw std::invalid_argument("Argumento invalido. Tamanho incorrespondente");
  }

  for(int i = 0; i < this->kSize_; i++)
  {
    if(in_value[i] >'9' or in_value[i]<'0')
    {
      throw std::invalid_argument("Argumento invalido. Digitos invalidos");
    }
  }
}

AccommodationCapacity::AccommodationCapacity(std::string in_value)
{
  this->set_value(in_value);
}

void AccommodationCapacity::set_value(std::string in_value)
{
  this->validate(in_value);
  this->value_ = in_value;
}

void AccommodationCapacity::validate(std::string in_value)
{
  if(in_value.length() != this->kSize_)
  {
    throw std::invalid_argument("Argumento invalido. Valor incorrespondente");
  }

  if(in_value[0] < '1' or in_value[0] > '9')
  {
    throw std::invalid_argument("Argumento invalido. Digito invalido");
  }
}