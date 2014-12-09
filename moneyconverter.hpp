#ifndef MONEYCONVERTER_H
#define MONEYCONVERTER_H

#include <iostream>
#include <string>
#include "converter.hpp"
#include "decorator.hpp"

class Moneyconverter : public Decorator
{
  public:
    Moneyconverter();
    virtual double convert(double inValue) = 0;
    virtual std::string toString() const = 0;
    virtual void print() const = 0;
};

#endif // MONEYCONVERTER_H