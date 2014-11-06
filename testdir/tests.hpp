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

TINYTEST_DECLARE_SUITE(Money);
TINYTEST_DECLARE_SUITE(Temperature);
TINYTEST_DECLARE_SUITE(Weight);

#endif // TESTS_H
