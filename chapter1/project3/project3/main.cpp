#include <iostream>

/**
 * Vince Allen
 *
 * Chapter 1, Project 3
 * Employee gets salary increase retroactive 6 months.
 * Input previous salary.
 * Output retroactive salary due employee, new annual salary, new monthly salary.
 */

double const PERCENTAGE_INCREASE = 0.076;
double const MONTHS_IN_A_YEAR = 12;
double const MONTHS_RETROACTIVE = 6;

int main(int argc, const char * argv[]) {

    double currentAnnualSalary, currentMonthySalary, newAnnualSalary, newMonthlySalary;

    std::cout << "Input your current annual salary. $";
    std::cin >> currentAnnualSalary;

    currentMonthySalary = currentAnnualSalary / MONTHS_IN_A_YEAR;
    newAnnualSalary = currentAnnualSalary + (currentAnnualSalary * PERCENTAGE_INCREASE);
    newMonthlySalary = newAnnualSalary / MONTHS_IN_A_YEAR;

    std::cout << "New annual salary: $" << newAnnualSalary << std::endl;
    std::cout << "New monthly salary: $" << newMonthlySalary << std::endl;
    std::cout << "Retroactive salary due employee: $" << (newMonthlySalary - currentMonthySalary) * MONTHS_RETROACTIVE << std::endl;
    
    return 0;
}
