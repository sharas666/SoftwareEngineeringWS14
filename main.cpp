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

