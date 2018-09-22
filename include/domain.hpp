#ifndef	PROJETO_TP1_DOMAIN_H 
#define	PROJETO_TP1_DOMAIN_H

#include <stdexcept>
#include <iostream>

// Class declaration

//! Agency
/*! 
 * 	Receive and validates Agency number.
!*/

class Agency
{
	public:

	// Access methods

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
			Returns Agency value.
		*/
		std::string get_value();

	private:

		//! Agency value's size
		/*!	
				Defines Agency's standard value. Const static int value.
		*/
		const static int kSize_ = 5;

		//!	Agency value
		/*!
				It's a sequence of 5 digits(XXXXX) between 0-9. String value.
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

	// Access methods

		/*! Constructor

				Initializes Bank and validates its value, following the 
				standards notion(XXX), all digits between 0 and 9).

				\param in_value a std::string type.

				\sa Bank::set_value(std::string in_value)	
		*/
		Bank(std::string in_value);

		/*!	Set Value function

				Sets valid values to a Bank, called during its contruction.

				\param in_value a std::string type.

				\sa Bank::validate(std::string in_value)
		*/
		void set_value(std::string in_value);


		/*! Get Value function

			Returns Bank value.

		*/
		std::string get_value();

	private:

		/*!	Bank value's size

				Defines Bank's standard value.
		*/
		const static int kSize_ = 3;

		/*!	Bank value

				It's a sequence of 3 digits(XXX) between 0-9.
		*/
		std::string value_;
		/*!	Validate function.

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
		/*! Constructor

				Initializes Accommodation Capacity and validates its value, 1 digit, between 1-9.

				\param in_value a std::string type.

				\sa AccommodationCapacity::set_value(std::string in_value)	
		*/
		AccommodationCapacity(std::string in_value);
		void set_value(std::string in_value);
		std::string get_value();

	private:
		const static int kSize_ = 1;
		std::string value_;
		void validate(std::string in_value);

};

inline std::string AccommodationCapacity::get_value() 
{
	return (this->value_);
}

#endif	// PROJETO_TP1_DOMAIN_H
