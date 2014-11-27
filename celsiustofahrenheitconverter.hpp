#ifndef CELSIUSTOFAHRENHEITCONVERTER_H
#define CELSIUSTOFAHRENHEITCONVERTER_H

#include "temperatureconverter.hpp"

class celsiusToFahrenheitConverter : public Temperatureconverter
{
  public:
    celsiusToFahrenheitConverter();
    double convert(double inCelsius);
    std::string toString() const;
    void print() const;
    static std::shared_ptr<converter> create();
};

#endif // CELSIUSTOFAHRENHEITCONVERTER_H
