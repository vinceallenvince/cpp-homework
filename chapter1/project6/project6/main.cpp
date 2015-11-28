#include <iostream>

double const MAX_REGULAR_HOURS_PER_WEEK = 40;
double const HOURLY_RATE = 16.78;
double const OVERTIME_HOURLY_RATE = HOURLY_RATE * 1.5;
double const SOC_SEC_WITHHOLD_PERCENTAGE = 0.06;
double const FED_WITHHOLD_PERCENTAGE = 0.14;
double const STATE_WITHHOLD_PERCENTAGE = 0.05;
double const UNION_WEEKLY_DUES = 10;
double const MAX_DEPENDENTS = 2;
double const DEPENDENT_PENALTY = 35;

int main(int argc, const char * argv[]) {

    // input    -> number of hours worked in a week
    //          -> number of dependents
    //
    // output   -> gross pay
    //          -> socsec withholding
    //          -> fed withholding
    //          -> state withholding
    //          -> net pay

    int hoursWorked, totalDependents, dependentDeduction;
    float regularPay, overtimePay, grossPay, socDeduction, fedDeduction, stateDeduction;

    std::cout << "Enter total number of hours worked in a week. ";
    std::cin >> hoursWorked;

    std::cout << "Enter total number of dependents. ";
    std::cin >> totalDependents;

    regularPay = hoursWorked * HOURLY_RATE;
    overtimePay = hoursWorked > MAX_REGULAR_HOURS_PER_WEEK ? (hoursWorked - MAX_REGULAR_HOURS_PER_WEEK) * OVERTIME_HOURLY_RATE : 0;
    grossPay = regularPay + overtimePay;
    socDeduction = grossPay * SOC_SEC_WITHHOLD_PERCENTAGE;
    fedDeduction = grossPay * FED_WITHHOLD_PERCENTAGE;
    stateDeduction = grossPay * STATE_WITHHOLD_PERCENTAGE;
    dependentDeduction = totalDependents > MAX_DEPENDENTS ? DEPENDENT_PENALTY : 0;

    std::cout << "Gross pay: $" << grossPay << std::endl;
    std::cout << "Social Security wholding: $" << socDeduction << std::endl;
    std::cout << "Federal wholding: $" << fedDeduction << std::endl;
    std::cout << "State wholding: $" << stateDeduction << std::endl;
    std::cout << "Net pay: $" << grossPay - socDeduction - fedDeduction - stateDeduction - UNION_WEEKLY_DUES - dependentDeduction << std::endl;

    return 0;
}
