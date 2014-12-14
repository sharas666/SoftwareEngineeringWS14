#ifndef MONEYCONVERTER_H
#define MONEYCONVERTER_H

#include <iostream>
#include <string>
#include "converter.hpp"

class Moneyconverter : public converter
{
  public:
    Moneyconverter();
    Moneyconverter(std::shared_ptr<converter> to_decorate) : converter{to_decorate}{}
    virtual double convert(double inValue) = 0;
    virtual std::string toString() const = 0;
    virtual void print() const = 0;
};

#endif // MONEYCONVERTER_H