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
    
#ifndef CONVERTERFACTORY_H
#define CONVERTERFACTORY_H

#include <memory>
#include "converter.hpp"
#include <map>
#include <functional>

class ConverterFactory
{
  public:
    std::shared_ptr<converter> create(std::string const&);
    static ConverterFactory* instance();

  private:
    ConverterFactory();
    static ConverterFactory* s_instance;
    std::map<std::string, std::function<std::shared_ptr<converter>()>> m;
};



#endif // CONVERTERFACTORY_H
