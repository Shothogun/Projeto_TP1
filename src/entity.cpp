#include "../include/entity.hpp"
#include "../include/domain.hpp"


User::User()
{
  this->name_ = NULL;
  this->identifier_ = NULL;
  this->password_ = NULL;
}

Accommodation::Accommodation()
{
  this->identifier_ = NULL;
  this->accommodation_type_ = NULL;
  this->accommodation_capacity_ = NULL;
  this->begin_date_ = NULL;
  this->end_date_ = NULL;
  this->state_ = NULL;
  this->daily_ = NULL;
}


CreditCard::CreditCard()
{
  this->number_ = NULL;
  this->expiration_ = NULL;
}

Account::Account()
{
  this->number_ = NULL;
  this->agency_ = NULL;
  this->bank_ = NULL;
}



