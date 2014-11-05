#include "celsiustofahrenheitconverter.hpp"
#include "dollartoeuroconverter.hpp"
#include "eurotorupeeconverter.hpp"
#include "fahrenheittokelvinconverter.hpp"
#include "kilogramtomilligramconverter.hpp"
#include "kilogramtocentnerconverter.hpp"

int main(int argc, char* argv[])
{
  std::string conversion = argv[0];
  double value = std::stod(argv[1]);

  if (conversion == "DollarToEuro")
  {
    dollarToEuroConverter* myConverter = new dollarToEuroConverter();
    double aLotOfDollars = value;
    double aLotOfEuros = myConverter->convert(aLotOfDollars);
    std::cout << myConverter->toString() << " has converted "<< aLotOfDollars << " Dollar to " << aLotOfEuros <<" Euros!"<<std::endl;
  }

  /*
   * TODO
   *
   * use desired conversion here
   *
  */

  
  return 0;
}

