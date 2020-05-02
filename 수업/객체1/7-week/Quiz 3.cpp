/*
컴퓨터와 가위바위보 게임을 하는 프로그램을 작성.
컴퓨터는 임의로 가위바위보를 선택(rand 함수 사용)
EOF를 입력 받을때까지 게임을 계속 진행.
마지막에 전체 게임 횟수, user의 승리 횟수를 출력함.
*/

#include <iostream>
#include <ctime>
using namespace std;

void bobo(int, int&);

int main(){
    cout << "가위바위보 게임을 시작하시겠습니까? 준비됬으면 Enter를 눌러주세요!" << endl;
    getchar();
    system("cls");

    int count = 0;
    int win_count = 0;
    while(!cin.eof()){
        int choose;
        cout << "가위-1, 바위-2, 보-3 : ";
        cin >> choose;

        if (choose <1 || choose>3) {
            cout << "잘못 입력하셨습니다." << endl;
            return 0;
        }
        bobo(choose, win_count);
        count++;
    }
    cout << "총 게임 횟수 : " << count << " user가 이긴 횟수 : " << win_count << endl;
}

void bobo(int choose, int &win_count){
    srand(time(0));
    int com = rand() % 3 + 1;
    switch(com){
        case 1: // 가위
            if(choose == 1) cout << "비겼습니다." << endl;
            else if(choose == 2){
                cout << "이겼습니다." << endl;
                win_count++;
                }
            else cout << "졌습니다." << endl;
            break;
        case 2: // 바위
            if(choose == 1) cout << "졌습니다." << endl;
            else if(choose == 2){
                cout << "비겼습니다." << endl;
                }
            else {
                cout << "이겼습니다." << endl;
                win_count++;
            }
            break;
        case 3: // 보
            if(choose == 1) {
                cout << "이겼습니다." << endl;
                win_count++;
            }
            else if(choose == 2){
                cout << "졌습니다." << endl;
                }
            else cout << "비겼습니다." << endl;
            break;
    }
}