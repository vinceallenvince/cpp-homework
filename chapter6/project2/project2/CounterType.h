//
// CounterType.h
// Vince Allen
// Chapter 6, project2
//

#include <stdio.h>

class CounterType {
    int count;
    int min = 0;
    int limitCounter(int num);
public:
    int getCounter() { return count; };
    int setCounter(int num);
    int incrementCounter();
    int decrementCounter();
};
