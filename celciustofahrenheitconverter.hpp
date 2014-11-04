#ifndef CELSIUSTOFAHRENHEITCONVERTER_H
#define CELSIUSTOFAHRENHEITCONVERTER_H

#include "Moneyconverter.hpp"

class celsiusToFahrenheitConverter : public Moneyconverter
{
  public:
    celsiusToFahrenheitConverter();
    double convert(double inCelsius);
    std::string toString() const;
    void print() const;
};

#endif // CELSIUSTOFAHRENHEITCONVERTER_H
