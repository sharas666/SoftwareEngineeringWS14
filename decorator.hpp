#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include <vector>
#include "converter.hpp"

class Decorator : public converter
{
	public:
		Decorator() : m_to_decorate{nullptr}{};
		Decorator(std::shared_ptr<converter> new_decorator) : m_to_decorate{new_decorator}{}
		virtual double convert(double inValue);
	private:
		std::shared_ptr<converter> m_to_decorate;
};

#endif //DECORATOR_HPP