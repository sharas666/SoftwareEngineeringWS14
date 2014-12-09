#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include <iostream>
#include <string>
#include "converter.hpp"
#include "decorator.hpp"

class Temperatureconverter : public Decorator
{
  public:
    Temperatureconverter();
    virtual double convert(double inValue) = 0;
    virtual std::string toString() const = 0;
    virtual void print() const = 0;
};

#endif // TEMPERATURECONVERTER_H