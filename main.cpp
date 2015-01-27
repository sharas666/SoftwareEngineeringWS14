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
/*
 Contact us at magdalena.keil@uni-weimar.de or joshua.david.koenig@uni-weimar.de
 */


#include <deque>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <string>
#include <stdexcept>

#include "celsiustofahrenheitconverter.hpp"
#include "dollartoeuroconverter.hpp"
#include "eurotorupeeconverter.hpp"
#include "fahrenheittokelvinconverter.hpp"
#include "kilogramtomilligramconverter.hpp"
#include "kilogramtocentnerconverter.hpp"
#include "converterFactory.hpp"
#include "inverse.hpp"
#include "command.hpp"


bool is_digits(const std::string &str)
{
  if(str[0] == '-')
  {
    return std::all_of(str.begin()+1, str.end(), ::isdigit);
  }
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

void run_commands(ConverterFactory* cFactory, std::stringstream &cmd,
                                         std::shared_ptr<converter> const& converter)
{
  std::string next_command;
  cmd >> next_command;
  if(!is_digits(next_command))
  { // wenn keine ziffern
    auto new_converter = cFactory->create(next_command);
    if(new_converter != nullptr)
    {
      new_converter->link(converter);
    }
    run_commands(cFactory, cmd, new_converter);
  }
  else
  {
    try
    {
      if(next_command.empty())
      {
        throw std::runtime_error("\n no value to convert\n"); 
      }
      if(!cmd.eof())
      {
        throw std::runtime_error("\n can only convert one value\n");
      }
      if(!converter)
      {
        throw std::runtime_error("\n converter does not exist\n");
      }
      if (stod(next_command) < converter->get_min_value())
      {
        throw std::runtime_error("\n value out of range\n");
      }
      std::cout << converter->convert(stod(next_command)) << std::endl;
    }
    catch(std::exception & e)
    {
      std::cout << e.what() << "\n";
    }
  }
}

int main(int argc, char* argv[])
{
  std::cout << "\n";
  std::cout << "Copyright (C) 2015 Magdalena Keil, Joshua König\n";
  std::cout << "This program comes with ABSOLUTELY NO WARRANTY;\n";
  std::cout << "This is free software, and you are welcome to redistribute it";
  std::cout << "under certain conditions;\n\n";
  std::cout << "<converter> [inverse / <converter> ...] <value>\n";
  std::cout << "converter: ctof, dtoe, etor, ftok, ktom, ktoc\n";
  std::deque<Command> commandList{};
  std::string value;

  for(std::string line; std::getline(std::cin, line);)
  {
    commandList.push_back({line});   
  }

  ConverterFactory* cFactory;
  cFactory = cFactory->instance();

  for(auto i : commandList)
  {
    std::stringstream cmd{i.m_command};
    run_commands(cFactory, cmd, nullptr);
  }
  return 0;
}

