/**
 * Vince Allen
 *
 * Chapter 3, project 2
 * Calculate last year's inflation rate.
 * Input the price of an item both one year ago and today.
 */

#include <iostream>

double inflationRate(double priceYearAgo, double priceNow);

int main(int argc, const char * argv[]) {

    char again = 'Y';
    double priceYearAgo, priceNow;

    while (again != 'n' && again != 'N') {

        std::cout << "Enter the price of cookies a year ago. $";
        std::cin >> priceYearAgo;

        std::cout << "Enter the price of cookies now. $";
        std::cin >> priceNow;

        std::cout << "The inflation rate: %" << inflationRate(priceYearAgo, priceNow) << std::endl;

        std::cout << "Again (Y or n) ";
        std::cin >> again;
    }

    return 0;
}

double inflationRate(double priceYearAgo, double priceNow) {
    return ((priceNow - priceYearAgo) / priceYearAgo) * 100;
}
