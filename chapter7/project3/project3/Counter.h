//  Counter.h
//  Chapter 7, Project3

#include <stdio.h>
#include <iostream>
using namespace std;

class Counter {

    int maxValue;
    int currentValue;

    int units0;
    int units10;
    int units100;
    int units1000;

public:

    Counter(int maxValue = 9999, int currentValue = 0);

    int getMaxValue();
    int getCurrentValue();
    int getUnits0();
    int getUnits10();
    int getUnits100();
    int getUnits1000();

    void setMaxValue(int maxValue);
    void setCurrentValue(int currentValue);
    void setUnits0(int val);
    void setUnits10(int val);
    void setUnits100(int val);
    void setUnits1000(int val);

    void reset();
    void incr0();
    void incr10();
    void incr100();
    void incr1000();
    bool overflow();

    int calculateCurrentValue();
    void updateDisplay();
};
