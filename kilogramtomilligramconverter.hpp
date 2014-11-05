#ifndef KILOGRAMTOMILLIGRAMCONVERTER_H
#define KILOGRAMTOMILLIGRAMCONVERTER_H

#include "weightconverter.hpp"

class kilogramToMilligramConverter : public Weightconverter
{
  public:
    kilogramToMilligramConverter();
    double convert(double inKilogram);
    std::string toString() const;
    void print() const;
};

#endif // KILOGRAMTOMILLIGRAMCONVERTER_H
