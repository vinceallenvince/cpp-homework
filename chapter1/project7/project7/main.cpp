/**
 * Vince Allen
 *
 * Chapter 1, Project 7
 * Inputs a subject's weight in pounds, the number of METS for an activity,
 * and the number of minutes spent on that activitym.
 * Output an estimate for the total number of calories burned.
 * 1 kilogram = 2.2 pounds
 * Calories/Minute = 0.0175 X MET X Weight (Kg)
 */

double const CAL_MIN_CONST = 0.0175;
double const POUNDS_PER_KILOGRAM = 2.2;

#include <iostream>

int main(int argc, const char * argv[]) {

    double weightInPounds, totalMets, totalMinutes;

    std::cout << "How much do you weight in pounds? ";
    std::cin >> weightInPounds;

    std::cout << "Enter the total METS for an activity. ";
    std::cin >> totalMets;

    std::cout << "Enter the total minutes for an activity. ";
    std::cin >> totalMinutes;

    double totalCaloriesBurned = CAL_MIN_CONST * totalMets * (weightInPounds / POUNDS_PER_KILOGRAM) * totalMinutes;

    std::cout << "You will burn " << totalCaloriesBurned << " calories after your activity." << std::endl;

    return 0;
}
