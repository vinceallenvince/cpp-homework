//
//  Vince Allen
//  Chapter 7, Project 8
//
//  Write a program that outputs a histogram of grades for an assignment. The program
//  should input each grade as an integer and store the grade in a vector. Grades should
//  be entered until the user enters -1 for a grade. The program should then scan
//  through the vector and compute the histogram. In computing the histogram, the minimum
//  value of a grade is 0. Your program should determine the max value entered by the
//  user. Output the histogram to the console.
//
//  OUTPUT:
//
//  Enter a grade bw 0 and 100 (-1 to quit): 30
//  Enter a grade bw 0 and 100 (-1 to quit): 27
//  Enter a grade bw 0 and 100 (-1 to quit): 17
//  Enter a grade bw 0 and 100 (-1 to quit): 41
//  Enter a grade bw 0 and 100 (-1 to quit): 28
//  Enter a grade bw 0 and 100 (-1 to quit): 31
//  Enter a grade bw 0 and 100 (-1 to quit): -1
//
//  Max grade: 41
//
//  All results:
//  ****************************** 30
//
//  *************************** 27
//
//  ***************** 17
//
//  ***************************************** 41
//
//  **************************** 28
//
//  ******************************* 31
//

#include <iostream>
#include <iomanip>
#include <vector>
using namespace::std;

int getMaxGrade(vector<int> v);

int main(int argc, const char * argv[]) {

    int grade;

    vector<int> v;

    while (grade != -1) {
        if (grade) v.push_back(grade);
        cout << "Enter a grade bw 0 and 100 (-1 to quit): ";
        cin >> grade;
    }

    cout << endl;
    cout << "Max grade: " << getMaxGrade(v) << endl;
    cout << endl;
    cout << "All results: " << endl;
    long l = v.size();
    for (int i = 0; i < l; ++i) {
        int val = v[i];
        cout << left << setw(val) << setfill('*') << "" << " " << val << endl;
        cout << endl;
    }

    return 0;
}

int getMaxGrade(vector<int> v) {
    int max = 0;
    long l = v.size();
    for (int i = 0; i < l; ++i) {
        int val = v[i];
        if (val > max) max = val;
    }
    return max;
};
