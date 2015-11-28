//
//  Vince Allen
//  Midterm, Project 2
//
//  Write a program that emulates the STL  integer Vector class. Demonstrate the
//  following cases work:
//
//  (i)     Vector X(8);
//  (ii)    Vector Y(8,10);
//  (iii)	X.resize(16)
//  (iv)	X.pop_front( );
//  (v)     X.pop_back( );
//  (vi)	Y.push_front(100);
//  (vii)	Y.setValue(10,-99);
//  (viii)	Y.push_back(100);
//  (ix)	X.VectorConcat(Y);
//  (x)     X.Print();
//  (xi)	Y.Print();
//  (xii)	Y.Print(12);
//
//  OUTPUT:
//
//  [PASSED] Vector X(8);
//  [PASSED] Vector Y(8, 10);
//  [PASSED] X.resize(16);
//  [PASSED] X.pop_front();
//  [PASSED] X.pop_back();
//  [PASSED] Y.push_front(100);
//  [PASSED] Y.setValue(10,-99);
//  [PASSED] Y.push_back(100);
//  [PASSED] X.concat(Y);
//  0
//  0
//  0
//  0
//  0
//  0
//  0
//  0
//  0
//  0
//  0
//  0
//  0
//  0
//  100
//  10
//  10
//  10
//  10
//  10
//  10
//  10
//  10
//  100
//  [PASSED] X.print();
//  100
//  10
//  10
//  10
//  10
//  10
//  10
//  10
//  10
//  100
//  [PASSED] Y.print();
//  100
//  10
//  10
//  10
//  10
//  10
//  10
//  10
//  10
//  100
//  [PASSED] Y.print(12);
//
//  All tests succeeded.
//

#include <iostream>
#include "VectorTests.h"
using namespace std;

#define NDEBUG
#include <assert.h>

bool vectorDemo0();
bool vectorDemo1();
bool vectorDemo2();
bool vectorDemo3();
bool vectorDemo4();
bool vectorDemo5();
bool vectorDemo6();
bool vectorDemo7();
bool vectorDemo8();
bool vectorDemo9();
bool vectorDemo10();
bool vectorDemo11();

Vector X(8);
Vector Y(8, 10);

int main(int argc, const char * argv[]) {

    assert(vectorTests());

    const int TOTAL_TESTS = 12;

    Test vectorDemos[TOTAL_TESTS];

    strcpy(vectorDemos[0].description, "Vector X(8);");
    strcpy(vectorDemos[1].description, "Vector Y(8, 10);");
    strcpy(vectorDemos[2].description, "X.resize(16);");
    strcpy(vectorDemos[3].description, "X.pop_front();");
    strcpy(vectorDemos[4].description, "X.pop_back();");
    strcpy(vectorDemos[5].description, "Y.push_front(100);");
    strcpy(vectorDemos[6].description, "Y.setValue(10,-99);");
    strcpy(vectorDemos[7].description, "Y.push_back(100);");
    strcpy(vectorDemos[8].description, "X.concat(Y);");
    strcpy(vectorDemos[9].description, "X.print();");
    strcpy(vectorDemos[10].description, "Y.print();");
    strcpy(vectorDemos[11].description, "Y.print(12);");

    vectorDemos[0].func = vectorDemo0;
    vectorDemos[1].func = vectorDemo1;
    vectorDemos[2].func = vectorDemo2;
    vectorDemos[3].func = vectorDemo3;
    vectorDemos[4].func = vectorDemo4;
    vectorDemos[5].func = vectorDemo5;
    vectorDemos[6].func = vectorDemo6;
    vectorDemos[7].func = vectorDemo7;
    vectorDemos[8].func = vectorDemo8;
    vectorDemos[9].func = vectorDemo9;
    vectorDemos[10].func = vectorDemo10;
    vectorDemos[11].func = vectorDemo11;

    //

    TestRunner::runTests(vectorDemos, TOTAL_TESTS);

    std::cout << std::endl << "All tests succeeded." << std::endl << std::endl;

    return 0;
}

bool vectorDemo0() {
    return X.getValue(0) == 0 && X.getValue(X.getSize() - 1) == 0;
};

bool vectorDemo1() {
    return Y.getValue(0) == 10 && Y.getValue(Y.getSize() - 1) == 10;
};

bool vectorDemo2() {
    X.resize(16);
    return X.getSize() == 16 && X.getValue(0) == 0 && X.getValue(X.getSize() - 1) == 0;
};

bool vectorDemo3() {
    int currentSize = X.getSize();
    X.pop_front();
    return X.getSize() == currentSize - 1 && X.getValue(0) == 0 && X.getValue(X.getSize() - 1) == 0;
};

bool vectorDemo4() {
    int currentSize = X.getSize();
    X.pop_back();
    return X.getSize() == currentSize - 1 && X.getValue(0) == 0 && X.getValue(X.getSize() - 1) == 0;
};

bool vectorDemo5() {
    Y.push_front(100);
    return Y.getValue(0) == 100;
};

bool vectorDemo6() {
    Y.setValue(10,-99);

    bool thrown = false;
    try {
        Y.getValue(10);
    } catch (const std::out_of_range& e) {
        thrown = true;
    }

    return Y.getValue(0) == 100 && thrown;
};

bool vectorDemo7() {
    Y.push_back(100);
    return Y.getValue(Y.getSize() - 1) == 100;
};

bool vectorDemo8() {
    int currentSizeX = X.getSize();
    int currentSizeY = Y.getSize();
    int newSize = currentSizeX + currentSizeY;
    X.concat(Y);
    return X.getSize() == newSize && X.getValue(0) == 0 && X.getValue(newSize - 1) == 100;
};

bool vectorDemo9() {
    X.print();
    return true;
};

bool vectorDemo10() {
    Y.print();
    return true;
};

bool vectorDemo11() {
    Y.print(12);
    return true;
};
