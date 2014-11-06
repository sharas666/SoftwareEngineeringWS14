#include "celsiustofahrenheitconverter.hpp"

#include <string>

celsiusToFahrenheitConverter::celsiusToFahrenheitConverter()
{
}

/*In: double value of celsius
 *Out: Fahrenheit value of input celsius as of 04.11.14
 */
double celsiusToFahrenheitConverter::convert(double inputCelsius){
  return inputCelsius * 1.8 + 32;
}

std::string celsiusToFahrenheitConverter::toString() const{
  return "Celsius to Fahrenheit Converter";
}

void celsiusToFahrenheitConverter::print() const{
  std::cout<<this->toString();
}
