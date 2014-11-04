#include "fahrenheittokelvinconverter.hpp"

#include <string>

fahrenheitToKelvinConverter::fahrenheitToKelvinConverter()
{
}

/*In: double value of fahrenheit
 *Out: Kelvin value of input fahrenheit as of 04.11.14
 */
double fahrenheitToKelvinConverter::convert(double inputFahrenheit){
  return (inputFahrenheit + 459.67) / 1.8;
}

std::string fahrenheitToKelvinConverter::toString() const{
  return "Fahrenheit to Kelvin Converter";
}

void fahrenheitToKelvinConverter::print() const{
  std::cout<<this->toString();
}
