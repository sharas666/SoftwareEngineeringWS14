#include "kilogramtocentnerconverter.hpp"

#include <string>

kilogramToCentnerConverter::kilogramToCentnerConverter()
{
}

/*In: double value of Kilogram
 *Out: Centner value of input Kilogram as of 04.11.14
 */
double kilogramToCentnerConverter::convert(double inputKilogram){
  return inputKilogram*1;
}

std::string kilogramToCentnerConverter::toString() const{
  return "Kilogram to Centner Converter";
}

void kilogramToCentnerConverter::print() const{
  std::cout<<this->toString();
}
