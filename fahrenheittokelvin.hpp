#ifndef FAHRENHEITTOKELVINCONVERTER_H
#define FAHRENHEITTOKELVINCONVERTER_H

#include "Moneyconverter.hpp"

class fahrenheitToKelvinConverter : public Moneyconverter
{
  public:
    fahrenheitToKelvinConverter();
    double convert(double inFahrenheit);
    std::string toString() const;
    void print() const;
};

#endif // FAHRENHEITTOKELVINCONVERTER_H
