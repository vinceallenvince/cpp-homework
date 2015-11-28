/**
 * Vince Allen
 *
 * Chapter 4, Project 4
 * Convert feet/inches to meters/centimeters.
 * 0.3048 meters in  a foot, 100 cm / m, 12 in/ft
 *
 * Output:
 * Input length in feet.
 * 10
 * Input length in inches.
 * 3
 * Metric conversion: 3m 12cm
 * Again (Y or n)
 */

#include <iostream>

const char inputPrompt[] = "Input length in ";
const char convertedPrefix[] = "Metric conversion: ";
const double METERS_PER_FOOT = 0.3048;
const int CENTIMETERS_PER_METER = 100;
const double CENTIMETERS_PER_FOOT = METERS_PER_FOOT * CENTIMETERS_PER_METER;
const int INCHES_PER_FOOT = 12;
const double CENTIMETERS_PER_INCH = CENTIMETERS_PER_FOOT / INCHES_PER_FOOT;

void inputValue(int &input, char desc[]);
void convertValue(int inputValueA, int inputValueB, int &outputValueA, int &outputValueB);
void displayConvertedValue(int outputHours, int outputMins);

int main(int argc, const char * argv[]) {

    int inputValueA, inputValueB, outputValueA, outputValueB;
    char inputValueAType[] = "feet";
    char inputValueBType[] = "inches";

    char again = 'Y';
    while (again != 'n' && again != 'N') {
        inputValue(inputValueA, inputValueAType);
        inputValue(inputValueB, inputValueBType);
        convertValue(inputValueA, inputValueB, outputValueA, outputValueB);
        displayConvertedValue(outputValueA, outputValueB);

        std::cout << "Again (Y or n) ";
        std::cin >> again;
    }

    return 0;
}

void inputValue(int &input, char desc[]) {
    std::cout << inputPrompt << desc << "." << std::endl;
    std::cin >> input;
}

void convertValue(int inputValueA, int inputValueB, int &outputValueA, int &outputValueB) {

    // convert feet to inches
    int totalInches = inputValueA * INCHES_PER_FOOT;

    // add remaining inches
    totalInches += inputValueB;

    // convert inches to centimeters
    int centimeters = totalInches * CENTIMETERS_PER_INCH;

    // divide by 100 for m
    outputValueA = centimeters / CENTIMETERS_PER_METER;

    // mod by 100 for cm
    outputValueB = centimeters % CENTIMETERS_PER_METER;
}

void displayConvertedValue(int outputValueA, int outputValueB) {
    std::cout << convertedPrefix << outputValueA << "m " << outputValueB << "cm " << std::endl;
}

