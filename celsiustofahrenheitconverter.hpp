#ifndef CELSIUSTOFAHRENHEITCONVERTER_H
#define CELSIUSTOFAHRENHEITCONVERTER_H

#include "temperatureconverter.hpp"

class celsiusToFahrenheitConverter : public Temperatureconverter
{
  public:
    celsiusToFahrenheitConverter() : Temperatureconverter{-273.15}{};
    celsiusToFahrenheitConverter(std::shared_ptr<converter> to_decorate) : Temperatureconverter{to_decorate, -273.15}{}
    double convert(double inCelsius);
    std::string toString() const;
    void print() const;
    static std::shared_ptr<converter> create();
};

#endif // CELSIUSTOFAHRENHEITCONVERTER_H
