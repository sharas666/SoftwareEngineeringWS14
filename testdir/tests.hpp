#ifndef TESTS_H
#define TESTS_H

#include "tinytest.h"
#include "../converter.hpp"
#include "../celsiustofahrenheitconverter.hpp"
#include "../dollartoeuroconverter.hpp"
#include "../eurotorupeeconverter.hpp"
#include "../fahrenheittokelvinconverter.hpp"
#include "../kilogramtomilligramconverter.hpp"
#include "../kilogramtocentnerconverter.hpp"
#include "../converterFactory.hpp"
#include "../inverse.hpp"

TINYTEST_DECLARE_SUITE(Money);
TINYTEST_DECLARE_SUITE(Temperature);
TINYTEST_DECLARE_SUITE(Weight);
TINYTEST_DECLARE_SUITE(Converter_factory);  
TINYTEST_DECLARE_SUITE(Decorator);

#endif // TESTS_H
