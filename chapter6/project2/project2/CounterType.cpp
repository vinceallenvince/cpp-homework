//
// CounterType.cpp
// Vince Allen
// Chapter 6, project2
//

#include "CounterType.h"

int CounterType::limitCounter(int num) {
    return count = num >= min ? num : min;
};

int CounterType::setCounter(int num) {
    return limitCounter(num);
};

int CounterType::incrementCounter() {
    return setCounter(count + 1);
};

int CounterType::decrementCounter() {
    return setCounter(count - 1);
};
