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

    static std::shared_ptr<converter> cToF();
    static std::shared_ptr<converter> dToC();
    static std::shared_ptr<converter> eToR();
    static std::shared_ptr<converter> fToK();
    static std::shared_ptr<converter> kToC();
    static std::shared_ptr<converter> kToM();

  private:
    ConverterFactory();
    static ConverterFactory* s_instance;
    std::map<std::string, std::function<std::shared_ptr<converter>()>> m;
    // template <typename T>
    // std::map<std::string, std::function<T()>> m;
};



#endif // CONVERTERFACTORY_H
