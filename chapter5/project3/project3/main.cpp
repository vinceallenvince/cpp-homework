//
// Vince Allen 10/28/2015
//
// Chapter 5, Project 3
//
//  Define a function that takes a partially filled array of numbers
//  as its arguments and returns the standard deviation of the
//  numbers in the partially filled array.
//
//  The function will have two formal parameters: an array parameter and
//  a formal parameter of type int that gives the number of array positions used.
//
//  The numbers in the array will be of type double. Embed your function in a
//  suitable test program.
//
//  The standard deviation is the square root of variance.
//  Square of the variance is given by the average of the squares of difference between
//  the data points and the mean.
//
//  variance = σ2 = ∑ (x-µ)2 / N
//
//  OUTPUT:
//  mean: 5.0126
//  variance: 10.1362
//  standard deviation: 3.18375
//

#include <iostream>
#include <cmath>

//#define NDEBUG
#include <assert.h>

using namespace std;

const int TOTAL_NUMS = 10000;
const int MAX_RANGE = 10;

void fillArrayWithRandomValues(double arr[], int arraySize);
double arrayMean(double arr[], int arraySize);
double variance(double mean, double arr[], int arraySize);
double standardDeviation(double var);

int main(int argc, const char * argv[]) {

    srand(10);

    // ASSERTIONS

    double testArr[] = {1, 9, 4, 1, 9, 6, 9, 5, 7, 9};
    double testMean = arrayMean(testArr, 10);
    double testVariance = variance(testMean, testArr, 10);
    double testSD = standardDeviation(testVariance);
    assert(testMean == 6);
    assert(testVariance == 9.1999999999999993);
    assert(testSD == 3.03315017762062);

    //

    double nums[TOTAL_NUMS * 2]; // force partially filled array
    fillArrayWithRandomValues(nums, TOTAL_NUMS);

    double mean = arrayMean(nums, TOTAL_NUMS);
    cout << "mean: " << mean << endl;

    double var = variance(mean, nums, TOTAL_NUMS);
    cout << "variance: " << var << endl;

    double sd = standardDeviation(var);
    cout << "standard deviation: " << sd << endl;

    return 0;
}

/**
 * Returns the a square root of the passed variance (ie. standard deviation)
 * @param var A double representing variance
 * @return The square root
 */
double standardDeviation(double var) {
    return sqrt(var);
}

/**
 * Returns the statistical variance of an array of numbers.
 * @param mean The average of the numbers in the array
 * @param arr[] An array of numbers
 * @param arraySize The size of the array of numbers
 * @return The variance
 */
double variance(double mean, double arr[], int arraySize) {
    double *ptr = &arr[0];
    double sum = 0;
    for (int i = 0; i < arraySize; ++i) {
        double x = *ptr++;
        sum += pow(x - mean, 2);
    }
    return sum / arraySize;
}

/**
 * Returns the average of an array of numbers.
 * @param arr[] The array of numbers
 * @param arraySize The size of the array of numbers
 * @return The mean
 */
double arrayMean(double arr[], int arraySize) {
    double *ptr = &arr[0];
    double sum = 0;
    for (int i = 0; i < arraySize; ++i) {
        sum += *ptr++;
    }
    return sum / arraySize;
}

/**
 * Fills an array with random values.
 * @param arr[] An array
 * @param arraySize The array size
 */
void fillArrayWithRandomValues(double arr[], int arraySize) {
    double *ptr = &arr[0];
    for (int i = 0; i < arraySize; ++i) {
        *ptr++ = static_cast<double>(rand() % (MAX_RANGE + 1));
    }
}
