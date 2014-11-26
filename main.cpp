#include "celsiustofahrenheitconverter.hpp"
#include "dollartoeuroconverter.hpp"
#include "eurotorupeeconverter.hpp"
#include "fahrenheittokelvinconverter.hpp"
#include "kilogramtomilligramconverter.hpp"
#include "kilogramtocentnerconverter.hpp"
#include "converterFactory.hpp"

int main(int argc, char* argv[])
{
  std::string input = argv[1];
  double value = std::stod(argv[2]);

  ConverterFactory* cFactory;
  cFactory = cFactory->instance();
  double output = cFactory->create(input)->convert(value); 
  std::cout << output << std::endl;
  
  return 0;
}

