#ifndef WEIGHTCONVERTER_H
#define WEIGHTCONVERTER_H

#include <iostream>
#include <string>
#include "converter.hpp"
#include "decorator.hpp"

class Weightconverter : public Decorator
{
  public:
    Weightconverter();
    virtual double convert(double inValue) = 0;
    virtual std::string toString() const = 0;
    virtual void print() const = 0;
};

#endif // WEIGHTCONVERTER_H