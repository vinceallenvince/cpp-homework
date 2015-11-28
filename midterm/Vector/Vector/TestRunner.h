#include <iostream>
#include <assert.h>

typedef bool (*fn)();

struct Test {
    char description[128];
    fn func;
};

class TestRunner {
    
public:
    static void runTests(Test tests[], int totalTests);
};
