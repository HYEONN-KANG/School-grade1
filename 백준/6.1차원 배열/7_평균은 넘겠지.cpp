#include <iostream>
#include <cmath>
#include <iomanip>

int main(){
    using namespace std;

    int test_case, students_num, grade[1000];
    cin >> test_case;

    int sum;
    double average, result;

    // test_case의 수만큼 반복
    for(int i = 0; i < test_case; i++){
        cin >> students_num;

        sum = 0;
        for(int i = 0; i < students_num; i++){
            cin >> grade[i];
            sum += grade[i];
        }

        // 평균 구하기
        average = (double)sum / students_num;

        // 비율 구하기
        int up_students = 0;
        for(int i = 0; i < students_num; i++){
            if(grade[i] > average) up_students++;
        }

        result = (double(up_students) / students_num) * 100;

        cout.setf(ios::fixed);
        cout << setprecision(3) << round(result*1000)/1000 << "%" << endl;
    }
}