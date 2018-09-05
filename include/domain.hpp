#ifndef	PROJETO_TP1_DOMAIN_H 
#define	PROJETO_TP1_DOMAIN_H

#include <string>

// Declaração de classe

class Agency
{
	public:
	void set_value(std::string in_value);

	private:

		const static int kSize_ = 5;
		std::string value_;
		
};


#endif	// PROJETO_TP1_DOMAIN_H
