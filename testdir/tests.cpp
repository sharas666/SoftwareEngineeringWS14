#include "tests.hpp"

//round
double round(double d)
{
	return (int)(d * 100) / 100.0;
}

// money
int test_dollar_to_euro()
{
	dollarToEuroConverter d{};
	TINYTEST_EQUAL(0.000000, round(d.convert(0)));
	TINYTEST_EQUAL(0, round(d.convert(-0)));
	TINYTEST_EQUAL(0.780000, round(d.convert(1)));
	TINYTEST_EQUAL(2.72, round(d.convert(3.48)));
	TINYTEST_EQUAL(-2.71, round(d.convert(-3.48))); // possible?
	return 1;
}

int test_euro_to_rupee()
{
	euroToRupeeConverter e{};
	TINYTEST_EQUAL(0, round(e.convert(0)));
	TINYTEST_EQUAL(0, round(e.convert(-0)));
	TINYTEST_EQUAL(76.82, round(e.convert(1)));
	TINYTEST_EQUAL(267.36, round(e.convert(3.48)));
	TINYTEST_EQUAL(-267.37, round(e.convert(-3.48)));
	return 1;
}

// temperature
int test_celsius_to_fahrenheit()
{
	celsiusToFahrenheitConverter c{};
	TINYTEST_EQUAL(32, round(c.convert(0)));
	TINYTEST_EQUAL(32, round(c.convert(-0)));
	TINYTEST_EQUAL(33.79, round(c.convert(1)));
	TINYTEST_EQUAL(30.2, round(c.convert(-1)));
	TINYTEST_EQUAL(117.62, round(c.convert(3.48)));
	TINYTEST_EQUAL(25.74, round(c.convert(-3.48)));
	return 1;
}

int test_fahrenheit_to_kelvin()
{
	fahrenheitToKelvinConverter f{};
	TINYTEST_EQUAL(255.37, round(f.convert(0)));
	TINYTEST_EQUAL(255.37, round(f.convert(-0)));
	TINYTEST_EQUAL(255.78, round(f.convert(1)));
	TINYTEST_EQUAL(254.67, round(f.convert(-1)));
	TINYTEST_EQUAL(257.16, round(f.convert(3.48)));
	TINYTEST_EQUAL(253.29, round(f.convert(-3.48)));
	return 1;
}

// weight
int test_kilogram_to_milligram()
{
	kilogramToMilligramConverter k{};
	TINYTEST_EQUAL(0, round(k.convert(0)));
	TINYTEST_EQUAL(0, round(k.convert(-0)));
	TINYTEST_EQUAL(1000000, round(k.convert(1)));
	TINYTEST_EQUAL(3480000, round(k.convert(3.48)));
	TINYTEST_EQUAL(-3480000, round(k.convert(-3.48))); // possible
	return 1;
}

int test_kilogram_to_centner()
{
	kilogramToCentnerConverter k{};
	TINYTEST_EQUAL(0, round(k.convert(0)));
	TINYTEST_EQUAL(0, round(k.convert(-0)));
	TINYTEST_EQUAL(0.02, round(k.convert(1)));
	TINYTEST_EQUAL(0.06, round(k.convert(3.48)));
	TINYTEST_EQUAL(-0.06, round(k.convert(-3.48))); // possible?
	return 1;
}

TINYTEST_START_SUITE(Money);
	TINYTEST_ADD_TEST(test_dollar_to_euro);
	TINYTEST_ADD_TEST(test_euro_to_rupee);
TINYTEST_END_SUITE();

TINYTEST_START_SUITE(Temperature);
	TINYTEST_ADD_TEST(test_celsius_to_fahrenheit);
	TINYTEST_ADD_TEST(test_fahrenheit_to_kelvin);
TINYTEST_END_SUITE();

TINYTEST_START_SUITE(Weight);
	TINYTEST_ADD_TEST(test_kilogram_to_milligram);
	TINYTEST_ADD_TEST(test_kilogram_to_centner);
TINYTEST_END_SUITE();

TINYTEST_START_MAIN();
  TINYTEST_RUN_SUITE(Money);
  TINYTEST_RUN_SUITE(Temperature);
  TINYTEST_RUN_SUITE(Weight);
TINYTEST_END_MAIN();
