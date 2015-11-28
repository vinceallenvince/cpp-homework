/**
 * Vince Allen
 *
 * Chapter 1, Project 8
 * The Babylonian method to calculate the square root of a
 * positive number n is as follows:
 * 1. make a guess at the answer (you can pick n/2 as your initial guess).
 * 2. Compute r = n / guess.
 * 3. Set guess = (guess + r) / 2.
 * 4. Go back to step 2.
 * 
 * Write a program that inputs an integer for n, iterates through the
 * Babylonian algorithm five times, outputs the answer as a double to
 * two decimal places. Your answer will be most accurate for small values of n.
 */

#include <iostream>

int const TOTAL_ITERATIONS = 5;

int main(int argc, const char * argv[]) {

    double number;

    std::cout << "Enter a number greater than 0." << std::endl;
    std::cin >> number;

    double guess = number / 2;

    for (int i = 0; i < TOTAL_ITERATIONS; i++) {
        double r = number / guess;
        guess = (guess + r) / 2;
        std::cout << guess << std::endl;
    }

    std::cout << "The Babylonian answer: " << guess;

    return 0;
}
