#include "celsiustofahrenheitconverter.hpp"

#include <string>

celsiusToFahrenheitConverter::celsiusToFahrenheitConverter()
{
}

/*In: double value of celsius
 *Out: Fahrenheit value of input celsius as of 04.11.14
 */
double celsiusToFahrenheitConverter::convert(double inputCelsius){

   	if(m_to_decorate == nullptr)
		return inputCelsius * 1.8 + 32;
	else
		return m_to_decorate->convert(inputCelsius) * 1.8 + 32;
}

std::string celsiusToFahrenheitConverter::toString() const{
	if(m_to_decorate)
  		return m_to_decorate->toString() +" Celsius to Fahrenheit Converter ";
  	else
  		return " Celsius to Fahrenheit Converter ";
}

void celsiusToFahrenheitConverter::print() const{
  std::cout<<this->toString();
}

std::shared_ptr<converter> celsiusToFahrenheitConverter::create()
{
	return std::make_shared<celsiusToFahrenheitConverter>();
}
