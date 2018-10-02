#ifndef	PROJETO_TP1_DOMAIN_H 
#define	PROJETO_TP1_DOMAIN_H

#include <stdexcept>
#include <iostream>

//! Months enum type
/*! Months values begins at 1(January) and end at 12(December)*/
enum Months{kJan=1 ,kFev, kMar, kAbr,kMai, kJun, kJul, kAgo, kSet, kOut, kNov, kDez};

//! StateName enum type

enum class StateName{AC, AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, 
							 MG, PA, PB, PR, PE, PI, RJ, RN, RS, RO, RR, SC, SP, SE, TO};

//! AccommodationOption enum type

enum class AccommodationOption{Apartamento, Casa, Flat};

// Class declaration

//! Agency
/*! 
 * 	Receive and validates Agency number.
!*/
class Agency
{
	public:

		//! Constructor
		/*! 
				Initializes Agency and validates its value, following the 
				standards notion(XXXXX, all digits between 0 and 9).

				\param in_value a std::string type

				\sa Agency::set_value(std::string in_value)	
		*/
		Agency(std::string in_value);

		//! Set Value function
		/*!	
				Sets valid values to a Agency, called during its contruction.

				\param in_value a std::string type.

				\sa Agency::validate(std::string in_value)
		*/
		void set_value(std::string in_value);

		//! Get Value function
		/*! 
			Returns Agency value. std::string type.
		*/
		std::string get_value();

	private:

		//! Agency value's size
		/*!	
				Defines Agency's standard size value. const static int value.
		*/
		const static int kSize_ = 5;

		//!	Agency value
		/*!
				It's a sequence of 5 digits(XXXXX) between 0-9. std::string type.
		*/
		std::string value_;

		//! Validate function.
		/*!	
				Validates the Agency value set during its construction.

				\param in_value a std::string type.

				\sa Agency::Agency(std::string in_value)				
		*/
		void validate(std::string in_value);
		
};

inline std::string Agency::get_value() 
{
	return (this->value_);
}

//! Bank
/*!
 * 	Receive and validates Bank number.
!*/
class Bank
{
	public:

		//! Constructor
		/*!
				Initializes Bank and validates its value, following the 
				standards notion(XXX), all digits between 0 and 9).

				\param in_value a std::string type.

				\sa Bank::set_value(std::string in_value)	
		*/
		Bank(std::string in_value);

		//! Set Value function
		/*!	
				Sets valid values to a Bank, called during its contruction.

				\param in_value a std::string type.

				\sa Bank::validate(std::string in_value)
		*/
		void set_value(std::string in_value);

		//! Get Value function
		/*! 
				Returns Bank value. std::string type
		*/
		std::string get_value();

	private:

		//! Bank value's size
		/*!	
				Defines Bank's standard size value. const static int type.
		*/
		const static int kSize_ = 3;

		//! Bank value
		/*!	
				It's a sequence of 3 digits(XXX) between 0-9. std::string type.
		*/
		std::string value_;

		//! Validate function
		/*!
				Validates the Bank value set during its construction.

				\param in_value a std::string type.

				\sa Bank::Bank(std::string in_value)				
		*/
		void validate(std::string in_value);
};

inline std::string Bank::get_value() 
{
	return (this->value_);
}

//! AccommodationCapacity
/*!
		Receives and validates Accommodation and Capacity number.
*/
class AccommodationCapacity
{
	public:

		//! Constructor
		/*! 
				Initializes AccommodationCapacity and validates its value, 1 digit, between 1-9.

				\param in_value a std::string type.

				\sa AccommodationCapacity::set_value(std::string in_value)	
		*/
		AccommodationCapacity(std::string in_value);

		//!	Set Value function
		/*!
				Sets valid values to a AccommodationCapacity, called during its contruction.

				\param in_value a std::string type.

				\sa AccommodationCapacity::validate(std::string in_value)
		*/
		void set_value(std::string in_value);

		//! Get Value function
		/*!
				Returns value. std::string type.
		*/
		std::string get_value();

  private: 

		//!	AccommodationCapacity value's size
		/*!
				Defines Accommodation value following the standard: 1 digit between
				1 to 9. const static int type.
		*/
    const static int kSize_ = 1; 

		//! AccommodationCapacity value
		/*!
				1 digit between 1 to 9. std::string type.
		*/
    std::string value_;

		//! Validate function.
		/*!
				Validates the AccommodationCapacity value set during its construction.

				\param in_value a std::string type.

				\sa AccommodationCapacity::AccommodationCapacity(std::string in_value)				
		*/
    void validate(std::string in_value); 
 
};
 
inline std::string AccommodationCapacity::get_value()  
{ 
  return (this->value_); 
}

//! DailyValue
/*!
		Receives and validates daily value price.
*/

class DailyValue
{
	public:
		//! Constructor
		/*! 
				Initializes DailyValue and validates its value, between 1.00 to 10'000.00.

				\param in_value a std::string type.

				\sa DailyValue::set_value(std::string in_value)	
		*/
		DailyValue(std::string in_value);

		//!	Set Value function
		/*!
				Sets valid values to a DailyValue, called during its contruction.

				\param in_value a std::string type.

				\sa DailyValue::validate(std::string in_value)
		*/
		void set_value(std::string in_value);

		//! Get Value function
		/*! 
				Returns value. std::string type.
		*/
		std::string get_value();

	private:

		//!	DailyValue's minor value
		/*!
				Defines major Daily's value possible: 1.00 real. constexpr static double type.
		*/
		constexpr static double kMinorSize_ = 1.00;

		//!	DailyValue's major value
		/*!
				Defines minor Daily's value possible: 10'000.00 real. constexpr static double type.
		*/
		constexpr static double kMajorSize_ = 10000.00;

		//!	DailyValue's value
		/*!
				Number between 1.00 to 10'000.00. std::string type.
		*/
		std::string value_;

		//!	daily_'s value
		/*!
				Number between 1.00 to 10'000.00. float type.
		*/
		float dayly_;


		//!	Validate function.
		/*!
				Validates the DailyValue's value set during its construction.

				\param in_value a std::string type.

				\sa DailyValue::DailyValue(std::string in_value)				
		*/
		void validate(std::string in_value_);
};

inline std::string DailyValue::get_value()
{
	return (this->value_);
}

//! Date
/*!
		Receives and validates date.
*/
class Date
{
	public:

		//! Constructor
		/*!
				Initializes date and validates its value, following the 
				standards notion(DD/MMM/AAAA), where:

				DD is two digits number between 01 to 31, 
				MMM is the month: jan,fev, mar, abr, mai, jun, jul, ago, set, out, nov or dez.
				AAAA is a year: 2000 to 2099, considering Leap years.

				\param in_value a std::string type.

				\sa Date::set_value(std::string in_value)	
		*/
		Date(std::string in_value);

		//!	Set Value function
		/*!
				Sets valid values to Date, called during its contruction.

				\param in_value a std::string type.

				\sa Date::validate(std::string in_value)
		*/
		void set_value(std::string in_value);

		//! Get Value function
		/*!
				Returns value. std::string type.
		*/
		std::string get_value();

		//! Get day function
		/*!
				Returns day value. int type.
		*/
		int get_day();

		//! Get month function
		/*!
				Returns month value. int type.
		*/
		int get_month();

		//! Get year function
		/*!
				Returns year value. int type.
		*/
		int get_year();

	private:
		//! Date value's size
		/*!	
				Defines Date's standard size value. const static int value.
		*/
		const static int kSize_ = 11;

		//!	Date's value
		/*!
				It's a sequence of 11 characters(DD/MMM/AAAA) between 0-9. std::string value.
		*/
		std::string value_;

		//!	Day's value
		/*!
				Value depends on month and leap year. int type.
		*/
		int day_;

		//!	Month's value
		/*!
				Value between 1 to 12. int type.
		*/
		int month_;

		//!	Year's value
		/*!
				Value between 2000 to 2099. int type.
		*/
		int year_;

		//! Validate function.
		/*!	
				Validates the Date value set during its construction.

				\param in_value a std::string type.

				\sa Date::Date(std::string in_value)				
		*/
		void validate(std::string in_value);

		//! Month Validate function.
		/*!	
				Validates the Date's month value set during its construction.
				It follows the months enum standard.
				Returns a month equivalent, int type.

				\param month_in a std::string type.

				\sa Months			
		*/
		int month_validate(std::string month_in);

		//! Day Validate function.
		/*!	
				Validates the day value in a certain month of certain year.
				Verifies if the leap year.

				\param year_value a int type.
				\param month_value a int type.
				\param day_value a int type.

				\sa Months			
		*/
		void day_validate(int year_value,int month_value, int day_value);

};

inline std::string Date::get_value()
{
	return (this->value_);
}

inline int Date::get_day()
{
	return (this->day_);
}

inline int Date::get_month()
{
	return (this->month_);
}

inline int Date::get_year()
{
	return (this->year_);
}

//! ExpirationDate
/*!
		Receives and validates date.
*/
class ExpirationDate
{
	public:

		//! Constructor
		/*!
				Initializes ExpirationDate and validates its value, following the 
				standards notion(DD/MM), where:

				MM is two digits number between 01 to 12, 
				AA is the month: 00 to 99.

				\param in_value a std::string type.

				\sa ExpirationDate::set_value(std::string in_value)	
		*/
		ExpirationDate(std::string in_value);

		//!	Set Value function
		/*!
				Sets valid values to ExpirationDate, called during its contruction.

				\param in_value a std::string type.

				\sa Date::validate(std::string in_value)
		*/
		void set_value(std::string in_value);

		//! Get Value function
		/*!
				Returns value. std::string type.
		*/
		std::string get_value();

		//! Get month function
		/*!
				Returns month value. int type.
		*/
		int get_month();

		//! Get year function
		/*!
				Returns year value. int type.
		*/
		int get_year();

	private:
		//! ExpirationDate value's size
		/*!	
				Defines ExpirationDate's standard size value. const static int value.
		*/
		const static int kSize_ = 5;

		//!	ExpirationDate's value
		/*!
				It's a sequence of 5 characters(MM/AA) between 0-9. std::string value.
		*/
		std::string value_;

		//!	Month's value
		/*!
				Value between 1 to 12. int type.
		*/
		int month_;

		//!	Year's value
		/*!
				Value between 2000 to 2099. int type.
		*/
		int year_;

		//! Validate function.
		/*!	
				Validates the ExpirationDate value set during its construction.

				It's important to note that the only way year input is invalid is 
				in the case which the in_value has a length lesser than 5 and 
				its digits is not a number, as every possible two number digits is satisfied 
				in the standard(0 to 99). Therefore, the particular year substring value is not required 
				to be check, in contrast to month(01 to 12).
				
				\param in_value a std::string type.

				\sa ExpirationDate::ExpirationDate(std::string in_value)				
		*/
		void validate(std::string in_value);
};

inline int ExpirationDate::get_month()
{
	return (this->month_);
}

inline int ExpirationDate::get_year()
{
	return (this->year_);
}

//! State
/*!
		Receives and validates state.
*/
class State
{
	public:
		//! Constructor
		/*!
				Initializes State and validates its value according to its initials.

				\param in_value a std::string type.

				\sa State::set_value(std::string in_value)	
		*/
		State(std::string in_value);

		//!	Set Value function
		/*!
				Sets valid values to State, called during its contruction.

				\param in_value a std::string type.

				\sa State::validate(std::string in_value)
		*/
		void set_value(std::string in_value);

		//! Get Value function
		/*!
				Returns value. std::string type.
		*/
		std::string get_value();

		//! Get state function
		/*!
				Returns state value. enum class StateName type.

				\sa StateName
		*/
		StateName get_state();

	private:
		//! State string's size
		/*!	
				Defines State's standard size value. const static int value.
		*/
		const static int kSize_ = 2;

		//!	State's value
		/*!
				It's a sequence of 2 characters. Express the initials of 
				brazilian states. std::string value.
		*/
		std::string value_;

		//!	state's value
		/*!
				enum class StateName type.

				\sa StateName
		*/
		StateName state_;

		//! Validate function.
		/*!	
				Validates the State value set during its construction.
				Returns a StateName type.

				\param in_value a std::string type.

				\sa StateName::StateName(std::string in_value)
				\sa StateName			
		*/
		StateName validate(std::string in_value);
};

inline std::string State::get_value()
{
	return (this->value_);
}

inline StateName State::get_state()
{
	return (this->state_);
}

//! Identifier
/*!
		Receives and validates identifier.
*/
class Identifier
{
	public:
		//! Constructor
		/*!
				Initializes Identifier and validates following the 
				standards notion(XXXXX, all lowe-case letters a-z).

				\param in_value a std::string type.

				\sa Identifier::set_value(std::string in_value)	
		*/
		Identifier(std::string in_value);

		//!	Set Value function
		/*!
				Sets valid values to Identifier, called during its contruction.

				\param in_value a std::string type.

				\sa Identifier::validate(std::string in_value)
		*/
		void set_value(std::string in_value);

		//! Get Value function
		/*!
				Returns value. std::string type.
		*/
		std::string get_value();

	private:

		//! Identifier's size
		/*!	
				Defines Identifier's standard size value. const static int value.
		*/
		const static int kSize_ = 5;

		//!	Identifier value
		/*!
				It's a sequence of 5 letter(XXXXX) lower-case. std::string type.
		*/
		std::string value_;

		//! Validate function.
		/*!	
				Validates the Identifier value set during its construction.

				\param in_value a std::string type.

				\sa Identifier::Identifier(std::string in_value)				
		*/
		void validate(std::string in_value);
};

inline std::string Identifier::get_value()
{
	return (this->value_);
}

//! Name
/*!
		Receives and validates Name.
*/
class Name
{
	public:
		//! Constructor
		/*!
				Initializes Name and validates following the 
				standards notion(XXXXXXXXXXXXXXX), each X is a letter, space or dot.
				It's forbidden adjacents spaces and before a dot there always a letter. 

				\param in_value a std::string type.

				\sa Name::set_value(std::string in_value)	
		*/
		Name(std::string in_value);

		//!	Set Value function
		/*!
				Sets valid values to Name, called during its contruction.

				\param in_value a std::string type.

				\sa Name::validate(std::string in_value)
		*/
		void set_value(std::string in_value);

		//! Get Value function
		/*!
				Returns value. std::string type.
		*/
		std::string get_value();

	private:
		//! Name's size
		/*!	
				Defines Name's standard size value. const static int value.
		*/
		const static int kSize_ = 15;

		//!	Name value
		/*!
				It's a sequence of 15 letter(XXXXXXXXXXXXXXX), dot and space. std::string type.
		*/
		std::string value_;

		//! Validate function.
		/*!	
				Validates the Name value set during its construction.
				It's a string of 15 characters, letter, dots and spaces.

				It's not allowed:

				- Name with less or greater than 15 characters.

				- Name with dot not preceded of letter.

				- Name with double space.

				- Name without a character.

				Note: It's important to note that if the name not contains a letter,
				the only possible way of fill it is with dot and space. However, 
				if the name starts with a dot 2th rule is violated. So, it must start 
				with a space. But, following to the next character, the only possible 
				character is a dot, either it would be double spaced. At this point, 
				the dot would violate the 2th rule. Neither possible characters different from
				a letter is possible. Therefore, a name without a letter would automaticaly sufficient
				forbid with the 3 first rules, since either would be violated.

				\param in_value a std::string type.

				\sa Name::Name(std::string in_value)				
		*/
		void validate(std::string in_value);
};

inline std::string Name::get_value()
{
	return (this->value_);
}

//! CreditCardNumber
/*!
		Receives and validates Credit card number.
*/
class CreditCardNumber
{
	public:

		//! Constructor
		/*! 
				Initializes CreditCardNumber and validates its value, following the 
				standards notion(XXXXXXXXXXXXXXXX, all digits between 0 and 9), and validation test.

				\param in_value a std::string type

				\sa CreditCardNumber::set_value(std::string in_value)	
		*/
		CreditCardNumber(std::string in_value);

		//! Set Value function
		/*!	
				Sets valid values to a CreditCardNumber, called during its contruction.

				\param in_value a std::string type.

				\sa CreditCardNumber::validate(std::string in_value)
		*/
		void set_value(std::string in_value);

		//! Get Value function
		/*! 
			Returns CreditCardNumber value. std::string type.
		*/
		std::string get_value();

	private:

		//! CreditCardNumber value's size
		/*!	
				Defines CreditCardNumber's standard size value. const static int value.
		*/
		const static int kSize_ = 16;
		
		//!	CreditCardNumber value
		/*!
				It's a sequence of 16 digits(XXXXXX) between 0-9. std::string type.
		*/		
		std::string value_;

		//! Validate function.
		/*!	
				Validates the CreditCardNumber value set during its construction, following the 
				Luhn's algorithm test

				\param in_value a std::string type.

				\sa CreditCardNumber::CreditCardNumber(std::string in_value)				
		*/
		void validate(std::string in_value);
};

inline std::string CreditCardNumber::get_value() 
{
	return (this->value_);
}

//! AccountNumber
/*!
		Receives and validates Account's number.
*/
class AccountNumber
{
	public:

		//! Constructor
		/*! 
				Initializes AccountNumber and validates its value, following the 
				standards notion(XXXXXX, all digits between 0 and 9).

				\param in_value a std::string type

				\sa AccountNumber::set_value(std::string in_value)	
		*/
		AccountNumber(std::string in_value);

		//! Set Value function
		/*!	
				Sets valid values to a AccountNumber, called during its contruction.

				\param in_value a std::string type.

				\sa AccountNumber::validate(std::string in_value)
		*/
		void set_value(std::string in_value);

		//! Get Value function
		/*! 
			Returns AccountNumber value. std::string type.
		*/
		std::string get_value();

	private:

		//! AccountNumber value's size
		/*!	
				Defines AccountNumber's standard size value. const static int value.
		*/
		const static int kSize_ = 6;

		//!	AccountNumber value
		/*!
				It's a sequence of 6 digits(XXXXXX) between 0-9. std::string type.
		*/
		std::string value_;

		//! Validate function.
		/*!	
				Validates the AccountNumber value set during its construction.

				\param in_value a std::string type.

				\sa AccountNumber::AccountNumber(std::string in_value)				
		*/
		void validate(std::string in_value);
};

inline std::string AccountNumber::get_value() 
{
	return (this->value_);
}


//! Password
/*!
		Receives and validates Password.
*/
class Password
{
	public:
		//! Constructor
		/*!
				Initializes Password and validates following the 
				standards notion(XXXXXXXX), each X is a letter, special character (! # $ % &),
				and number (0 to 9).

				\param in_value a std::string type.

				\sa Password::set_value(std::string in_value)	
		*/
		Password(std::string in_value);

		//!	Set Value function
		/*!
				Sets valid values to Password, called during its contruction.

				\param in_value a std::string type.

				\sa Password::validate(std::string in_value)
		*/
		void set_value(std::string in_value);

		//! Get Value function
		/*!
				Returns value. std::string type.
		*/
		std::string get_value();

	private:
		//! Password's size
		/*!	
				Defines Password's standard size value. const static int value.
		*/
		const static int kSize_ = 8;

		//!	Identifier value
		/*!
				It's a sequence of 8 letter(XXXXXXXX), special character (! # $ % &),
				and number (0 to 9). std::string type.
		*/
		std::string value_;

		//! Validate function.
		/*!	
				Validates the Password value set during its construction.
				It's a string of 8 characters, letter, special character and number.

				It's not allowed:

				- Repeated character.

				It must at least have:

				- One Upper case letter

				- One Lower case letter

				- One number

				- One Special character

				\param in_value a std::string type.

				\sa Password::Password(std::string in_value)				
		*/
		void validate(std::string in_value);
};

inline std::string Password::get_value()
{
	return (this->value_);
}

//! AccommodationType
/*! 
 * 	Receive and validates AccommodationType number.
!*/
class AccommodationType
{
	public:

		//! Constructor
		/*! 
				Initializes AccommodationType and validates its value, a Apartamento
				Casa or Flat.

				\param in_value a std::string type

				\sa AccommodationType::set_value(std::string in_value)	
		*/
		AccommodationType(std::string in_value);

		//! Set Value function
		/*!	
				Sets valid values to a AccommodationType, called during its contruction.

				\param in_value a std::string type.

				\sa AccommodationType::validate(std::string in_value)
		*/
		void set_value(std::string in_value);

		//! Get Value function
		/*! 
			Returns AccommodationType value. std::string type.
		*/
		std::string get_value();

		//! Get Value function
		/*! 
			Returns AccommodationType enum value. enum class AccommodationOption type.
		*/
		AccommodationOption get_accommodation_type();

	private:
		//!	AccommodationType value
		/*!
				It's only three options: "Apartamento", "Casa" or "Flat". std::string type.
		*/
		std::string value_;

		//!	AccommodationType value
		/*!
				It's only three options: AccommodationType::Apartamento, 
				AccommodationType::Casa or AccommodationType::Flat. std::string type.
		*/
		AccommodationOption accommodation_type_;

		//! Validate function.
		/*!	
				Validates the AccommodationType value set during its construction.

				Returns a AccommodationType variable.

				\param in_value a std::string type.

				\sa AccommodationType::AccommodationType(std::string in_value)				
		*/
		AccommodationOption validate(std::string in_value);
		
};

inline std::string AccommodationType::get_value() 
{
	return (this->value_);
}

inline AccommodationOption AccommodationType::get_accommodation_type() 
{
	return (this->accommodation_type_);
}

#endif	// PROJETO_TP1_DOMAIN_H
