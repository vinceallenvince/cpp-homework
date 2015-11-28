//
// Vince Allen
// Chapter 6, project10
//
// Create a Temperature class that internally stores a temperature in degrees Kelvin. Create
// functions setTempKelvin, setTempFahrenheit, and setTempCelsius that takes an input in the
// specified scale, converts the temperature to Kelvin, and stores that temperature in the
// class member variable.
//
// Also, create functions that return the stores temperature in degrees Kelvin, Fahrenheit,
// or Celsius. Write a main function to test the class.
//
// Kelvin = Celsius + 273.15
// Kelvin = (Fahrenheit + 459.67) * (5/9)
// Celsius = (5/9) * (Fahrenheit - 32)
//
// OUTPUT:
//
// [PASSED] Should set temperature.
// [PASSED] Should convert passed Fahrenheit temperature to Kelvin.
// [PASSED] Should convert passed Celsius temperature to Kelvin.
// [PASSED] Should return Kelvin temperature in Fahrenheit scale.
// [PASSED] Should return Kelvin temperature in Celsius scale.
//
// All tests succeeded.
//

#include <iostream>
#include "assert.h"
#include "Test.h"
#include "Temperature.h"
#include <cmath>
using namespace std;

const int TOTAL_TESTS = 5;
void runTests(Test tests[], int totalTests);
bool test0();
bool test1();
bool test2();
bool test3();
bool test4();

int main(int argc, const char * argv[]) {

    Test tests[TOTAL_TESTS];

    strcpy(tests[0].description, "Should set temperature.");
    strcpy(tests[1].description, "Should convert passed Fahrenheit temperature to Kelvin.");
    strcpy(tests[2].description, "Should convert passed Celsius temperature to Kelvin.");
    strcpy(tests[3].description, "Should return Kelvin temperature in Fahrenheit scale.");
    strcpy(tests[4].description, "Should return Kelvin temperature in Celsius scale.");
    tests[0].func = test0;
    tests[1].func = test1;
    tests[2].func = test2;
    tests[3].func = test3;
    tests[4].func = test4;

    runTests(tests, TOTAL_TESTS);

    cout << endl << "All tests succeeded." << endl << endl;

    return 0;
}

bool test0() {
    Temperature temperature;
    temperature.setTempKelvin(50);
    return temperature.getTempKelvin() == 50;
};

bool test1() {
    Temperature temperature;
    temperature.setTempFahrenheit(50);
    return roundl(temperature.getTempKelvin()) == 283;
};

bool test2() {
    Temperature temperature;
    temperature.setTempCelsius(50);
    return roundl(temperature.getTempKelvin()) == 323;
};

bool test3() {
    Temperature temperature;
    temperature.setTempKelvin(300);
    return roundl(temperature.getTempFahrenheit()) == 80;
};

bool test4() {
    Temperature temperature;
    temperature.setTempKelvin(300);
    return roundl(temperature.getTempFahrenheit()) == 80;
};

void runTests(Test tests[], int totalTests) {
    for (int i = 0; i < totalTests; ++i) {
        assert(tests[i].func());
        cout << "[PASSED] " << tests[i].description << endl;
    }
}
