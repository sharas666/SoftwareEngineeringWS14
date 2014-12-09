#ifndef EUROTORUPEECONVERTER_H
#define EUROTORUPEECONVERTER_H

#include "moneyconverter.hpp"

class euroToRupeeConverter : public Moneyconverter
{
  public:
    euroToRupeeConverter();
    euroToRupeeConverter(std::shared_ptr<converter> to_decorate) : Moneyconverter{to_decorate}{}
    double convert(double inEuros);
    std::string toString() const;
    void print() const;
    static std::shared_ptr<converter> create();
};

#endif // EUROTORUPEECONVERTER_H
