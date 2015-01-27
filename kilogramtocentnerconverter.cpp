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
#include "kilogramtocentnerconverter.hpp"

#include <string>

/*In: double value of Kilogram
 *Out: Centner value of input Kilogram as of 04.11.14
 */
double kilogramToCentnerConverter::convert(double inputKilogram){
  
    if(m_to_decorate == nullptr)
		return inputKilogram * 0.02;
	else
		return m_to_decorate->convert(inputKilogram) * 0.02;
}

std::string kilogramToCentnerConverter::toString() const{
	if(m_to_decorate)
  		return m_to_decorate->toString() +" Kilogram to Centner Converter ";
  	else
  		return " Kilogram to Centner Converter ";
}

void kilogramToCentnerConverter::print() const{
  std::cout<<this->toString();
}

std::shared_ptr<converter> kilogramToCentnerConverter::create()
{
	return std::make_shared<kilogramToCentnerConverter>();
}