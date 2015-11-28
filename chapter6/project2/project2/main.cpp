//
// Vince Allen
// Chapter 6, project 2
//
// Define a class for CounterType. An object of this type is used to count things,
// so it records a count that is a nonnegative whole number.
//
// OUTPUT:
//
// [PASSED] Should set count to a value passed as an argument.
// [PASSED] Should increment counter.
// [PASSED] Should decrement counter.
// [PASSED] Should not allow counter to equal a negative number.
//
// All tests succeeded.
//

#include <iostream>
#include "assert.h"
#include "Test.h"
#include "CounterType.h"
using namespace std;

const int TOTAL_TESTS = 4;
void runTests(Test tests[], int totalTests);
bool test0();
bool test1();
bool test2();
bool test3();

int main(int argc, const char * argv[]) {

    Test tests[TOTAL_TESTS];

    strcpy(tests[0].description, "Should set count to a value passed as an argument.");
    strcpy(tests[1].description, "Should increment counter.");
    strcpy(tests[2].description, "Should decrement counter.");
    strcpy(tests[3].description, "Should not allow counter to equal a negative number.");
    tests[0].func = test0;
    tests[1].func = test1;
    tests[2].func = test2;
    tests[3].func = test3;

    runTests(tests, TOTAL_TESTS);

    return 0;
}

bool test0() {
    CounterType counter;
    counter.setCounter(10);
    return counter.getCounter() == 10;
};

bool test1() {
    CounterType counter;
    counter.setCounter(10);
    counter.incrementCounter();
    return counter.getCounter() == 11;
};

bool test2() {
    CounterType counter;
    counter.setCounter(10);
    counter.decrementCounter();
    return counter.getCounter() == 9;
};

bool test3() {
    CounterType counterA;
    counterA.setCounter(-100);

    CounterType counterB;
    counterB.setCounter(0);
    counterB.decrementCounter();
    return counterA.getCounter() == 0 && counterB.getCounter() == 0;
};

void runTests(Test tests[], int totalTests) {
    for (int i = 0; i < totalTests; ++i) {
        assert(tests[i].func());
        cout << "[PASSED] " << tests[i].description << endl;
    }
}
