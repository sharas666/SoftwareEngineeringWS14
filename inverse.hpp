#ifndef INVERSE_HPP
#define INVERSE_HPP

#include "converter.hpp"

class Inverse : public converter
{
	public:
		Inverse() : converter{0}{}
		Inverse(std::shared_ptr<converter> to_invert) : converter{to_invert, 0}{}
		double convert(double inValue);
	    std::string toString() const;
	    void print() const;
	    static std::shared_ptr<converter> create();
	
};

#endif //INVERSE_HPP