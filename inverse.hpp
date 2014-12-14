#ifndef INVERSE_HPP
#define INVERSE_HPP

#include "converter.hpp"

class Inverse : public converter
{
	public:
		Inverse() : converter{}{}
		Inverse(std::shared_ptr<converter> to_invert) : converter{to_invert}{}
		double convert(double inValue);
	    std::string toString() const;
	    void print() const;
	    static std::shared_ptr<converter> create();
	
};

#endif //INVERSE_HPP