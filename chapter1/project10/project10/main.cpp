/**
 * Vince Allen
 *
 * Chapter 1, Project 10
 * Write a program that allows the user to enter a time in seconds and
 * then outputs how far an object would drop if it is in freefall for
 * that length of time. Assume no friction or resistance from air and a
 * constant acceleration of 32 feet per second due to gravity.
 *
 * Use the equation:
 * distance = 1/2 * acceleration * time ^ 2
 */

#include <iostream>

int const ACCEL_FEET_PER_SECOND = 32;

int main(int argc, const char * argv[]) {

    double timeInSeconds;

    std::cout << "Enter a time in seconds." << std::endl;
    std::cin >> timeInSeconds;

    double distance = 0.5 * ACCEL_FEET_PER_SECOND * (timeInSeconds / 2);
    std::cout << "The object will fall " << distance << " feet." << std::endl;

    return 0;
}
