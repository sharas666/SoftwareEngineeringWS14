#include "tinytest.h"
#include "converter.hpp"

int test_dollar_converter1(){
	dollarToEuroConverter d{};
	TINYTEST_EQUAL(0.78, d.convert(1));
	TINYTEST_EQUAL(2.71, d.convert(3.48));
}