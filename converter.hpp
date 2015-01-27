#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <string>
#include <memory>

class converter
{
  	public:
	    converter() : m_to_decorate{}, m_min_value{} {}
	    converter(double min_value) : m_to_decorate{}, m_min_value{min_value} {}
	    converter(std::shared_ptr<converter> const& to_decorate, double min_value) : m_to_decorate{to_decorate},m_min_value{min_value}{};
	    virtual double convert(double inValue) = 0;
	    virtual std::string toString() const = 0;
	    virtual void print() const = 0;
	    void link(std::shared_ptr<converter> const& to_decorate);
	    double get_min_value() const;
	protected:
		std::shared_ptr<converter> m_to_decorate;
		double m_min_value;
};

#endif // CONVERTER_H
