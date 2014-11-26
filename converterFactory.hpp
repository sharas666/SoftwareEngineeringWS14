#ifndef CONVERTERFACTORY_H
#define CONVERTERFACTORY_H

#include <memory>
#include "converter.hpp"
#include <map>
#include <functional>

class ConverterFactory
{
  public:
    std::shared_ptr<converter> create(std::string const&) const;
    static ConverterFactory* instance();

    std::shared_ptr<converter> cToF() const;
    std::shared_ptr<converter> dToC() const;
    std::shared_ptr<converter> eToR() const;
    std::shared_ptr<converter> fToK() const;
    std::shared_ptr<converter> kToc() const;
    std::shared_ptr<converter> kTom() const;

  private:
    ConverterFactory();
    static ConverterFactory* s_instance;
    //std::map<std::string, std::function<std::shared_ptr<converter>>()> m;
};



#endif // CONVERTERFACTORY_H
