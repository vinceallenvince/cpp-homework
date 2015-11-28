/**
 * Vince Allen
 *
 * Chapter 3, Project 1
 * 1 liter = 0.264179 gallons
 * Input total liters of gasoline consumed and miles traveled.
 * Output miles per gallon.
 */
#include <iostream>

double const gallonsPerLiter = 0.264179;

int main(int argc, const char * argv[]) {

    char again = 'Y';
    double totalLitersConsumed, totalMilesTraveled;

    while (again != 'n' && again != 'N') {

        std::cout << "How many liters of gasoline did your car consume?" << std::endl;
        std::cin >> totalLitersConsumed;

        std::cout << "How many miles did you travel?" << std::endl;
        std::cin >> totalMilesTraveled;

        std::cout << "Your car gets " << totalMilesTraveled / (totalLitersConsumed * gallonsPerLiter) << " miles per gallon of gasoline." << std::endl;

        std::cout << "Again (Y or n) ";
        std::cin >> again;
    }
    return 0;
}
