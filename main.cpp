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
#include "inverse.hpp"
#include "command.hpp"


bool is_digits(const std::string &str)
{
return std::all_of(str.begin(), str.end(), ::isdigit);
}

void run_commands(ConverterFactory* cFactory, std::stringstream &cmd,
                                         std::shared_ptr<converter> const& converter)
{
  std::string next_command;
  cmd >> next_command;
  if(!is_digits(next_command))
  {
    auto new_converter = cFactory->create(next_command);
    if(new_converter != nullptr)
    {
      new_converter->link(converter);
    }
    run_commands(cFactory, cmd, new_converter);
  }
  else
  {
    if(!converter || !cmd.eof())
    {
      std::cout << "<converter type> <inverse> <value>" << std::endl;
    }
    else
    {
      std::cout << converter->convert(stod(next_command)) << std::endl;
    }
  }
}

int main(int argc, char* argv[])
{
  std::deque<Command> commandList{};

  std::string converter_type;
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

