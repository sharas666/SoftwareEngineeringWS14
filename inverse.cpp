#include "inverse.hpp"
#include "temperatureconverter.hpp"
#include <memory>

double Inverse::convert(double inValue)
{
	if(/*std::shared_ptr<Temperatureconverter> to_check = */std::dynamic_pointer_cast<Temperatureconverter>(m_to_decorate))
	{
		std::cout << "temperature not invertable" << std::endl;
		return 0;
	}
	return inValue * (1 / (m_to_decorate->convert(inValue) / inValue));
}

std::string Inverse::toString() const
{
	return "Inverse " + m_to_decorate->toString();
}
   
void Inverse::print() const
{
	std::cout<<this->toString();
}