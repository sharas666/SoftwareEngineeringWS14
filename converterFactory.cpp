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
	m.insert(std::make_pair("cToF", cToF));
	m.insert(std::make_pair("dToC", dToC));
	m.insert(std::make_pair("eToR", eToR));
	m.insert(std::make_pair("fToK", fToK));
	m.insert(std::make_pair("kToC", kToC));
	m.insert(std::make_pair("kToM", kToM));
}	

std::shared_ptr<converter> ConverterFactory::create(std::string const& s) const
{
	return nullptr;
}

ConverterFactory* ConverterFactory::instance()
{
	if(s_instance == NULL)
	{
		s_instance = new ConverterFactory;
		return s_instance;
	}
}

std::shared_ptr<converter> ConverterFactory::cToF()
{
	return std::make_shared<celsiusToFahrenheitConverter>();
}

std::shared_ptr<converter> ConverterFactory::dToC()
{
	return std::make_shared<dollarToEuroConverter>();
}

std::shared_ptr<converter> ConverterFactory::eToR()
{
	return std::make_shared<euroToRupeeConverter>();
}

std::shared_ptr<converter> ConverterFactory::fToK()
{
	return std::make_shared<fahrenheitToKelvinConverter>();
}

std::shared_ptr<converter> ConverterFactory::kToC()
{
	return std::make_shared<kilogramToCentnerConverter>();
}

std::shared_ptr<converter> ConverterFactory::kToM()
{
	return std::make_shared<kilogramToMilligramConverter>();
}