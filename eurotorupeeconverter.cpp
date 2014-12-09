#include "eurotorupeeconverter.hpp"

#include <string>

euroToRupeeConverter::euroToRupeeConverter()
{
}

/*In: double value of euros
 *Out: Rupee value of input Euros as of 04.11.14
 */
double euroToRupeeConverter::convert(double inputEuros){
  
    if(m_to_decorate == nullptr)
		return inputEuros * 76.83;
	else
		return m_to_decorate->convert(inputEuros * 76.83);
}

std::string euroToRupeeConverter::toString() const{
  return "Euro to Rupee Converter";
}

void euroToRupeeConverter::print() const{
  std::cout<<this->toString();
}

std::shared_ptr<converter> euroToRupeeConverter::create()
{
	return std::make_shared<euroToRupeeConverter>();
}