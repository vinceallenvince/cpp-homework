//
//  Vince Allen
//  Chapter 7, Project3
//
//  Create a simple counter with keys mapped to units representing orders of magnitude.
//
//  OUTPUT:
//
//  [PASSED] Should create a Counter w default values.
//  [PASSED] Should create a Counter w passed values.
//  [PASSED] Should reset Counter currentValue to 0.
//  [PASSED] Should increment units0.
//  [PASSED] Should increment units10.
//  [PASSED] Should increment units100.
//  [PASSED] Should increment units1000.
//  [PASSED] Should carry over units from units0 to units10.
//  [PASSED] Should carry over units from units10 to units100.
//  [PASSED] Should carry over units from units100 to units1000.
//  [PASSED] Should not carry over units from units1000.
//  [PASSED] Should check overflow.
//
//  All tests succeeded.
//
//  Counter max: 1000
//  Increment counter (a: +1000, s: +100, d: +10, f: 1)
//
//  Key: s
//  Current total: 100
//  Key: s
//  Current total: 200
//  Key: s
//  Current total: 300
//  Key: d
//  Current total: 310
//  Key: d
//  Current total: 320
//  Key: a
//  Current total: 1000 [OVERFLOW]
//

#include <iostream>
#include "CounterTests.h"
using namespace std;

//#define NDEBUG
#include <assert.h>

int main(int argc, const char * argv[]) {

    assert(counterTests());

    char key;

    Counter c(1000, 0);

    cout << "Counter max: " << c.getMaxValue() << endl;
    cout << "Increment counter (a: +1000, s: +100, d: +10, f: 1)" << endl << endl;

    while (!c.overflow()) {
        cout << "Key: ";
        cin >> key;
        if (key == 'a') {
            c.incr1000();
        } else if (key == 's') {
            c.incr100();
        } else if (key == 'd') {
            c.incr10();
        } else if (key == 'f') {
            c.incr0();
        }
        c.updateDisplay();
    }

    return 0;
}
