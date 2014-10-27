#ifndef DOLLARTOEUROCONVERTER_H
#define DOLLARTOEUROCONVERTER_H

#include "Moneyconverter.hpp"

class dollarToEuroConverter : public Moneyconverter
{
  public:
    dollarToEuroConverter();
    double convert(double inDollars);
    std::string toString() const;
    void print() const;
};

#endif // DOLLARTOEUROCONVERTER_H
