//
//  Vince Allen
//  Chapter 7, Project1
//
//  Define an abstract class Month that is an abstract data type for a month. Your class will
//  have one member variable of type int to represent a month (1 for Jan, etc). Include all
//  the following member functions: a constructor to set the month using the first three letters
//  in the name of the month as three arguments, a constructor to set the month using an
//  integer as an argument, (1 for Jan, etc), a default constructor, an input function that
//  reads the month as the first three letters in the name of the month, an output function
//  that outputs the month as an integer, an output function that outputs the month as the first
//  three letters in the name of the month, and a member function that returns the next month
//  as a value of type Month. Embed your class definition in a test program.
//
//  OUTPUT
//
//  [PASSED] Constructor should set the month using the first three letters in the name of the
//  month as three arguments.
//  [PASSED] Constructor should set the month using an integer as an argument.
//  [PASSED] Default constructor should set the month using default index.
//  [PASSED] Should set the month using the first three letters in the name of the month.
//  [PASSED] Should return the month as the first three letters in the name of the month.
//  [PASSED] Should return the next month as a value of type Month.
//
//  All tests succeeded.
//

#include <iostream>
#include "Month.h"
#include "TestRunner.h"
using namespace std;

bool monthTest0();
bool monthTest1();
bool monthTest2();
bool monthTest3();
bool monthTest4();
bool monthTest5();

int main(int argc, const char * argv[]) {


    const int TOTAL_TESTS = 6;

    Test monthTests[TOTAL_TESTS];

    strcpy(monthTests[0].description, "Constructor should set the month using the first three letters in the name of the month as three arguments.");
    strcpy(monthTests[1].description, "Constructor should set the month using an integer as an argument.");
    strcpy(monthTests[2].description, "Default constructor should set the month using default index.");
    strcpy(monthTests[3].description, "Should set the month using the first three letters in the name of the month.");
    strcpy(monthTests[4].description, "Should return the month as the first three letters in the name of the month.");
    strcpy(monthTests[5].description, "Should return the next month as a value of type Month.");

    monthTests[0].func = monthTest0;
    monthTests[1].func = monthTest1;
    monthTests[2].func = monthTest2;
    monthTests[3].func = monthTest3;
    monthTests[4].func = monthTest4;
    monthTests[5].func = monthTest5;

    //

    TestRunner::runTests(monthTests, TOTAL_TESTS);

    std::cout << std::endl << "All tests succeeded." << std::endl << std::endl;

    return 0;
}

bool monthTest0() {
    Month monthJan('j', 'a', 'n');
    Month monthJun('j', 'u', 'n');
    Month monthJul('j', 'u', 'l');
    Month monthOct('o', 'c', 't');

    return monthJan.getMonthIndex() == 0 && monthJun.getMonthIndex() == 5 && monthJul.getMonthIndex() == 6 && monthOct.getMonthIndex() == 9;
};

bool monthTest1() {
    Month monthJun(5);
    return monthJun.getMonthIndex() == 5;
};

bool monthTest2() {
    Month month;
    return month.getMonthIndex() == 0;
};

bool monthTest3() {
    Month month;
    month.setMonthByFirstThreeChars('s', 'e', 'p');
    return month.getMonthIndex() == 8;
};

bool monthTest4() {
    Month month(2);
    const char *m = month.getMonthAsFirstThreeChars();
    const char str[] = "mar";
    const char *ptr = &str[0];
    return strcmp(m, ptr) == 0;
};

bool monthTest5() {
    Month monthMar(2);
    Month nextMonthA = monthMar.getNextMonth();
    Month monthDec(11);
    Month nextMonthB = monthDec.getNextMonth();
    return nextMonthA.getMonthIndex() == 3 && nextMonthB.getMonthIndex() == 0;
}
