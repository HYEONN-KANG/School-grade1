#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

const int students = 5;
const int tests = 4;

void printArray(int [][tests], int, int);   // 배열 출력 함수
double average(int [], int);    // 평균 구하는 함수
double standard(int [], int);   // 표준 편차 구하는 함수

int main(){
    int studentGrades[students][tests];

    srand(time(0));
    for(int i = 0; i < students; i++){
        for(int j = 0; j < tests; j++){
            studentGrades[i][j] = rand()%11;
        }
    }

    cout << "The array is:\n";
    printArray(studentGrades, students, tests);
    cout << endl << endl;

    double avg[students];

    for(int person = 0; person < students; person++){
        cout << "The average grade for student " << person
             << " is "
             << average(studentGrades[person], tests)
             << endl;
        avg[person] = average(studentGrades[person], tests);
    }
    cout << endl;

    for(int person = 0; person < students; person++){
        cout << "The standard deviation for student " << person
             << " is "
             << standard(studentGrades[person], tests)
             << endl;
    }
    cout << endl;

    double totalAverage = 0;
    for(int i = 0; i < students; i++){
        totalAverage += avg[i];
    }
    totalAverage = totalAverage / students;

    cout << "The total average of 5 students is "
         << totalAverage << endl;
    
}

double average(int setOfGrades[], int tests){
    int total = 0;

    for(int i = 0; i < tests; i++){
        total += setOfGrades[i];
    }

    return static_cast<double>(total) / tests;
}

void printArray(int grades[][tests], int pupils, int tests){
    cout << left << "               [0]  [1]  [2]  [3]";

    for(int i = 0; i < pupils; i++){
        cout << "\nstudentGrade[" << i << "] ";

        for(int j = 0; j < tests; j++){
            cout << setw(5) << grades[i][j];
        }
    }
}

double standard(int setOfGrades[], int tests){
    int total = 0;

    for(int i = 0; i < tests; i++){
        total += setOfGrades[i];
    }

    int average = static_cast<double>(total) / tests;
    double p, b = 0;

    for(int i = 0; i < tests; i++){
        p = setOfGrades[i] - pow(average, 2);
        b += pow(p, 2);
    }

    b = b / tests;

    return sqrt(b);
}
