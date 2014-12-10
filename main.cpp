#include "celsiustofahrenheitconverter.hpp"
#include "dollartoeuroconverter.hpp"
#include "eurotorupeeconverter.hpp"
#include "fahrenheittokelvinconverter.hpp"
#include "kilogramtomilligramconverter.hpp"
#include "kilogramtocentnerconverter.hpp"
#include "converterFactory.hpp"
#include "decorator.hpp"
#include "inverse.hpp"

int main(int argc, char* argv[])
{
  // std::string input = argv[1];
  // double value = std::stod(argv[2]);

  // ConverterFactory* cFactory;
  // cFactory = cFactory->instance();
  // double output = cFactory->create(input)->convert(value); 
  // std::cout << output << std::endl;


	std::shared_ptr<converter> a = std::make_shared<Inverse>(std::make_shared<dollarToEuroConverter>());
	std::shared_ptr<converter> b = std::make_shared<dollarToEuroConverter>();

	std::cout << b->convert(a->convert(25.12)) << std::endl;
  
  return 0;
}

