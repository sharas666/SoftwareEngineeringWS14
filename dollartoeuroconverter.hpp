#ifndef DOLLARTOEUROCONVERTER_H
#define DOLLARTOEUROCONVERTER_H

#include "moneyconverter.hpp"

class dollarToEuroConverter : public Moneyconverter
{
  public:
    dollarToEuroConverter();
    dollarToEuroConverter(std::shared_ptr<converter> to_decorate) : Moneyconverter{to_decorate}{}
    double convert(double inDollars);
    std::string toString() const;
    void print() const;
    static std::shared_ptr<converter> create();
};

#endif // DOLLARTOEUROCONVERTER_H
