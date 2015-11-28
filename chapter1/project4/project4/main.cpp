/**
 * Chapter 1, Project 4
 */

#include <iostream>

int const MONTHS_IN_A_YEAR = 12;

int main(int argc, const char * argv[]) {

    // face value
    // interest
    // loan period in years
    // total interest due = face value * interest * loan period in years
    // amount returned to consumer = face value - total interest due

    // input    <- total consumer needs returned
    //          <- interest rate
    //          <- loan period in months
    //
    // output   -> total face value to return what consumer needs
    //          -> monthly payment

    double totalNeeded, interestRate, yearlyLoadPeriod;
    int monthlyLoanPeriod;

    std::cout << "Enter the total amount needed. $";
    std::cin >> totalNeeded;

    std::cout << "Enter the interest rate. %";
    std::cin >> interestRate;

    std::cout << "Enter the load period in months. ";
    std::cin >> monthlyLoanPeriod;

    yearlyLoadPeriod = monthlyLoanPeriod / MONTHS_IN_A_YEAR;

    std::cout << "Total face value needed: $" <<


    // amount returned to consumer = face value - (face value * interest * loan period in years)

    100 = x - (x * 0.9);

    return 0;
}
