#ifndef FAHRENHEITTOKELVINCONVERTER_H
#define FAHRENHEITTOKELVINCONVERTER_H

#include "temperatureconverter.hpp"

class fahrenheitToKelvinConverter : public Temperatureconverter
{
  public:
    fahrenheitToKelvinConverter();
    double convert(double inFahrenheit);
    std::string toString() const;
    void print() const;
};

#endif // FAHRENHEITTOKELVINCONVERTER_H