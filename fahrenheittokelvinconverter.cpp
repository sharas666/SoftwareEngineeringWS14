#include "fahrenheittokelvinconverter.hpp"

#include <string>


/*In: double value of fahrenheit
 *Out: Kelvin value of input fahrenheit as of 04.11.14
 */
double fahrenheitToKelvinConverter::convert(double inputFahrenheit){

	if(m_to_decorate == nullptr)
		return (inputFahrenheit + 459.67) / 1.8;
	else
		return (m_to_decorate->convert(inputFahrenheit) + 459.67) / 1.8;
}

std::string fahrenheitToKelvinConverter::toString() const{
	if(m_to_decorate)
  		return m_to_decorate->toString() +" Fahrenheit to Kelvin Converter ";
  	else
  		return " Fahrenheit to Kelvin Converter ";
}

void fahrenheitToKelvinConverter::print() const{
  std::cout<<this->toString();
}

std::shared_ptr<converter> fahrenheitToKelvinConverter::create()
{
	return std::make_shared<fahrenheitToKelvinConverter>();
}