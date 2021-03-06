#include "tests.hpp"



// money
int test_dollar_to_euro()
{
	dollarToEuroConverter d{};
	TINYTEST_EQUAL_EPSILON(0.000000, d.convert(0));
	TINYTEST_EQUAL_EPSILON(0, d.convert(-0));
	TINYTEST_EQUAL_EPSILON(0.780000, d.convert(1));
	TINYTEST_EQUAL_EPSILON(2.72, d.convert(3.48));
	TINYTEST_EQUAL_EPSILON(-2.72, d.convert(-3.48)); 
	return 1;
}

int test_euro_to_rupee()
{
	euroToRupeeConverter e{};
	TINYTEST_EQUAL_EPSILON(0, e.convert(0));
	TINYTEST_EQUAL_EPSILON(0, e.convert(-0));
	TINYTEST_EQUAL_EPSILON(76.82, e.convert(1));
	TINYTEST_EQUAL_EPSILON(267.36, e.convert(3.48));
	TINYTEST_EQUAL_EPSILON(-267.37, e.convert(-3.48));
	return 1;
}

// temperature
int test_celsius_to_fahrenheit()
{
	celsiusToFahrenheitConverter c{};
	TINYTEST_EQUAL_EPSILON(32, c.convert(0));
	TINYTEST_EQUAL_EPSILON(32, c.convert(-0));
	TINYTEST_EQUAL_EPSILON(33.79, c.convert(1));
	TINYTEST_EQUAL_EPSILON(30.2, c.convert(-1));
	TINYTEST_EQUAL_EPSILON(38.26, c.convert(3.48));
	TINYTEST_EQUAL_EPSILON(25.74, c.convert(-3.48));
	return 1;
}

int test_fahrenheit_to_kelvin()
{
	fahrenheitToKelvinConverter f{};
	TINYTEST_EQUAL_EPSILON(255.37, f.convert(0));
	TINYTEST_EQUAL_EPSILON(255.37, f.convert(-0));
	TINYTEST_EQUAL_EPSILON(255.78, f.convert(1));
	TINYTEST_EQUAL_EPSILON(254.67, f.convert(-1));
	TINYTEST_EQUAL_EPSILON(257.16, f.convert(3.48));
	TINYTEST_EQUAL_EPSILON(253.29, f.convert(-3.48));
	return 1;
}

// weight
int test_kilogram_to_milligram()
{
	kilogramToMilligramConverter k{};
	TINYTEST_EQUAL_EPSILON(0, k.convert(0));
	TINYTEST_EQUAL_EPSILON(0, k.convert(-0));
	TINYTEST_EQUAL_EPSILON(1000000, k.convert(1));
	TINYTEST_EQUAL_EPSILON(3480000, k.convert(3.48));
	TINYTEST_EQUAL_EPSILON(-3480000, k.convert(-3.48)); 
	return 1;
}

int test_kilogram_to_centner()
{
	kilogramToCentnerConverter k{};
	TINYTEST_EQUAL_EPSILON(0, k.convert(0));
	TINYTEST_EQUAL_EPSILON(0, k.convert(-0));
	TINYTEST_EQUAL_EPSILON(0.02, k.convert(1));
	TINYTEST_EQUAL_EPSILON(0.06, k.convert(3.48));
	TINYTEST_EQUAL_EPSILON(-0.06, k.convert(-3.48)); 
	return 1;
}

int test_singleton()
{
	ConverterFactory* cFactory1;
	ConverterFactory* cFactory2;

	cFactory1 = cFactory1->instance();
	cFactory2 = cFactory2->instance();
	TINYTEST_ASSERT(cFactory1 == cFactory2);

	return 1;
}

int test_factory()
{
	ConverterFactory* cFactory;
	cFactory = cFactory->instance();
	auto c1 = cFactory->create("ctof");
	auto c2 = cFactory->create("ctof");
	TINYTEST_ASSERT(c1 != c2);

	return 1;
}

int test_decorator()
{
	std::shared_ptr<converter> a = std::make_shared<celsiusToFahrenheitConverter>(std::make_shared<fahrenheitToKelvinConverter>());
	TINYTEST_EQUAL_EPSILON(298.27, a->convert(25.12));

	return 1;
}

int test_inverse()
{
	std::shared_ptr<converter> a = std::make_shared<Inverse>(std::make_shared<dollarToEuroConverter>());
	std::shared_ptr<converter> b = std::make_shared<dollarToEuroConverter>();

  	TINYTEST_EQUAL_EPSILON(25.12, b->convert(a->convert(25.12)));

  	return 1;
}

int test_inverse_temperature()
{
	std::shared_ptr<converter> c = std::make_shared<Inverse>(std::make_shared<celsiusToFahrenheitConverter>());

  	TINYTEST_EQUAL_EPSILON(0 , c->convert(25.12));

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

TINYTEST_START_SUITE(Converter_factory);
	TINYTEST_ADD_TEST(test_singleton);
	TINYTEST_ADD_TEST(test_factory);
TINYTEST_END_SUITE();

TINYTEST_START_SUITE(Decorator);
	TINYTEST_ADD_TEST(test_decorator);
	TINYTEST_ADD_TEST(test_inverse);
	TINYTEST_ADD_TEST(test_inverse_temperature);
TINYTEST_END_SUITE();


TINYTEST_START_MAIN();
  TINYTEST_RUN_SUITE(Money);
  TINYTEST_RUN_SUITE(Temperature);
  TINYTEST_RUN_SUITE(Weight);
  TINYTEST_RUN_SUITE(Converter_factory);  
  TINYTEST_RUN_SUITE(Decorator);  
TINYTEST_END_MAIN();
