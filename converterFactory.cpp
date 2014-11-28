#include "converterFactory.hpp"
#include "celsiustofahrenheitconverter.hpp"
#include "dollartoeuroconverter.hpp"
#include "eurotorupeeconverter.hpp"
#include "fahrenheittokelvinconverter.hpp"
#include "kilogramtomilligramconverter.hpp"
#include "kilogramtocentnerconverter.hpp"
#include <iostream>



ConverterFactory* ConverterFactory::s_instance = NULL;

ConverterFactory::ConverterFactory() : m{}
{
	m.insert(std::make_pair("cToF", celsiusToFahrenheitConverter::create));
	m.insert(std::make_pair("dToE", dollarToEuroConverter::create));
	m.insert(std::make_pair("eToR", euroToRupeeConverter::create));
	m.insert(std::make_pair("fToK", fahrenheitToKelvinConverter::create));
	m.insert(std::make_pair("kToC", kilogramToCentnerConverter::create));
	m.insert(std::make_pair("kToM", kilogramToMilligramConverter::create));
}	

std::shared_ptr<converter> ConverterFactory::create(std::string const& s)
{
	return m[s]();
}

ConverterFactory* ConverterFactory::instance()
{
	if(s_instance == NULL)
	{
		s_instance = new ConverterFactory;
	}
	return s_instance;
}
