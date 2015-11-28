//
// Vince Allen
// Chapter 6, project8
//
// Define a class Money that stores a monetary amount. The class should have two private
// integer variables, one to store the number of dollars and another to store the number
// of cents. Add accessor and mutator functions that return the monetary amount as a double.
// Write a program that tests all your functions with at least two different Money objects.
//
// OUTPUT:
//
// [PASSED] Should return a properly formatted amount.
// [PASSED] Should return a properly formatted amount.
//
// All tests succeeded.
//

#include <iostream>
#include "assert.h"
#include "Test.h"
#include "Money.h"
using namespace::std;

const int TOTAL_TESTS = 2;
void runTests(Test tests[], int totalTests);
bool test0();
bool test1();

int main(int argc, const char * argv[]) {

    Test tests[TOTAL_TESTS];

    strcpy(tests[0].description, "Should return a properly formatted amount.");
    strcpy(tests[1].description, "Should return a properly formatted amount.");
    tests[0].func = test0;
    tests[1].func = test1;

    runTests(tests, TOTAL_TESTS);

    cout << endl << "All tests succeeded." << endl << endl;

    return 0;
}

bool test0() {
    Money money;
    money.setData(5, 35);
    return money.getAmount() == 5.35;
};

bool test1() {
    Money money;
    money.setData(800, 78);
    return money.getAmount() == 800.78;
};

void runTests(Test tests[], int totalTests) {
    for (int i = 0; i < totalTests; ++i) {
        assert(tests[i].func());
        cout << "[PASSED] " << tests[i].description << endl;
    }
}
