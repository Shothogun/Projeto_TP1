#ifndef	PROJETO_TP1_DOMAIN_H 
#define	PROJETO_TP1_DOMAIN_H

#include <stdexcept>
#include <iostream>

// Declaração de classe

class Agency
{
	public:

	// Métodos de acesso 

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




#endif	// PROJETO_TP1_DOMAIN_H
