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
    
#ifndef CELSIUSTOFAHRENHEITCONVERTER_H
#define CELSIUSTOFAHRENHEITCONVERTER_H

#include "temperatureconverter.hpp"

class celsiusToFahrenheitConverter : public Temperatureconverter
{
  public:
    celsiusToFahrenheitConverter() : Temperatureconverter{-273.15}{};
    celsiusToFahrenheitConverter(std::shared_ptr<converter> to_decorate) : Temperatureconverter{to_decorate, -273.15}{}
    double convert(double inCelsius);
    std::string toString() const;
    void print() const;
    static std::shared_ptr<converter> create();
};

#endif // CELSIUSTOFAHRENHEITCONVERTER_H
