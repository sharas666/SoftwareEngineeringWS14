#include "celsiustofahrenheitconverter.hpp"
#include "dollartoeuroconverter.hpp"
#include "eurotorupeeconverter.hpp"
#include "fahrenheittokelvinconverter.hpp"
#include "kilogramtomilligramconverter.hpp"
#include "kilogramtocentnerconverter.hpp"

int main(int argc, char* argv[])
{
  std::string conversion = argv[1];
  std::string value = argv[2];

  if (conversion == "DollarToEuro")
  {
    dollarToEuroConverter* myConverter = new dollarToEuroConverter();
    double aLotOfDollars = std::stod(value);
    double aLotOfEuros = myConverter->convert(aLotOfDollars);
    std::cout << myConverter->toString() << " has converted "<< aLotOfDollars << " Dollar to " << aLotOfEuros <<" Euros!"<<std::endl;
  }

  else if (conversion == "EuroToRupee")
  {
    euroToRupeeConverter* myConverter = new euroToRupeeConverter();
    double aLotOfEuros = std::stod(value);
    double aLotOfRupees = myConverter->convert(aLotOfEuros);
    std::cout << myConverter->toString() << " has converted "<< aLotOfEuros << " Euro to " << aLotOfRupees <<" Rupees!"<<std::endl;
  }

  /*
   * TODO
   *
   * use desired conversion here
   *
  */

  
  return 0;
}

