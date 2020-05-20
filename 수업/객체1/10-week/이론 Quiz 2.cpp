/*
ppt 65~71 코드 구현해보고, 각각의 퀴즈별 평균을 계산하는 함수를 추가, 각 퀴즈의 평균 점수를 출력
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int students = 3;
const int exams = 4;

int minimum(int [][exams], int, int);
int maximum(int [][exams], int, int);
double average(int [], int);
void printArray(int [][exams], int, int);
double QuizAverage(int [][exams], int, int);

int main(){
    int studentGrades[students][exams] =
    {   {77, 68, 86, 73},
        {96, 87, 89, 78},
        {70, 90, 86, 81}};
    
    cout << "The array is:\n";
    printArray(studentGrades, students, exams);

    cout << "\n\nLowest grade: " 
         << minimum(studentGrades, students, exams)
         << "\nHighhest grades: "
         << maximum(studentGrades, students, exams) << "\n\n";

    cout << fixed << setprecision(2);

    for(int person = 0; person < students; person++){
        cout << "The average grade for student " << person
             << " is "
             << average(studentGrades[person], exams)
             << endl;
    }
    cout << endl;

    for(int tests = 0; tests < exams; tests++){
        cout << "The average grade for exam " << tests
             << " is "
             << QuizAverage(studentGrades, students, tests)
             << endl;
    }

    return 0;
}

int minimum(int grades[][exams], int pupils, int tests){
    int lowGrade = 100;

    for(int i = 0; i < pupils; i++){
        for(int j = 0; j < tests; j++){
            if(grades[i][j] < lowGrade)     lowGrade = grades[i][j];
        }
    }

    return lowGrade;
}

int maximum(int grades[][exams], int pupils, int tests){
    int highGrade = 0;

    for(int i = 0; i < pupils; i++){
        for(int j = 0; j < tests; j++){
            if(grades[i][j] > highGrade)    highGrade = grades[i][j];
        }
    }

    return highGrade;
}

double average(int setOfGrades[], int tests){
    int total = 0;

    for(int i = 0; i < tests; i++){
        total += setOfGrades[i];
    }

    return static_cast<double>(total) / tests;
}

void printArray(int grades[][exams], int pupils, int tests){
    cout << left << "                [0]  [1]  [2]  [3]";

    for(int i = 0; i < pupils; i++){
        cout << "\nstudentGrade[" << i << "] ";

        for(int j = 0; j < tests; j++){
            cout << setw(5) << grades[i][j];
        }
    }
}

double QuizAverage(int setOfGrades[][exams], int pupils, int tests){
    int average;
    for(int j = 0; j < pupils; j++){
        average += setOfGrades[j][tests];
    }
    return static_cast<double>(average) / pupils;
}
