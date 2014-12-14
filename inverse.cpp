#include "inverse.hpp"
#include "temperatureconverter.hpp"
#include <memory>

double Inverse::convert(double inValue)
{
	if (m_to_decorate)
	{
		if(std::dynamic_pointer_cast<Temperatureconverter>(m_to_decorate))
		{
			std::cout << "temperature not invertable ";
			return 0;
		}
		return inValue * inValue / (m_to_decorate->convert(inValue));
	}
	else
	{
		std::cout << "error" << std::endl;
		return 0;
	}
}

std::string Inverse::toString() const
{
	if (m_to_decorate)
	{
		return "Inverse " + m_to_decorate->toString();
	}
	else
	{
		return "error";
	}
}
   
void Inverse::print() const
{
	std::cout<<this->toString();
}

std::shared_ptr<converter> Inverse::create()
{
	return std::make_shared<Inverse>();
}