#include "TestRunner.h"

void TestRunner::runTests(Test tests[], int totalTests) {
    for (int i = 0; i < totalTests; ++i) {
        assert(tests[i].func());
        std::cout << "[PASSED] " << tests[i].description << std::endl;
    }
};
