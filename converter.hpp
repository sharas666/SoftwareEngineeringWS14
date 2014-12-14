#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <string>
#include <memory>

class converter
{
  	public:
    converter() : m_to_decorate{} {}
    converter(std::shared_ptr<converter> const& to_decorate) : m_to_decorate{to_decorate}{};
	    virtual double convert(double inValue) = 0;
	    virtual std::string toString() const = 0;
	    virtual void print() const = 0;
	    void link(std::shared_ptr<converter> const& to_decorate);
	protected:
		std::shared_ptr<converter> m_to_decorate;
};

#endif // CONVERTER_H
