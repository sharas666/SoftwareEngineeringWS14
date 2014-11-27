#ifndef KILOGRAMTOCENTNERCONVERTER_H
#define KILOGRAMTOCENTNERCONVERTER_H

#include "weightconverter.hpp"

class kilogramToCentnerConverter : public Weightconverter
{
  public:
    kilogramToCentnerConverter();
    double convert(double inKilogram);
    std::string toString() const;
    void print() const;
    static std::shared_ptr<converter> create();
};

#endif // KILOGRAMTOCENTNERCONVERTER_H
