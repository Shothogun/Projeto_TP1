#ifndef	PROJETO_TP1_DOMAIN_H 
#define	PROJETO_TP1_DOMAIN_H

#include <stdexcept>
#include <iostream>

// Class declaration

/*! \class Agency
 * 
 * 	Receive and validates Agency number
!*/

class Agency
{
	public:

	// Access methods

		/*! Constructor

				Initializes Agency and validates its value, following the 
				standards notion(XXXXX, all digits between 0 and 9).

				\sa set_value(std::string in_value)	
		*/
		Agency(std::string in_value);

		/*!	Set Value function

				Sets valid values to a Agency, called during its contruction.

				\sa Agency::validate(std::string in_value)
		*/
		void set_value(std::string in_value);
		std::string get_value();

	private:

		const static int kSize_ = 5;
		std::string value_;
		void validate(std::string in_value);
		
};

inline std::string Agency::get_value() 
{
	return (this->value_);
}

class Bank
{
	public:

	// Access methods

		Bank(std::string in_value);
		void set_value(std::string in_value);
		std::string get_value();

	private:

		const static int kSize_ = 3;
		std::string value_;
		void validate(std::string in_value);
		
};

inline std::string Bank::get_value() 
{
	return (this->value_);
}

class AccommodationCapacity
{
	public:
		AccommodationCapacity(std::string in_value);
		void set_value(std::string in_value);
		std::string get_value();

};

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
