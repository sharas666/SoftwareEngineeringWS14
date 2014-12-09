#include "decorator.hpp"



double Decorator::convert(double inValue)
{
	return convert(m_to_decorate->convert(inValue));


}