//  Counter.cpp
//  Chapter 7, Project3

#include "Counter.h"

/**
 * Creates a Counter.
 * @param maxValue The counter's maximum display value.
 * @param currentValue The counter's current value.
 * @constructor
 */
Counter::Counter(int maxValue, int currentValue) {
    this->maxValue = maxValue;
    this->currentValue = currentValue;
    this->units0 = 0;
    this->units10 = 0;
    this->units100 = 0;
    this->units1000 = 0;
};

// accessors
int Counter::getMaxValue() {
    return this->maxValue;
};

int Counter::getCurrentValue() {
    return this->currentValue;
};

int Counter::getUnits0() {
    return this->units0;
};

int Counter::getUnits10() {
    return this->units10;
};

int Counter::getUnits100() {
    return this->units100;
};

int Counter::getUnits1000() {
    return this->units1000;
};

void Counter::setMaxValue(int maxValue) {
    this->maxValue = maxValue;
};

void Counter::setCurrentValue(int currentValue) {
    this->currentValue = currentValue;
};

void Counter::setUnits0(int val) {
    this->units0 = val;
    this->setCurrentValue(this->calculateCurrentValue());
    this->overflow();
};

void Counter::setUnits10(int val) {
    this->units10 = val;
    this->setCurrentValue(this->calculateCurrentValue());
    this->overflow();
};

void Counter::setUnits100(int val) {
    this->units100 = val;
    this->setCurrentValue(this->calculateCurrentValue());
    this->overflow();
};

void Counter::setUnits1000(int val) {
    this->units1000 = val;
    this->setCurrentValue(this->calculateCurrentValue());
    this->overflow();
};

// utility methods
/**
 * Returns true if current value exceeds max value.
 */
bool Counter::overflow() {
    return this->getCurrentValue() > this->getMaxValue();
};

/**
 * Returns the full value based on unit totals.
 * @return Current value.
 */
int Counter::calculateCurrentValue() {
    return (this->getUnits1000() * 1000) + (this->getUnits100() * 100) + (this->getUnits10() * 10) + this->getUnits0();
};

/**
 * Prints the current total to cout. If current value exceeds max value,
 * the total is marked as overflow.
 */
void Counter::updateDisplay() {
    char overflow[] = "[OVERFLOW]";
    std::cout << "Current total: " << std::min(this->getCurrentValue(), this->getMaxValue()) << " " << (this->overflow() ? overflow : "") << std::endl;
};

// mutators
void Counter::reset() {
    this->currentValue = 0;
};

void Counter::incr0() {
    int val = this->getUnits0() + 1;
    if (val >= 10) {
        this->incr10();
        val = 0;
    }
    this->setUnits0(val);
};

void Counter::incr10() {
    int val = this->getUnits10() + 1;
    if (val >= 10) {
        this->incr100();
        val = 0;
    }
    this->setUnits10(val);
};

void Counter::incr100() {
    int val = this->getUnits100() + 1;
    if (val >= 10) {
        this->incr1000();
        val = 0;
    }
    this->setUnits100(val);
};

void Counter::incr1000() {
    int val = this->getUnits1000() + 1;
    this->setUnits1000(val);
};
