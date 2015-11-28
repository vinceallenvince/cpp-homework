/**
 * Chapter 2, project 1
 * Gauge the expected cost of an item given a number of years.
 * Input the current per item cost, the total years to purchase and
 * the inflation rate.
 * Output the per item cost after the total years.
 */

#include <iostream>
#include <assert.h>

float adjustForInflation(float perItemCost, float inflationRate);

int main(int argc, const char * argv[]) {

    assert(adjustForInflation(10.0, 1.0) == static_cast<float>(0.1));

    //

    float perItemCost, years, inflationRate;

    std::cout << "Enter per item cost. $";
    std::cin >> perItemCost;

    std::cout << "Enter total years from now to purchase. ";
    std::cin >> years;

    std::cout << "Enter inflation rate as a percentage. %";
    std::cin >> inflationRate;

    for (int i = 0; i < years; i++) {
        perItemCost += adjustForInflation(perItemCost, inflationRate);
    }
    std::cout << "Items " << years << " year(s) from now will cost $" << perItemCost << " per item. \n";

    return 0;
}

float adjustForInflation(float perItemCost, float inflationRate)
{
    return perItemCost * inflationRate * 0.01;
}
