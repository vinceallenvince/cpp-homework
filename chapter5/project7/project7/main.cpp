//
// Vince Allen 10/28/2015
//
// Chapter 5, Project 7
//
// Generate a text-based histogram for a quiz given to a class of students. The quiz is
// graded from a scale from 0 to 5. Write a program that allows the user to enter grades
// for each student.
//
// As the user enters grades, the program should count, using an array, the number of 0's,
// the number of 1's, the number of 2's, the number of 3's, the number of 4's, and the
// number of 5's. The program should be capable of handling an arbitrary number of grades.
//
// Output the histogram count at the end. For exmaple, if the input grades are 3, 0, 1, 3,
// 3, 5, 5, 4, 5, 4, then the program should output.
//
// 1 grade(s) of 0
// 1 grade(s) of 1
// ...
//
// OUTPUT:
//
// Enter grade for student #0: 3
// Enter grade for student #1: 4
// Enter grade for student #2: 3
// Enter grade for student #3: 5
// Enter grade for student #4: 3
// Enter grade for student #5: 2
// Enter grade for student #6: 3
// Enter grade for student #7: 3
// Enter grade for student #8: 2
// Enter grade for student #9: 0
//
// Totals:
//
// 1 grade(s) of 0
// 0 grade(s) of 1
// 2 grade(s) of 2
// 5 grade(s) of 3
// 1 grade(s) of 4
// 1 grade(s) of 5
//

#include <iostream>
#include <iomanip>
using namespace std;

#define NDEBUG
#include <assert.h>

const int MAX_GRADE = 6;
const int TOTAL_STUDENTS = 10;

void initializeGrades(int grades[][1], const int maxGrade, const int totalStudents);
void updateGrades(int grade, int grades[][1]);
void displayGrades(int grades[][1], const int maxGrade);

int main(int argc, const char * argv[]) {

    int grades[MAX_GRADE][1];
    int totalGraded = 0;
    int currentGrade;

    initializeGrades(grades, MAX_GRADE, TOTAL_STUDENTS);

    while (totalGraded < TOTAL_STUDENTS) {
        cout << "Enter grade for student #" << totalGraded << ": ";
        cin >> currentGrade;
        updateGrades(currentGrade, grades);
        totalGraded++;
    }

    displayGrades(grades, MAX_GRADE);

    return 0;
}

/**
 * Zereos out all values in the grading matrix.
 * @param grades[][] A maxtrix of grades
 * @param maxGrade The maximum grade
 * @param totalStudents The total students to grade
 */
void initializeGrades(int grades[][1], const int maxGrade, const int totalStudents) {
    int *ptr = &grades[0][0];
    for (int y = 0; y < maxGrade; ++y) {
        for (int x = 0; x < totalStudents; ++x) {
            *ptr++ = 0;
        }
    }
}

/**
 * Increments the total number of grades matching the passed grade.
 * @parm grade A grade
 * @param grades[][] A maxtrix of grades
 */
void updateGrades(int grade, int grades[][1]) {
    grades[grade][0]++;
}

/**
 * Renders the grading matrix.
 * @param grades[][] A maxtrix of grades
 * @param maxGrade The maximum grade
 */
void displayGrades(int grades[][1], const int maxGrade) {
    cout << endl;
    cout << "Totals: " << endl << endl;
    for (int i = 0; i < maxGrade; ++i) {
        int totalGrades = grades[i][0];
        cout << totalGrades << " grade(s) of " << i << endl;
    }
}
