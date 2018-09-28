#ifndef	PROJETO_TP1_DOMAIN_H 
#define	PROJETO_TP1_DOMAIN_H

#include <stdexcept>
#include <iostream>

//! Months enum type
/*! Months values begins at 1(January) and end at 12(December)*/
enum Months{kJan=1 ,kFev, kMar, kAbr,kMai, kJun, kJul, kAgo, kSet, kOut, kNov, kDez};

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

//! Accommodation Capacity
/*!
		Receives and validates Accommodation and Capacity number.
*/
class AccommodationCapacity
{
	public:

		//! Constructor
		/*! 
				Initializes Accommodation Capacity and validates its value, 1 digit, between 1-9.

				\param in_value a std::string type.

				\sa AccommodationCapacity::set_value(std::string in_value)	
		*/
		AccommodationCapacity(std::string in_value);

		//!	Set Value function
		/*!
				Sets valid values to a Accommodation capacity, called during its contruction.

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

		//!	Accommodation capacity value's size
		/*!
				Defines Accommodation value following the standard: 1 digit between
				1 to 9. const static int type.
		*/
    const static int kSize_ = 1; 

		//! Accommodation capacity value
		/*!
				1 digit between 1 to 9. std::string type.
		*/
    std::string value_;

		//! Validate function.
		/*!
				Validates the Accommodation capacity value set during its construction.

				\param in_value a std::string type.

				\sa AccommodationCapacity::AccommodationCapacity(std::string in_value)				
		*/
    void validate(std::string in_value); 
 
};
 
inline std::string AccommodationCapacity::get_value()  
{ 
  return (this->value_); 
}

//! Daily Value
/*!
		Receives and validates daily value price.
*/

class DailyValue
{
	public:
		//! Constructor
		/*! 
				Initializes Daily Value and validates its value, between 1.00 to 10'000.00.

				\param in_value a std::string type.

				\sa DailyValue::set_value(std::string in_value)	
		*/
		DailyValue(std::string in_value);

		//!	Set Value function
		/*!
				Sets valid values to a Daily Value, called during its contruction.

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

		//!	Daily value's minor value
		/*!
				Defines major Daily's value possible: 1.00 real. constexpr static double type.
		*/
		constexpr static double kMinorSize_ = 1.00;

		//!	Daily value's major value
		/*!
				Defines minor Daily's value possible: 10'000.00 real. constexpr static double type.
		*/
		constexpr static double kMajorSize_ = 10000.00;

		//!	Daily value's value
		/*!
				Number between 1.00 to 10'000.00. std::string type.
		*/
		std::string value_;

		//!	Validate function.
		/*!
				Validates the Daily value's value set during its construction.

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
				Its follows the months enum standard

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

//! Expiration Date
/*!
		Receives and validates date.
*/
class ExpirationDate
{
	public:

		//! Constructor
		/*!
				Initializes Expiration date and validates its value, following the 
				standards notion(DD/MM), where:

				MM is two digits number between 01 to 12, 
				AA is the month: 00 to 99.

				\param in_value a std::string type.

				\sa ExpirationDate::set_value(std::string in_value)	
		*/
		ExpirationDate(std::string in_value);

		//!	Set Value function
		/*!
				Sets valid values to Expiration Date, called during its contruction.

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
		//! Expiration Date value's size
		/*!	
				Defines Expiration Date's standard size value. const static int value.
		*/
		const static int kSize_ = 5;

		//!	Expiration Date's value
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
				Validates the Expiration Date value set during its construction.

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

class CreditCardNumber
{
	public:
		CreditCardNumber(std::string in_value);
		void set_value(std::string in_value);
		std::string get_value();
	private:
		const static int kSize_ = 16;
		std::string value_;
		void validate(std::string in_value);
};

inline std::string CreditCardNumber::get_value() 
{
	return (this->value_);
}



#endif	// PROJETO_TP1_DOMAIN_H
