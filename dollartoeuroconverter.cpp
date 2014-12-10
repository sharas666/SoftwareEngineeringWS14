#include "dollartoeuroconverter.hpp"

#include <string>

dollarToEuroConverter::dollarToEuroConverter()
{
}

/*In: double value of dollars
 *Out: Euro value of input dollars as of 19.10.14
 */
double dollarToEuroConverter::convert(double inputDollars){
  

  	if(m_to_decorate == nullptr)
		return inputDollars*0.78224;
	else
		return m_to_decorate->convert(inputDollars*0.78224);
}

std::string dollarToEuroConverter::toString() const{
  return "Dollar to Euro Converter";
}

void dollarToEuroConverter::print() const{
  std::cout<<this->toString();
}

std::shared_ptr<converter> dollarToEuroConverter::create()
{
	return std::make_shared<dollarToEuroConverter>();
}
