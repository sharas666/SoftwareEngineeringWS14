# minimal makefile for SE class
all: main test

# main depends on all cpp files
main: $(patsubst %.cpp,%.o,$(wildcard *.cpp))
	g++ -std=c++0x -Wall -o $@ $^

# a slightly ugly hack to make .o depend on .hpp if it exists
.SECONDEXPANSION:
%.o: %.cpp $$(wildcard $$*.hpp)
	g++ -std=c++0x -Wall -c -o $@ $<

test:
	g++ -std=c++0x -o testdir/tests testdir/tests.cpp converter.cpp celsiustofahrenheitconverter.cpp dollartoeuroconverter.cpp eurotorupeeconverter.cpp fahrenheittokelvinconverter.cpp kilogramtomilligramconverter.cpp kilogramtocentnerconverter.cpp weightconverter.cpp moneyconverter.cpp temperatureconverter.cpp converterFactory.cpp
	./main DollarToEuro 10000
	./main EuroToRupee -4
	./main CelsiusToFahrenheit 80
	./main FahrenheitToKelvin 5
	./main KilogramToMilligram 0.1
	./main KilogramToCentner 300
	./testdir/tests

clean:
	rm main *.o

