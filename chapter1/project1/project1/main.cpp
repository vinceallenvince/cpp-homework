/**
 * Vince Allen
 *
 * Chapter 1, Project 1
 * One metric ton = 35273.92 ounces
 * Input total ounces of breakfast cereal.
 * Output weight in metric tons and total number of boxes to yield one metric ton of cereal.
 */

#include <iostream>

double const OUNCES_IN_ONE_METRIC_TON = 35273.92;

int main(int argc, const char * argv[]) {

    double boxOunces;

    std::cout << "Enter the weight in ounces of one box of your favorite cereal.\n";
    std::cin >> boxOunces;
    
    std::cout << "One box of your favorite cereal weighs " << boxOunces / OUNCES_IN_ONE_METRIC_TON << " metric tons.\n";

    double totalBoxes = OUNCES_IN_ONE_METRIC_TON / boxOunces;
    std::cout << "You need " << totalBoxes << " boxes to equal one metric ton of cereal.\n";

    return 0;
}
