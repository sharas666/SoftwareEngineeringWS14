#ifndef CONVERTERFACTORY_H
#define CONVERTERFACTORY_H

#include <memory>
#include "converter.hpp"
#include <map>
#include <functional>

class ConverterFactory
{
  public:
    std::shared_ptr<converter> create(std::string const&);
    static ConverterFactory* instance();

  private:
    ConverterFactory();
    static ConverterFactory* s_instance;
    std::map<std::string, std::function<std::shared_ptr<converter>()>> m;
};



#endif // CONVERTERFACTORY_H
