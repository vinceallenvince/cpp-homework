//
// Vince Allen
// Chapter 6, project 1
// Write a grading program for a class with the following policies.
//
// 1. There are two quizzes, each graded on the basis of 10 points.
// 2. There is one midterm exam and one final exam, each graded on the
//    basis of 100 points.
// 3. The final exam counts for 50% of the grade, the midterm counts for
//    25%, and the two quizzes together count for a total of 25%. (Do
//    not forget to normalize the quiz scores. They should be converted
//    to a percentage before they are averaged in.)
//
// Any grade of 90% or more is an A, any grade of 80 or more (but less
// than 90 is a B, any grade of 70 or more (but less than 80) is a C,
// any grade of 60 or more (but less than 70) is a D, and any grade
// below 60 is an F.
//
// The program will read in the student's scores and output the student's
// record, which consists of two quiz and two exam scores as well as
// student's average numeric score for the entire course and final
// letter grade.
//
// Define and use a structure for the student record.
//
// OUTPUT:
//
// Enter a score for the first quiz.
// 8
// Enter a score for the second quiz.
// 7
// Enter a score for the midterm.
// 85
// Enter a score for the final.
// 91
//
// STUDENT RECORD
// Quiz A:       80
// Quiz B:       70
// Midterm:      85
// Final:        91
//
// Average:      85
// Final letter: B
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include "assert.h"
using namespace std;

struct StudentRecord {
    float quizA;
    float quizB;
    float midterm;
    float final;
};

const char LETTER_GRADES[] = {'A', 'B', 'C', 'D', 'F'};
const int TOTAL_LETTER_GRADES = 5;

float mapRange(float val, float min1, float max1, float min2, float max2);
float calculateFinalNumericGrade(float quizA, float quizB, float midterm, float final);
char calculateLetterGrade(int numericGrade, const char letterGrades[], const int totalLetterGrades);
void displayRecord(StudentRecord record, const char letterGrades[], const int totalLetterGrades);

int main(int argc, const char * argv[]) {

    // ASSERTIONS

    StudentRecord tempRecord;
    tempRecord.quizA = 3;
    tempRecord.quizB = 5;
    tempRecord.midterm = 70;
    tempRecord.final = 85;

    assert(floor(mapRange(tempRecord.quizA, 0, 10, 0, 100)) == 30);
    assert(floor(mapRange(tempRecord.quizB, 0, 10, 0, 100)) == 50);
    assert(calculateFinalNumericGrade(tempRecord.quizA, tempRecord.quizB, tempRecord.midterm, tempRecord.final) == 61);
    assert(calculateLetterGrade(100, LETTER_GRADES, TOTAL_LETTER_GRADES) == 'A');
    assert(calculateLetterGrade(99, LETTER_GRADES, TOTAL_LETTER_GRADES) == 'A');
    assert(calculateLetterGrade(90, LETTER_GRADES, TOTAL_LETTER_GRADES) == 'A');
    assert(calculateLetterGrade(89, LETTER_GRADES, TOTAL_LETTER_GRADES) == 'B');
    assert(calculateLetterGrade(80, LETTER_GRADES, TOTAL_LETTER_GRADES) == 'B');
    assert(calculateLetterGrade(79, LETTER_GRADES, TOTAL_LETTER_GRADES) == 'C');
    assert(calculateLetterGrade(70, LETTER_GRADES, TOTAL_LETTER_GRADES) == 'C');
    assert(calculateLetterGrade(69, LETTER_GRADES, TOTAL_LETTER_GRADES) == 'D');
    assert(calculateLetterGrade(60, LETTER_GRADES, TOTAL_LETTER_GRADES) == 'D');
    assert(calculateLetterGrade(59, LETTER_GRADES, TOTAL_LETTER_GRADES) == 'F');
    assert(calculateLetterGrade(20, LETTER_GRADES, TOTAL_LETTER_GRADES) == 'F');

    //

    StudentRecord record;

    cout << "Enter a score for the first quiz." << endl;
    cin >> record.quizA;

    cout << "Enter a score for the second quiz." << endl;
    cin >> record.quizB;

    cout << "Enter a score for the midterm." << endl;
    cin >> record.midterm;

    cout << "Enter a score for the final." << endl;
    cin >> record.final;

    displayRecord(record, LETTER_GRADES, TOTAL_LETTER_GRADES);

    return 0;
}

float mapRange(float val, float min1, float max1, float min2, float max2) {
    double unitratio = (val - min1) / (max1 - min1);
    return (unitratio * (max2 - min2)) + min2;
}

float calculateFinalNumericGrade(float quizA, float quizB, float midterm, float final) {
    return floor((quizA * 0.125) + (quizB * 0.125) + (midterm * 0.25) + (final * 0.5));
}

char calculateLetterGrade(int numericGrade, const char letterGrades[], const int totalLetterGrades) {
    int index = 10 - floor(numericGrade / 10);
    if (index < totalLetterGrades) {
     index = index == 0 ? 1 : index;
    } else {
        index = totalLetterGrades;
    }
    return letterGrades[index - 1];
}

void displayRecord(StudentRecord record, const char letterGrades[], const int totalLetterGrades) {

    float quizA = mapRange(record.quizA, 0, 10, 0, 100);
    float quizB = mapRange(record.quizB, 0, 10, 0, 100);
    float midterm = record.midterm;
    float final = record.final;

    float avgGrade = calculateFinalNumericGrade(quizA, quizB, midterm, final);

    cout << endl;
    cout << "STUDENT RECORD" << endl;
    cout << left << setw(14) << setfill(' ') << "Quiz A: " << quizA << endl;
    cout << left << setw(14) << setfill(' ') << "Quiz B: " << quizB << endl;
    cout << left << setw(14) << setfill(' ') << "Midterm: " << midterm << endl;
    cout << left << setw(14) << setfill(' ') << "Final: " << final << endl;
    cout << endl;
    cout << left << setw(14) << setfill(' ') << "Average: " << avgGrade << endl;
    cout << left << setw(14) << setfill(' ') << "Final letter: " << calculateLetterGrade(avgGrade, letterGrades, totalLetterGrades) << endl;
    cout << endl;
}
