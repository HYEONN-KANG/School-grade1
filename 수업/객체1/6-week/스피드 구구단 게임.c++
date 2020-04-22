#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void gugudan();

int main(){
    cout << "[스피드 구구단 게임]" << endl << endl
        << "당신의 구구단 실력을 테스트 하세요." << endl
        << "10번 테스트 하겠습니다." << endl
        << "준비되면 엔터를 누르세요." << endl;
    getchar();
    system("cls");

    gugudan(); // 구구단 게임 함수
}

void gugudan(){
    time_t start, end;
    double usedTime;
    
    start = time(NULL); // 게임 스타트 시간 저장
    srand(start);
    
    int score = 0;
    int correct = 1;

    // 문제 10개 랜덤으로 출제
    for(int i = 1; i <= 10; i++){
        int num1 = (rand() % 10) + 1;
        int num2 = (rand() % 10) + 1;
        int output;

        cout << "문제 " << i << ":" << setw(2)
        << num1 << "*" << num2 << " = " ;
        cin >> output;
        if(output != num1*num2){
            cout << "틀렸습니다." << endl;
            correct = 0;
        }
        score++;
    }
    end = time(NULL);   // 게임 종료 시간 저장
    usedTime = static_cast<double>(end - start);    // 게임 이용 시간 저장

    if(correct == 1){
        cout << "점수는 " << score << " 게임 이용 시간은 " << usedTime << "초" << endl;
    }else{
        cout << "점수는 0" << " 게임 이용 시간은 " << usedTime << "초" << endl;
    }
    
}
