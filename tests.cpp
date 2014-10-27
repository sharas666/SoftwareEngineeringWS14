#include "tinytest.h"
#include "converter.hpp"

int test_dollar_converter1(){
	Dollarconverter d{};
	TINYTEST_EQUAL(1.26, d.convert(1));
	TINYTEST_EQUAL(4.38, d.convert(3.48));
}