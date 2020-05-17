#include <iostream>

int main(){
    using namespace std;

    int N;
    cin >> N;

    int grade[100];
    for(int i = 0; i < N; i++){
        cin >> grade[i];
    }

    // M값 구하기
    int M;
    M = grade[0];
    for(int i = 1; i < N; i++){
        if(grade[i] > M) M = grade[i];
    }

    // 시험 성적 바꾸기
    for(int i = 0; i < N; i++){
        grade[i] = (static_cast<float>(grade[i]) / M) * 100;
    }

    // 바뀐 시험 성적 평균 구하기
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += grade[i];
    }
    cout << sum << endl;
}