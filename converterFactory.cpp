#include "converterFactory.hpp"
#include "celsiustofahrenheitconverter.hpp"
#include "dollartoeuroconverter.hpp"
#include "eurotorupeeconverter.hpp"
#include "fahrenheittokelvinconverter.hpp"
#include "kilogramtomilligramconverter.hpp"
#include "kilogramtocentnerconverter.hpp"
#include "inverse.hpp"
#include <iostream>
#include <stdexcept>



ConverterFactory* ConverterFactory::s_instance = NULL;

ConverterFactory::ConverterFactory() : m{}
{
	m.insert(std::make_pair("ctof", celsiusToFahrenheitConverter::create));
	m.insert(std::make_pair("dtoe", dollarToEuroConverter::create));
	m.insert(std::make_pair("etor", euroToRupeeConverter::create));
	m.insert(std::make_pair("ftok", fahrenheitToKelvinConverter::create));
	m.insert(std::make_pair("ktoc", kilogramToCentnerConverter::create));
	m.insert(std::make_pair("ktom", kilogramToMilligramConverter::create));
	m.insert(std::make_pair("inverse", Inverse::create));
}	

std::shared_ptr<converter> ConverterFactory::create(std::string const& s)
{
	try
    {
		if(m.find(s) == m.end())
		{
			throw std::runtime_error("\n unknown command\n");
		}
		return m[s]();
    }
    catch(std::exception & e)
    {
      std::cout << e.what() << "\n";
    }
    return nullptr;
}

ConverterFactory* ConverterFactory::instance()
{
	if(s_instance == NULL)
	{
		s_instance = new ConverterFactory;
	}
	return s_instance;
}
