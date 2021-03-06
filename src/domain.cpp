#include <iostream>
#include <array>
#include <string>
#include <algorithm>
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
    throw std::invalid_argument("Agencia invalido. Tamanho incorrespondente");
  }

  // --------------------- Verify Digits ---------------------
  for(int i = 0; i < this->kSize_; i++)
  {
    if(in_value[i] >'9' or in_value[i]<'0')
    {
      throw std::invalid_argument("Agencia invalido. Digitos invalidos");
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
    throw std::invalid_argument("Banco invalido. Tamanho incorrespondente");
  }

  // --------------------- Verify Digits ---------------------
  for(int i = 0; i < this->kSize_; i++)
  {
    if(in_value[i] >'9' or in_value[i]<'0')
    {
      throw std::invalid_argument("Banco invalido. Digitos invalidos");
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
    throw std::invalid_argument("Capacidade invalido. Valor incorrespondente");
  }

  // --------------------- Verify digits ---------------------
  if(in_value[0] < '1' or in_value[0] > '9')
  {
    throw std::invalid_argument("Capacidade invalido. Digito invalido");
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
      throw std::invalid_argument("Diaria invalido. Digito invalido");
    }
  }

  double float_in_value = std::stof(in_value);

  // --------------------- Verify range ---------------------
  if(float_in_value < this->kMinorSize_)
  {
    throw std::invalid_argument("Diaria invalido. Valor de diaria menor que o padrao");
  }

  else if (float_in_value > this->kMajorSize_)
  {
    throw std::invalid_argument("Diaria invalido. Valor de diaria maior que o padrao");
  }

  this->dayly_ = float_in_value;
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
    throw std::invalid_argument("Data invalido. Tamanho incorrespondente ao padrao.");
  }

  // --------------------- Verify the '/' character ---------------------
  if(in_value[2] != '/' or in_value[6] != '/')
  {
    throw std::invalid_argument("Data invalido. Divisao de data \
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
      throw std::invalid_argument("Data invalido. Formato de dia invalido.");
    }
  }

  for(uint i = 0; i < year.size(); i++)
  {
    if(year[i] < '0' or year[i] > '9')
    {
      throw std::invalid_argument("Data invalido. Formato de ano invalido.");
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
    throw std::invalid_argument("Data invalido. Ano fora dos limites determinados.");

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
    throw std::invalid_argument("Data invalido. Mes expresso de forma incorreta.");
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
    throw std::invalid_argument("Data invalido. Dia invalido(nao existe em Janeiro).");
  }

  if((month_value == kFev) and (day_value < 1 or day_value > days_per_month[kFev-1]) )
  {
    throw std::invalid_argument("Data invalido. Dia invalido(nao existe em Fevereiro).");
  }

  if((month_value == kMar) and (day_value < 1 or day_value > days_per_month[kMar-1]) )
  {
    throw std::invalid_argument("Data invalido. Dia invalido(nao existe em Março).");
  }

  if((month_value == kAbr) and (day_value < 1 or day_value > days_per_month[kAbr-1]) )
  {
    throw std::invalid_argument("Data invalido. Dia invalido(nao existe em Abril).");
  }

  if((month_value == kMai) and (day_value < 1 or day_value > days_per_month[kMai-1]) )
  {
    throw std::invalid_argument("Data invalido. Dia invalido(nao existe em Maio).");
  }

  if((month_value == kJun) and (day_value < 1 or day_value > days_per_month[kJun-1]) )
  {
    throw std::invalid_argument("Data invalido. Dia invalido(nao existe em Junho).");
  }

  if((month_value == kJul) and (day_value < 1 or day_value > days_per_month[kJul-1]) )
  {
    throw std::invalid_argument("Data invalido. Dia invalido(nao existe em Julho).");
  }

  if((month_value == kAgo) and (day_value < 1 or day_value > days_per_month[kAgo-1]) )
  {
    throw std::invalid_argument("Data invalido. Dia invalido(nao existe em Agosto).");
  }

  if((month_value == kSet) and (day_value < 1 or day_value > days_per_month[kSet-1]) )
  {
    throw std::invalid_argument("Data invalido. Dia invalido(nao existe em Setembro).");
  }

  if((month_value == kOut) and (day_value < 1 or day_value > days_per_month[kOut-1]))
  {
    throw std::invalid_argument("Data invalido. Dia invalido(nao existe em Outubro).");
  }

  if((month_value == kNov) and (day_value < 1 or day_value > days_per_month[kNov-1]))
  {
    throw std::invalid_argument("Data invalido. Dia invalido(nao existe em Novembro).");
  }

  if((month_value == kDez) and (day_value < 1 or day_value > days_per_month[kDez-1]))
  {
    throw std::invalid_argument("Data invalido. Dia invalido(nao existe em Dezembro).");
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
    throw std::invalid_argument("Data de validade invalido. Tamanho incorrespondente ao padrao.");
  }

  // --------------------- Verify the '/' character ---------------------
  if(in_value[2] != '/')
  {
    throw std::invalid_argument("Data de validade invalido. Divisao de data \
                                incorrespondente, verifique o padrao (MM/AA).");
  }

  std::array<char,2> month = { in_value[0], in_value[1]};
  std::array<char,2> year = {in_value[3], in_value[4]};

  // --------------------- Verify Digits ---------------------
  for(uint i = 0; i < month.size(); i++)
  {
    if(month[i] < '0' or month[i] > '9')
    {
      throw std::invalid_argument("Data de validade invalido. Formato de mes invalido.");
    }
  }

  for(uint i = 0; i < year.size(); i++)
  {
    if(year[i] < '0' or year[i] > '9')
    {
      throw std::invalid_argument("Data de validade invalido. Formato de ano invalido.");
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
    throw std::invalid_argument("Data de validade invalido. Valor de mes fora do intervalo valido");
  }

  this->month_ = month_int;
}

State::State(std::string in_value)
{
  this->set_value(in_value);
}

void State::set_value(std::string in_value)
{
  this->state_ = this->validate(in_value);
  this->value_ = in_value;
}

StateName State::validate(std::string in_value)
{
  if(in_value == "AC")
  {
    return StateName::AC;
  }

  else if(in_value == "AL")
  {
    return StateName::AL;
  }

  else if(in_value == "AP")
  {
    return StateName::AP;
  }

  else if(in_value == "AM")
  {
    return StateName::AM;
  }

  else if(in_value == "BA")
  {
   return StateName::BA; 
  }

  else if(in_value == "CE")
  {
    return StateName::CE;
  }

  else if(in_value == "DF")
  {
    return StateName::DF;
  }

  else if(in_value == "ES")
  {
    return StateName::ES;
  }

  else if(in_value == "GO")
  {
    return StateName::GO;
  }

  else if(in_value == "MA")
  {
    return StateName::MA;
  }

  else if(in_value == "MT")
  {
    return StateName::MT;
  }

  else if(in_value == "MS")
  {
    return StateName::MS;
  }

  else if(in_value == "MG")
  {
    return StateName::MG;
  }

  else if(in_value == "PA")
  {
    return StateName::PA;
  }

  else if(in_value == "PB")
  {
    return StateName::PB;
  }

  else if(in_value == "PR")
  {
    return StateName::PR;
  }

  else if(in_value == "PE")
  {
    return StateName::PE;
  }

  else if(in_value == "PI")
  {
    return StateName::PI;
  }

  else if(in_value == "RJ")
  {
    return StateName::RJ;
  }

  else if(in_value == "RN")
  {
    return StateName::RN;
  }

  else if(in_value == "RS")
  {
    return StateName::RS;
  }

  else if(in_value == "RO")
  {
    return StateName::RO;
  }

  else if(in_value == "RR")
  {
    return StateName::RR;
  }

  else if(in_value == "SC")
  {
    return StateName::SC;
  }

  else if(in_value == "SP")
  {
    return StateName::SP;
  }

  else if(in_value == "SE")
  {
    return StateName::SE;
  }

  else if(in_value == "TO")
  {
    return StateName::TO;
  }

  else
  {
    throw std::invalid_argument("Argumento invalido. Estado inserido invalido.");
  }
}

Identifier::Identifier(std::string in_value)
{
  this->set_value(in_value);
}

void Identifier::set_value(std::string in_value)
{
  this->validate(in_value);
  this->value_ = in_value;
}

void Identifier::validate(std::string in_value)
{
  // --------------------- Verify size ---------------------
  if(in_value.length() != this->kSize_)
  {
    throw std::invalid_argument("Identificador invalido. Tamanho incorrespondente");
  }

  // --------------------- Verify Digits ---------------------
  for(uint i=0; i < in_value.length() ; i++)
  {
    if(in_value[i] < 'a' or in_value[i] > 'z')
    {
      throw std::invalid_argument("Identificador invalido. Dígito nao é letra minúscula");
    }
  }
}

Name::Name(std::string in_value)
{
   this->set_value(in_value);
}

void Name::set_value(std::string in_value)
{
  this->validate(in_value);
  this->value_ = in_value;
}

void Name::validate(std::string in_value)
{
  // --------------------- Verify size ---------------------
  if(in_value.length() != this->kSize_)
  {
    throw std::invalid_argument("Nome invalido. Tamanho incorrespondente");
  }

  const int first = 0;
  bool at_least_one_letter = false;

  // --------------------- Verify Digits ---------------------
  for(uint i = 0; i < in_value.length(); i++)
  {
    // Verify character
    if((in_value[i] < 'a' or in_value[i] > 'z') and (in_value[i] != '.' and in_value[i] != ' '))
    {
      if((in_value[i] < 'A' or in_value[i] > 'Z'))
      {
        throw std::invalid_argument("Nome invalido. Digito incorrespondente com o padrão");
      }
    }

    if((in_value[i] >= 'a' and in_value[i] <= 'z') or (in_value[i] >= 'A' and in_value[i] <= 'Z'))
    {
      at_least_one_letter = true;
    }

    // Dot is the first character
    if(in_value[i] == '.' and i == first)
    {
      throw std::invalid_argument("Nome invalido. Primeiro caracter é um '.', verifique o padrão");
    }

    // --------------------- Verify dot value ---------------------
    else if(in_value[i] == '.' and i != first)
    {
      if(in_value[i-1] < 'a' or in_value[i-1] > 'z')
      {
        if(in_value[i-1] < 'A' or in_value[i-1] > 'Z')
        {
          throw std::invalid_argument("Nome invalido. '.' não precedido por uma letra, verifique o padrão");
        }
      }
    }

    // Verify double space
    if(in_value[i] == ' ' and i != first)
    {
      if(in_value[i-1] == ' ')
      {
        throw std::invalid_argument("Nome invalido. Duplo espaço, verifique o padrão");
      } 
    } 
  } // for
  
  if(at_least_one_letter == false)
  {
    throw std::invalid_argument("Nome invalido. Não há uma letra no nome, verifique o padrão");
  }
}

CreditCardNumber::CreditCardNumber(std::string in_value)
{
  this->set_value(in_value);
}

void CreditCardNumber::set_value(std::string in_value)
{
	this->validate(in_value);
	this->value_ = in_value;
}

void CreditCardNumber::validate(std::string in_value)
{
  // --------------------- Verify size ---------------------
	if(in_value.length() != this->kSize_)
  {
    throw std::invalid_argument("Cartão de Crédito invalido. Tamanho incorrespondente");
  }

  // --------------------- Verify Digits ---------------------
	for(int i = 0; i < this->kSize_; i++)
  {
    if(in_value[i] >'9' or in_value[i]<'0')
    {
      throw std::invalid_argument("Cartão de Crédito invalido. Digitos invalidos");
    }
  }

  // --------------------- Luhn Algorithm ---------------------

  int sum = 0;
  int digit_int = 0;
  int parity = 0;

  for (int i = in_value.length()-1 ; i >= 0; i--)
  {
    parity = in_value.length() - i;
    std::string digit = in_value.substr(i,1);
    digit_int = stoi(digit);

    if(parity%2 == 0)
    {
      digit_int *= 2;
      if(digit_int > 9)
      {
        digit_int = digit_int%10 + 1;
      }
    }

    sum += digit_int; 
  }

  if(sum % 10 != 0)
  {
    throw std::invalid_argument("Cartão de Crédito invalido. Numero não encontrado");
  } 
}

AccountNumber::AccountNumber(std::string in_value)
{
  this->set_value(in_value);
}

void AccountNumber::set_value(std::string in_value)
{
  this->validate(in_value);
  this->value_ = in_value;
}

void AccountNumber::validate(std::string in_value)
{
  // --------------------- Verify size ---------------------
  if(in_value.length() != this->kSize_)
  {
    throw std::invalid_argument("Conta corrente invalido. Tamanho incorrespondente");
  }

  // --------------------- Verify Digits ---------------------
  for(int i = 0; i < this->kSize_; i++)
  {
    if(in_value[i] >'9' or in_value[i]<'0')
    {
      throw std::invalid_argument("Conta corrente invalido. Digitos invalidos");
    }
  }
}

Password::Password(std::string in_value)
{
  this->set_value(in_value);
}

void Password::set_value(std::string in_value)
{
  this->validate(in_value);
  this->value_ = in_value;
}

void Password::validate(std::string in_value)
{
  // --------------------- Verify size ---------------------
  if(in_value.length() != this->kSize_)
  {
    throw std::invalid_argument("Senha invalida. Tamanho incorrespondente");
  }

  const int first = 0;
  bool at_least_one_upper_case = false;
  bool at_least_one_lower_case = false;
  bool at_least_one_digit = false;
  bool at_least_one_special = false;

  // Sorting to verify doubled character
  std::string sorted_in_value = in_value;
  std::sort(sorted_in_value.begin(), sorted_in_value.end());

  for(uint i = 0; i < sorted_in_value.length(); i++)
  {
    // Initialize valid_character as false(verify if character follows the standard,
    // in positive valid_character = true).

    bool valid_character = false;

    if(sorted_in_value[i] >= 'a' and sorted_in_value[i] <= 'z')
    {
      at_least_one_lower_case = true;
      valid_character = true;
    }

    if(sorted_in_value[i] >= 'A' and sorted_in_value[i] <= 'Z')
    {
      at_least_one_upper_case = true;
      valid_character = true;
    }

    if(sorted_in_value[i] >= '0' and sorted_in_value[i] <= '9')
    {
      at_least_one_digit = true;
      valid_character = true;
    }

    if(sorted_in_value[i] == '!' or sorted_in_value[i] == '#' or sorted_in_value[i] == '$' or 
       sorted_in_value[i] == '%' or sorted_in_value[i] == '&')
    {
      at_least_one_special = true;
      valid_character = true;
    }

    // --------------------- Verify Digits ---------------------
    
    if(valid_character == false)
    {
      throw std::invalid_argument("Senha invalida. Caractere invalido, verifique o padrão");
    }
    
    // --------------------- Verify dublicated characters ---------------------

    if(i != first)
    {
      if(sorted_in_value[i] == sorted_in_value[i-1])
      {
        throw std::invalid_argument("Senha invalida. Caracteres repetidos, verifique o padrão");
      }
    }
  } // for

  // --------------------- Verify required characters ---------------------
  if(at_least_one_digit == false)
  {
    throw std::invalid_argument("Senha invalida. Falta um dígito numero na senha, verifique o padrão");
  }

  if(at_least_one_lower_case == false)
  {
    throw std::invalid_argument("Senha invalida. Falta um dígito letra minúscula na senha, verifique o padrão");
  }

  if(at_least_one_upper_case == false)
  {
    throw std::invalid_argument("Senha invalida. Falta um dígito letra maiúscula na senha, verifique o padrão");
  }

  if(at_least_one_special == false)
  {
    throw std::invalid_argument("Senha invalida. Falta um caractere especial na senha, verifique o padrão");
  }
}

AccommodationType::AccommodationType(std::string in_value)
{
  this->set_value(in_value);
}

void AccommodationType::set_value(std::string in_value)
{
  this->accommodation_type_ = this->validate(in_value);
  this->value_ = in_value;
}

AccommodationOption AccommodationType::validate(std::string in_value)
{
  if(in_value == "Apartamento")
  {
    return AccommodationOption::Apartamento;
  }

  else if(in_value == "Casa")
  {
    return AccommodationOption::Casa;
  }

  else if(in_value == "Flat")
  {
    return AccommodationOption::Flat;
  }

  else
  {
    throw std::invalid_argument("Tipo de acomodação inválida. Tamanho incorrespondente");
  }
}
