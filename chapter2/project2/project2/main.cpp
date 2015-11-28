/**
 * Chapter 2, Project 2
 * Calculate total payments needed to pay off a loan of $1000 with
 * an interest rate of %18.
 */

#include <iostream>
#include <assert.h>

double const TOTAL_COST = 1000.00;
double const ANNUAL_INTEREST_RATE = 18.0;
double const MONTHLY_INTEREST_RATE = ANNUAL_INTEREST_RATE / 12.0;
double const MONTHLY_PAYMENT = 50.00;

double makePayment(double currentBalance);

int main(int argc, const char * argv[]) {

    assert(makePayment(1000.0) == 965.0);

    double currentBalance = TOTAL_COST;
    int paymentNumber = 0;
    for (; currentBalance > 0; paymentNumber++) {
        currentBalance = makePayment(currentBalance);
    }

    std::cout << "You will pay off your debt in " << paymentNumber << " months with $" << MONTHLY_PAYMENT << " payments each month.";

    return 0;
}

double makePayment(double currentBalance)
{
    return currentBalance - (MONTHLY_PAYMENT - (currentBalance * MONTHLY_INTEREST_RATE * 0.01));
}
