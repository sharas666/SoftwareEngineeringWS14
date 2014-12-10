#include <deque>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <string>

#include "celsiustofahrenheitconverter.hpp"
#include "dollartoeuroconverter.hpp"
#include "eurotorupeeconverter.hpp"
#include "fahrenheittokelvinconverter.hpp"
#include "kilogramtomilligramconverter.hpp"
#include "kilogramtocentnerconverter.hpp"
#include "converterFactory.hpp"
#include "decorator.hpp"
#include "inverse.hpp"
#include "command.hpp"


bool is_digits(const std::string &str)
{
return std::all_of(str.begin(), str.end(), ::isdigit);
}

int main(int argc, char* argv[])
{
  // std::string input = argv[1];
  // double value = std::stod(argv[2]);

  // ConverterFactory* cFactory;
  // cFactory = cFactory->instance();
  // double output = cFactory->create(input)->convert(value); 
  // std::cout << output << std::endl;

 
  std::deque<Command> commandList{};

  std::string converter_type;
  std::string value;

  for(std::string line; std::getline(std::cin, line);)
  {
    std::stringstream cmd{line};  
    cmd >> converter_type >> value;

    if(is_digits(value))
    {
      commandList.push_back({converter_type, stod(value)});      
    }
    else
    {
      std::cout << "<converter type> <value>" << std::endl;
      return 0;
    }
  }

  ConverterFactory* cFactory;
  cFactory = cFactory->instance();

  std::shared_ptr<converter> new_converter;

  for(auto i : commandList)
  {
      new_converter = cFactory->create(i.m_command);
      if(new_converter)
      {
        std::cout << new_converter->convert(i.m_value) << std::endl;
      }
  }
  return 0;
}

