#ifndef INVERSE_HPP
#define INVERSE_HPP

#include "decorator.hpp"

class Inverse : public Decorator
{
	public:
		Inverse(std::shared_ptr<converter> to_invert) : Decorator{to_invert}{}
		double convert(double inValue);
	    std::string toString() const;
	    void print() const;
	
};

#endif //INVERSE_HPP