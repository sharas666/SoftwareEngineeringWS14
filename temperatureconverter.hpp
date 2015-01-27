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
#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include <iostream>
#include <string>
#include "converter.hpp"

class Temperatureconverter : public converter
{
  public:
    Temperatureconverter(double min_value) : converter{min_value}{}
    Temperatureconverter(std::shared_ptr<converter> to_decorate, double min_value) : converter{to_decorate, min_value}{}
    virtual double convert(double inValue) = 0;
    virtual std::string toString() const = 0;
    virtual void print() const = 0;
};

#endif // TEMPERATURECONVERTER_H