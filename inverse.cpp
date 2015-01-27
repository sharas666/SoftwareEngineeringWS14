#include "inverse.hpp"
#include "temperatureconverter.hpp"
#include <memory>
#include <stdexcept>

double Inverse::convert(double inValue)
{
	try
	{
		if(!m_to_decorate)
		{
			throw std::runtime_error("\n nothing to decorate\n <converter> inverse <value>\n");
		}
		if(std::dynamic_pointer_cast<Temperatureconverter>(m_to_decorate))
		{
			throw std::runtime_error("\n temperature not invertable\n");
		}
		return inValue * inValue / (m_to_decorate->convert(inValue));
	}
	catch(std::exception & e)
	{
	  std::cout << e.what() << "\n";
	}
}

std::string Inverse::toString() const
{
	return "Inverse " + m_to_decorate->toString();
}
   
void Inverse::print() const
{
	std::cout<<this->toString();
}

std::shared_ptr<converter> Inverse::create()
{
	return std::make_shared<Inverse>();
}