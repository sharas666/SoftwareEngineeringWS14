#include <deque>
#include <sstream>

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

int main(int argc, char* argv[])
{
  // std::string input = argv[1];
  // double value = std::stod(argv[2]);

  // ConverterFactory* cFactory;
  // cFactory = cFactory->instance();
  // double output = cFactory->create(input)->convert(value); 
  // std::cout << output << std::endl;

 
  std::deque<Command> commandList{};
  std::string cmd;
  int value;

  for(std::string line; std::getline(std::cin, line);)
  {
    std::stringstream str{line};
    str >> cmd >> value;

    std::cout << line << std::endl;
    commandList.push_back({cmd,value});
  }

  ConverterFactory* cFactory;
  cFactory = cFactory->instance();


  for(auto i : commandList)
  {
    std::cout << cFactory->create(i.m_command)->convert(i.m_value) << std::endl;
  }



	std::shared_ptr<converter> a = std::make_shared<Inverse>(std::make_shared<dollarToEuroConverter>());
	std::shared_ptr<converter> b = std::make_shared<dollarToEuroConverter>();
  std::shared_ptr<converter> c = std::make_shared<Inverse>(std::make_shared<celsiusToFahrenheitConverter>());

 //  std::cout << b->convert(a->convert(25.12)) << std::endl;
	// std::cout << c->convert(25.12) << std::endl;
  
  return 0;
}

