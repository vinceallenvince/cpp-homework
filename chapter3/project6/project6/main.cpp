/**
 * Vince Allen
 *
 * Chapter 3, Project 6
 * Compute the average and standard deviation of four scores.
 * standard deviation = square root of the average of four values
 */

#include <iostream>
#include <cmath>

double analyzeScores(double score1, double score2, double score3, double score4, bool isAvg, bool isStdDev);
double averageScores(double score1, double score2, double score3, double score4);
double standardDeviationScores(double avg);

int main(int argc, const char * argv[]) {

    char again = 'Y';
    double score1, score2, score3, score4;

    while (again != 'n' && again != 'N') {
        std::cout << "Enter the first score: ";
        std::cin >> score1;

        std::cout << "Enter the second score: ";
        std::cin >> score2;

        std::cout << "Enter the third score: ";
        std::cin >> score3;

        std::cout << "Enter the fourth score: ";
        std::cin >> score4;

        std::cout << "The average of your scores is: " << analyzeScores(score1, score2, score3, score4, true, false) << std::endl;
        std::cout << "The standard deviation of your scores is: " << analyzeScores(score1, score2, score3, score4, false, true) << std::endl;

        std::cout << "Again (Y or n) ";
        std::cin >> again;
    }

    return 0;
}

double analyzeScores(double score1, double score2, double score3, double score4, bool isAvg, bool isStdDev) {
    double avg = averageScores(score1, score2, score3, score4);
    if (isAvg) {
        return avg;
    }
    return standardDeviationScores(avg);
}

double averageScores(double score1, double score2, double score3, double score4) {
    return (score1 + score2 + score3 + score4) / 4;
}

double standardDeviationScores(double avg) {
    return sqrt(avg);
}
