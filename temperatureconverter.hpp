#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include <iostream>
#include <string>
#include "converter.hpp"

class Temperatureconverter : public converter
{
  public:
    Temperatureconverter(double min_value) : converter{min_value}{}
    Temperatureconverter(std::shared_ptr<converter> to_decorate, double min_value) : converter{to_decorate, min_value}{}
    virtual double convert(double inValue) = 0;
    virtual std::string toString() const = 0;
    virtual void print() const = 0;
};

#endif // TEMPERATURECONVERTER_H