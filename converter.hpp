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
    
#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <string>
#include <memory>

class converter
{
  	public:
	    converter() : m_to_decorate{}, m_min_value{} {}
	    converter(double min_value) : m_to_decorate{}, m_min_value{min_value} {}
	    converter(std::shared_ptr<converter> const& to_decorate, double min_value) : m_to_decorate{to_decorate},m_min_value{min_value}{};
	    virtual double convert(double inValue) = 0;
	    virtual std::string toString() const = 0;
	    virtual void print() const = 0;
	    void link(std::shared_ptr<converter> const& to_decorate);
	    double get_min_value() const;
	protected:
		std::shared_ptr<converter> m_to_decorate;
		double m_min_value;
};

#endif // CONVERTER_H
