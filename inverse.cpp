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
#include "inverse.hpp"
#include "temperatureconverter.hpp"
#include <memory>
#include <stdexcept>

double Inverse::convert(double inValue)
{
	try
	{
		if(!m_to_decorate)
		{
			throw std::runtime_error("\n nothing to decorate\n <converter> inverse <value>\n");
		}
		if(std::dynamic_pointer_cast<Temperatureconverter>(m_to_decorate))
		{
			throw std::runtime_error("\n temperature not invertable\n");
		}
		return inValue * inValue / (m_to_decorate->convert(inValue));
	}
	catch(std::exception & e)
	{
	  std::cout << e.what() << "\n";
	}
}

std::string Inverse::toString() const
{
	return "Inverse " + m_to_decorate->toString();
}
   
void Inverse::print() const
{
	std::cout<<this->toString();
}

std::shared_ptr<converter> Inverse::create()
{
	return std::make_shared<Inverse>();
}