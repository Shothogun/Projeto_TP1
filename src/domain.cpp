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

DailyValue::DailyValue(std::string in_value)
{
  this->set_value(in_value);
}

void DailyValue::set_value(std::string in_value)
{
  this->validate(in_value);
  this->value_ = in_value;
}

void DailyValue::validate(std::string in_value)
{
  for(int i = 0; i < in_value.length(); i++)
  {
    if((in_value[i] < '0' or in_value[i] > '9') and in_value[i] != '.')
    {
      throw std::invalid_argument("Argumento invalido. Digito invalido");
    }
  }

  double float_in_value = std::stof(in_value);


  if(float_in_value < this->kMinorSize_)
  {
    throw std::invalid_argument("Argumento invalido. Valor de diaria menor que o padrao");
  }

  else if (float_in_value > this->kMajorSize_)
  {
    throw std::invalid_argument("Argumento invalido. Valor de diaria maior que o padrao");
  }  
}

Date::Date(std::string in_value)
{
  this->set_value(in_value);
}

void Date::set_value(std::string in_value)
{
  this->validate(in_value);
  this->value_ = in_value;
}

void Date::validate(std::string in_value)
{

}

void CreditCardNumber::set_value(std::string in_value)
{
	this->validate(in_value);
	this->value_ = in_value;
}
void CreditCardNumber::validate(std::string in_value)
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
  // needs refactoring
    int nSum = 0, isSecond = false;
    for (int i = in_value.length() - 1; i >= 0; i--) {
 
        int d = in_value[i] - 'a';
 
        if (isSecond == true) {
            d = d * 2;
        }
 
        // We add two digits to handle
        // cases that make two digits after
        // doubling
        nSum += d / 10;
        nSum += d % 10;
 
        isSecond = !isSecond;
    }
    if (nSum % 10 != 0)
    {
      throw std::invalid_argument("Argumento invalido. Número de cartão inválido");
    }
    
}

