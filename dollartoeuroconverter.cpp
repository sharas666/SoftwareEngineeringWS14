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
    
#include "dollartoeuroconverter.hpp"

#include <string>



/*In: double value of dollars
 *Out: Euro value of input dollars as of 19.10.14
 */
double dollarToEuroConverter::convert(double inputDollars){
  

  	if(m_to_decorate == nullptr)
		return inputDollars*0.78224;
	else
		return m_to_decorate->convert(inputDollars)*0.78224;
}

std::string dollarToEuroConverter::toString() const{
	if(m_to_decorate)
  		return m_to_decorate->toString() +" Dollar to Euro Converter ";
  	else
  		return " Dollar to Euro Converter ";
}

void dollarToEuroConverter::print() const{
  std::cout<< this->toString();
}

std::shared_ptr<converter> dollarToEuroConverter::create()
{
	return std::make_shared<dollarToEuroConverter>();
}
