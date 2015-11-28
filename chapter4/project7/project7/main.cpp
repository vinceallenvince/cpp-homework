/**
 * Vince Allen
 *
 * Chapter 4, Project 7
 * Convert lbs/ounces to kilograms/grams.
 *
 * Output:
 * Input pounds.
 * 17
 * Input ounces.
 * 59
 * Metric conversion: 5:59p
 * Again (Y or n)
 */

#include <iostream>

void inputTime(int &input, char desc[]);
void convertTime(int inputHours, int inputMins, int &outputHours, int &outputMins, char &indicator);
void displayTime(int outputHours, int outputMins, char indicator);

int main(int argc, const char * argv[]) {

    int inputHours, inputMins, outputHours, outputMins;
    char hours[] = "hours";
    char minutes[] = "minutes";
    char indicator;

    char again = 'Y';
    while (again != 'n' && again != 'N') {
        inputTime(inputHours, hours);
        inputTime(inputMins, minutes);
        convertTime(inputHours, inputMins, outputHours, outputMins, indicator);
        displayTime(outputHours, outputMins, indicator);

        std::cout << "Again (Y or n) ";
        std::cin >> again;
    }

    return 0;
}

void inputTime(int &input, char desc[]) {
    std::cout << "Input 24hr notation " << desc << "." << std::endl;
    std::cin >> input;
}

void convertTime(int inputHours, int inputMins, int &outputHours, int &outputMins, char &indicator) {
    indicator = 'a';
    outputHours = inputHours;
    if (inputHours > 12) {
        outputHours = inputHours - 12;
        indicator = 'p';
    }
    outputMins = inputMins;
}

void displayTime(int outputHours, int outputMins, char indicator) {
    std::cout << "12hr conversion: " << outputHours << ":" << outputMins << indicator << std::endl;
}

