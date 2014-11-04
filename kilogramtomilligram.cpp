#include "kilogramtomilligramconverter.hpp"

#include <string>

kilogramToMilligramConverter::kilogramToMilligramConverter()
{
}

/*In: double value of Kilogram
 *Out: Milligram value of input Kilogram as of 04.11.14
 */
double kilogramToMilligramConverter::convert(double inputKilogram){
  return inputKilogram * 1000000;
}

std::string kilogramToMilligramConverter::toString() const{
  return "Kilogram to Milligram Converter";
}

void kilogramToMilligramConverter::print() const{
  std::cout<<this->toString();
}
