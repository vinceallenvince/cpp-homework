//  CounterTests.cpp
//  Chapter 7, Project3

#include "CounterTests.h"

const int TOTAL_TESTS = 12;

int counterTests() {

    Test counterTests[TOTAL_TESTS];

    strcpy(counterTests[0].description, "Should create a Counter w default values.");
    strcpy(counterTests[1].description, "Should create a Counter w passed values.");
    strcpy(counterTests[2].description, "Should reset Counter currentValue to 0.");
    strcpy(counterTests[3].description, "Should increment units0.");
    strcpy(counterTests[4].description, "Should increment units10.");
    strcpy(counterTests[5].description, "Should increment units100.");
    strcpy(counterTests[6].description, "Should increment units1000.");
    strcpy(counterTests[7].description, "Should carry over units from units0 to units10.");
    strcpy(counterTests[8].description, "Should carry over units from units10 to units100.");
    strcpy(counterTests[9].description, "Should carry over units from units100 to units1000.");
    strcpy(counterTests[10].description, "Should not carry over units from units1000.");
    strcpy(counterTests[11].description, "Should check overflow.");

    counterTests[0].func = counterTest0;
    counterTests[1].func = counterTest1;
    counterTests[2].func = counterTest2;
    counterTests[3].func = counterTest3;
    counterTests[4].func = counterTest4;
    counterTests[5].func = counterTest5;
    counterTests[6].func = counterTest6;
    counterTests[7].func = counterTest7;
    counterTests[8].func = counterTest8;
    counterTests[9].func = counterTest9;
    counterTests[10].func = counterTest10;
    counterTests[11].func = counterTest11;

    //

    TestRunner::runTests(counterTests, TOTAL_TESTS);

    std::cout << std::endl << "All tests succeeded." << std::endl << std::endl;

    return 1;
};

bool counterTest0() {
    Counter c;
    return c.getMaxValue() == 9999 && c.getCurrentValue() == 0;
};

bool counterTest1() {
    Counter c(1000, 10);
    return c.getMaxValue() == 1000 && c.getCurrentValue() == 10;
};

bool counterTest2() {
    Counter c(1000, 10);
    c.reset();
    return c.getCurrentValue() == 0;
};

bool counterTest3() {
    Counter c;
    c.incr0();
    return c.getUnits0() == 1;
};

bool counterTest4() {
    Counter c;
    c.incr10();
    return c.getUnits10() == 1;
};

bool counterTest5() {
    Counter c;
    c.incr100();
    return c.getUnits100() == 1;
};

bool counterTest6() {
    Counter c;
    c.incr1000();
    return c.getUnits1000() == 1;
};

bool counterTest7() {
    Counter c;
    c.setUnits0(9);
    c.incr0();
    return c.getUnits0() == 0 && c.getUnits10() == 1;
};

bool counterTest8() {
    Counter c;
    c.setUnits10(9);
    c.incr10();
    return c.getUnits10() == 0 && c.getUnits100() == 1;
};

bool counterTest9() {
    Counter c;
    c.setUnits100(9);
    c.incr100();
    return c.getUnits100() == 0 && c.getUnits1000() == 1;
};

bool counterTest10() {
    Counter c;
    c.setUnits1000(9);
    c.incr1000();
    return c.getUnits1000() == 10;
};

bool counterTest11() {
    Counter cA(1000, 0);
    cA.setUnits0(0);
    cA.setUnits10(0);
    cA.setUnits100(0);
    cA.setUnits1000(1);
    bool overflowA1 = cA.overflow();
    cA.incr0();
    bool overflowA2 = cA.overflow();

    Counter cB(9999, 0);
    cB.setUnits0(9);
    cB.setUnits10(9);
    cB.setUnits100(9);
    cB.setUnits1000(9);
    bool overflowB1 = cB.overflow();
    cB.incr0();
    bool overflowB2 = cB.overflow();

    return !overflowA1 && overflowA2 && !overflowB1 && overflowB2;
};
