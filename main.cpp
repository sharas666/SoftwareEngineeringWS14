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
    double valueDollars = std::stod(value);
    double valueEuros = myConverter->convert(valueDollars);
    std::cout << myConverter->toString() << " has converted "<< valueDollars << " Dollar to " << valueEuros <<" Euros!"<<std::endl;
  }

  else if (conversion == "EuroToRupee")
  {
    euroToRupeeConverter* myConverter = new euroToRupeeConverter();
    double valueEuros = std::stod(value);
    double valueRupees = myConverter->convert(valueEuros);
    std::cout << myConverter->toString() << " has converted "<< valueEuros << " Euro to " << valueRupees <<" Rupees!"<<std::endl;
  }

  else if (conversion == "CelsiusToFahrenheit")
  {
    celsiusToFahrenheitConverter* myConverter = new celsiusToFahrenheitConverter();
    double valueCelsius = std::stod(value);
    double valueFahrenheit = myConverter->convert(valueCelsius);
    std::cout << myConverter->toString() << " has converted "<< valueCelsius << " Celsius to " << valueFahrenheit <<" Fahrenheit!"<<std::endl;
  }

  else if (conversion == "FahrenheitToKelvin")
  {
    fahrenheitToKelvinConverter* myConverter = new fahrenheitToKelvinConverter();
    double valueFahrenheit = std::stod(value);
    double valueKelvin = myConverter->convert(valueFahrenheit);
    std::cout << myConverter->toString() << " has converted "<< valueFahrenheit << " Fahrenheit to " << valueKelvin <<" Kelvin!"<<std::endl;
  }

  else if (conversion == "KilogramToMilligram")
  {
    kilogramToMilligramConverter* myConverter = new kilogramToMilligramConverter();
    double valueKilogram = std::stod(value);
    double valueMilligram = myConverter->convert(valueKilogram);
    std::cout << myConverter->toString() << " has converted "<< valueKilogram << " Kilogram to " << valueMilligram <<" Milligram!"<<std::endl;
  }

  else if (conversion == "KilogramToCentner")
  {
    kilogramToCentnerConverter* myConverter = new kilogramToCentnerConverter();
    double valueKilogram = std::stod(value);
    double valueCentner = myConverter->convert(valueKilogram);
    std::cout << myConverter->toString() << " has converted "<< valueKilogram << " Kilogram to " << valueCentner <<" Centner!"<<std::endl;
  }

  
  return 0;
}

