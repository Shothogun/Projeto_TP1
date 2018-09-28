#include <iostream>
#include <array>
#include <string>
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
  // --------------------- Verify size ---------------------
  if(in_value.length() != this->kSize_)
  {
    throw std::invalid_argument("Argumento invalido. Tamanho incorrespondente");
  }

  // --------------------- Verify Digits ---------------------
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
  // --------------------- Verify size ---------------------
  if(in_value.length() != this->kSize_)
  {
    throw std::invalid_argument("Argumento invalido. Tamanho incorrespondente");
  }

  // --------------------- Verify Digits ---------------------
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
  // --------------------- Verify size ---------------------
  if(in_value.length() != this->kSize_)
  {
    throw std::invalid_argument("Argumento invalido. Valor incorrespondente");
  }

  // --------------------- Verify digits ---------------------
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

  // --------------------- Verify Digits ---------------------
  for(uint i = 0; i < in_value.length(); i++)
  {
    if((in_value[i] < '0' or in_value[i] > '9') and in_value[i] != '.')
    {
      throw std::invalid_argument("Argumento invalido. Digito invalido");
    }
  }

  double float_in_value = std::stof(in_value);

  // --------------------- Verify range ---------------------
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
  // --------------------- Verify size ---------------------
  if(in_value.length() != 11)
  {
    throw std::invalid_argument("Argumento invalido. Tamanho incorrespondente ao padrao.");
  }

  // --------------------- Verify the '/' character ---------------------
  if(in_value[2] != '/' or in_value[6] != '/')
  {
    throw std::invalid_argument("Argumento invalido. Divisao de data \
                                incorrespondente(verifique o padrao (DD/MMM/AAAA).");
  }

  // Expression in_value is divided in arrays type day, month and year
  std::array<char,2> day = { in_value[0], in_value[1] };
  std::array<char,3> month = { in_value[3], in_value[4], in_value[5]};
  std::array<char,4> year = {in_value[7], in_value[8], in_value[9], in_value[10]};

  // --------------------- Verify Digits ---------------------
  for(uint i = 0; i < day.size(); i++)
  {
    if(day[i] < '0' or day[i] > '9')
    {
      throw std::invalid_argument("Argumento invalido. Formato de dia invalido.");
    }
  }

  for(uint i = 0; i < year.size(); i++)
  {
    if(year[i] < '0' or year[i] > '9')
    {
      throw std::invalid_argument("Argumento invalido. Formato de ano invalido.");
    }
  }

  // Conversion of date to int
  std::string day_string(day.begin(), day.end());
  int day_int = stoi(day_string);

  // --------------------- Verify month value ---------------------
  std::string month_string(month.begin(), month.end());
  int month_int = this->month_validate(month_string);

  this->month_ = month_int;

  std::string year_string(year.begin(), year.end());
  int year_int = stoi(year_string);

  // --------------------- Verify year value ---------------------
  if(year_int < 2000 or year_int > 2099)
    throw std::invalid_argument("Argumento invalido. Ano fora dos limites determinados.");

  this->year_ = year_int;

  // --------------------- Verify day value ---------------------

  this->day_validate(year_int,month_int,day_int);

  this->day_ = day_int;
}

int Date::month_validate(std::string month_in)
{
  // Verifies month according to standart and returns its equivalent 
  // value in int.
  if(month_in == "jan")
  {
    return kJan;
  }

  else if(month_in == "fev")
  {
    return kFev;
  }

  else if(month_in == "mar")
  {
    return kMar;
  }

  else if(month_in == "abr")
  {
    return kAbr;
  }

  else if(month_in == "mai")
  {
    return kMai;
  }
  else if(month_in == "jun")
  {
    return kJun;
  }

  else if(month_in == "jul")
  {
    return kJul;
  }

  else if(month_in == "ago")
  {
    return kAgo;
  }

  else if(month_in == "set")
  {
    return kSet;
  }

  else if(month_in == "out")
  {
    return kOut;
  }

  else if(month_in == "nov")
  {
    return kNov;
  }

  else if(month_in == "dez")
  {
    return kDez;
  }

  else
  {
    throw std::invalid_argument("Argumento invalido. Mes expresso de forma incorreta.");
  }
}

void Date::day_validate(int year_value,int month_value, int day_value)
{
  // --------------------- Leap year correction -------------------------
  int days_per_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

  // February must have 1 more day in leap years
  if((year_value % 4 == 0 and year_value % 100 != 0)  or year_value % 400 == 0)
    days_per_month[kFev-1]++;

  if((month_value == kJan) and (day_value < 1 or day_value > days_per_month[kJan-1]) )
  {
    throw std::invalid_argument("Argumento invalido. Dia invalido(nao existe em Janeiro).");
  }

  if((month_value == kFev) and (day_value < 1 or day_value > days_per_month[kFev-1]) )
  {
    throw std::invalid_argument("Argumento invalido. Dia invalido(nao existe em Fevereiro).");
  }

  if((month_value == kMar) and (day_value < 1 or day_value > days_per_month[kMar-1]) )
  {
    throw std::invalid_argument("Argumento invalido. Dia invalido(nao existe em Março).");
  }

  if((month_value == kAbr) and (day_value < 1 or day_value > days_per_month[kAbr-1]) )
  {
    throw std::invalid_argument("Argumento invalido. Dia invalido(nao existe em Abril).");
  }

  if((month_value == kMai) and (day_value < 1 or day_value > days_per_month[kMai-1]) )
  {
    throw std::invalid_argument("Argumento invalido. Dia invalido(nao existe em Maio).");
  }

  if((month_value == kJun) and (day_value < 1 or day_value > days_per_month[kJun-1]) )
  {
    throw std::invalid_argument("Argumento invalido. Dia invalido(nao existe em Junho).");
  }

  if((month_value == kJul) and (day_value < 1 or day_value > days_per_month[kJul-1]) )
  {
    throw std::invalid_argument("Argumento invalido. Dia invalido(nao existe em Julho).");
  }

  if((month_value == kAgo) and (day_value < 1 or day_value > days_per_month[kAgo-1]) )
  {
    throw std::invalid_argument("Argumento invalido. Dia invalido(nao existe em Agosto).");
  }

  if((month_value == kSet) and (day_value < 1 or day_value > days_per_month[kSet-1]) )
  {
    throw std::invalid_argument("Argumento invalido. Dia invalido(nao existe em Setembro).");
  }

  if((month_value == kOut) and (day_value < 1 or day_value > days_per_month[kOut-1]))
  {
    throw std::invalid_argument("Argumento invalido. Dia invalido(nao existe em Outubro).");
  }

  if((month_value == kNov) and (day_value < 1 or day_value > days_per_month[kNov-1]))
  {
    throw std::invalid_argument("Argumento invalido. Dia invalido(nao existe em Novembro).");
  }

  if((month_value == kDez) and (day_value < 1 or day_value > days_per_month[kDez-1]))
  {
    throw std::invalid_argument("Argumento invalido. Dia invalido(nao existe em Dezembro).");
  }
}

ExpirationDate::ExpirationDate(std::string in_value)
{
  this->set_value(in_value);
}

void ExpirationDate::set_value(std::string in_value)
{
  this->validate(in_value);
  this->value_ = in_value;
}

void ExpirationDate::validate(std::string in_value)
{
  // --------------------- Verify size ---------------------
  if(in_value.length() != 5)
  {
    throw std::invalid_argument("Argumento invalido. Tamanho incorrespondente ao padrao.");
  }

  // --------------------- Verify the '/' character ---------------------
  if(in_value[2] != '/')
  {
    throw std::invalid_argument("Argumento invalido. Divisao de data \
                                incorrespondente, verifique o padrao (MM/AA).");
  }

  std::array<char,2> month = { in_value[0], in_value[1]};
  std::array<char,2> year = {in_value[3], in_value[4]};

  // --------------------- Verify Digits ---------------------
  for(uint i = 0; i < month.size(); i++)
  {
    if(month[i] < '0' or month[i] > '9')
    {
      throw std::invalid_argument("Argumento invalido. Formato de mes invalido.");
    }
  }

  for(uint i = 0; i < year.size(); i++)
  {
    if(year[i] < '0' or year[i] > '9')
    {
      throw std::invalid_argument("Argumento invalido. Formato de ano invalido.");
    }
  }

  std::string year_string(year.begin(), year.end());
  int year_int = stoi(year_string);  
  this->year_ = 2000 + year_int;

  std::string month_string(month.begin(), month.end());
  int month_int = stoi(month_string);

  // --------------------- Verify month value ---------------------

  if(month_int < 1 or month_int > 12)
  {
    throw std::invalid_argument("Argumento invalido. Valor de mes fora do intervalo valido");
  }

  this->month_ = month_int;
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

