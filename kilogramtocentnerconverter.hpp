#ifndef KILOGRAMTOCENTNERCONVERTER_H
#define KILOGRAMTOCENTNERCONVERTER_H

#include "weightconverter.hpp"

class kilogramToCentnerConverter : public Moneyconverter
{
  public:
    kilogramToCentnerConverter();
    double convert(double inKilogram);
    std::string toString() const;
    void print() const;
};

#endif // KILOGRAMTOCENTNERCONVERTER_H
