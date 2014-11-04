#include "tinytest.h"
#include "converter.hpp"

// money
int test_dollar_to_euro()
{
	dollarToEuroConverter d{};
	TINYTEST_EQUAL(0, d.convert(0));
	TINYTEST_EQUAL(0.78, d.convert(1));
	TINYTEST_EQUAL(2.71, d.convert(3.48));
	TINYTEST_EQUAL(-2.71, d.convert(-3.48)); // possible?
}

int test_euro_to_rupee()
{
	euroToRupeeConverter e{};
	TINYTEST_EQUAL(0, e.convert(0));
	TINYTEST_EQUAL(76.83, e.convert(1));
	TINYTEST_EQUAL(267.37, e.convert(3.48));
	TINYTEST_EQUAL(-267.37, e.convert(-3.48));
}

// temperature
int test_celsius_to_fahrenheit()
{
	celsiusToFahrenheitConverter c{};
	TINYTEST_EQUAL(32, c.convert(0));
	TINYTEST_EQUAL(33.8, c.convert(1));
	TINYTEST_EQUAL(30.2, c.convert(-1));
	TINYTEST_EQUAL(117.62, c.convert(3.48));
	TINYTEST_EQUAL(25.74, c.convert(-3.48));
}

int test_fahrenheit_to_kelvin()
{
	fahrenheitToKelvinConverter f{};
	TINYTEST_EQUAL(255.22, f.convert(0));
	TINYTEST_EQUAL(255.78, f.convert(1));
	TINYTEST_EQUAL(254.67, f.convert(-1));
	TINYTEST_EQUAL(257.16, f.convert(3.48));
	TINYTEST_EQUAL(253.29, f.convert(-3.48));
}

// weight
int test_kilogram_to_milligram()
{
	kilogramToMilligramConverter k{};
	TINYTEST_EQUAL(0, k.convert(0));
	TINYTEST_EQUAL(1000000, k.convert(1));
	TINYTEST_EQUAL(3480000, k.convert(3.48));
	TINYTEST_EQUAL(-3480000, k.convert(-3.48)); // possible
}

int test_kilogram_to_centner()
{
	kilogramToCentnerConverter k{};
	TINYTEST_EQUAL(0, k.convert(0));
	TINYTEST_EQUAL(0.02, k.convert(1));
	TINYTEST_EQUAL(0.069, k.convert(3.48));
	TINYTEST_EQUAL(-0.069, k.convert(-3.48)); // possible?
}