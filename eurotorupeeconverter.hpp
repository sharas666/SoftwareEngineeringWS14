#ifndef EUROTORUPEECONVERTER_H
#define EUROTORUPEECONVERTER_H

#include "Moneyconverter.hpp"

class euroToRupeeConverter : public Moneyconverter
{
  public:
    euroToRupeeConverter();
    double convert(double inEuros);
    std::string toString() const;
    void print() const;
};

#endif // EUROTORUPEECONVERTER_H