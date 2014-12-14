#include "kilogramtomilligramconverter.hpp"

#include <string>

kilogramToMilligramConverter::kilogramToMilligramConverter()
{
}

/*In: double value of Kilogram
 *Out: Milligram value of input Kilogram as of 04.11.14
 */
double kilogramToMilligramConverter::convert(double inputKilogram){

    if(m_to_decorate == nullptr)
		return inputKilogram * 1000000;
	else
		return m_to_decorate->convert(inputKilogram) * 1000000;
}

std::string kilogramToMilligramConverter::toString() const{
  return "Kilogram to Milligram Converter";
}

void kilogramToMilligramConverter::print() const{
  std::cout<<this->toString();
}

std::shared_ptr<converter> kilogramToMilligramConverter::create()
{
	return std::make_shared<kilogramToMilligramConverter>();
}