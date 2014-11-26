#include "converterFactory.hpp"
#include "celsiustofahrenheitconverter.hpp"
#include "dollartoeuroconverter.hpp"
#include "eurotorupeeconverter.hpp"
#include "fahrenheittokelvinconverter.hpp"
#include "kilogramtomilligramconverter.hpp"
#include "kilogramtocentnerconverter.hpp"



ConverterFactory* ConverterFactory::s_instance = NULL;

ConverterFactory::ConverterFactory() {//:m{}{
	//m.insert(std::make_pair<std::string, std::function<std::shared_ptr<converter>>()>("cToF",cToF()));
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

std::shared_ptr<converter> ConverterFactory::cToF() const
{
	return std::make_shared<celsiusToFahrenheitConverter>();
}

std::shared_ptr<converter> ConverterFactory::dToC() const
{
	return std::make_shared<dollarToEuroConverter>();
}

std::shared_ptr<converter> ConverterFactory::eToR() const
{
	return std::make_shared<euroToRupeeConverter>();
}

std::shared_ptr<converter> ConverterFactory::fToK() const
{
	return std::make_shared<fahrenheitToKelvinConverter>();
}

std::shared_ptr<converter> ConverterFactory::kToc() const
{
	return std::make_shared<kilogramToCentnerConverter>();
}

std::shared_ptr<converter> ConverterFactory::kTom() const
{
	return std::make_shared<kilogramToMilligramConverter>();
}