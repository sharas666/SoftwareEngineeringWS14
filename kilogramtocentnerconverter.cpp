#include "kilogramtocentnerconverter.hpp"

#include <string>

kilogramToCentnerConverter::kilogramToCentnerConverter()
{
}

/*In: double value of Kilogram
 *Out: Centner value of input Kilogram as of 04.11.14
 */
double kilogramToCentnerConverter::convert(double inputKilogram){
  
    if(m_to_decorate == nullptr)
		return inputKilogram * 0.02;
	else
		return m_to_decorate->convert(inputKilogram * 0.02);
}

std::string kilogramToCentnerConverter::toString() const{
  return "Kilogram to Centner Converter";
}

void kilogramToCentnerConverter::print() const{
  std::cout<<this->toString();
}

std::shared_ptr<converter> kilogramToCentnerConverter::create()
{
	return std::make_shared<kilogramToCentnerConverter>();
}