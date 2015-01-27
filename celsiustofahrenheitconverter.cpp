/* 
This program is used to convert different temperature,
money and weight units into each other

Copyright (C) 2015 Magdalena Keil, Joshua König
 */

/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "celsiustofahrenheitconverter.hpp"

#include <string>



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
