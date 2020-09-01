/*
time() 함수를 사용하여 현재 시간을 출력하는 프로그램을 작성하세요.
1초에 한번씩 현재 시간을 출력
Sleep(1000)은 1000밀리세컨드 대기하는 함수.
출력형태 : 13시 5분 10초
못 풀음.
*/

#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int main(){
    while(true){
        long int mytime = (long int)time(0);
        mytime %= (60*60*24);
        int hour, min, sec;
        hour = mytime / (60*60);
        mytime %= (60*60);
        min = mytime / 60;
        sec = mytime % 60;
        (hour + 9 > 24 ? hour = hour + 9 - 24 : hour = hour + 9);

        cout << hour << "h " << min << "min " << sec << "sec" << "\r";
        Sleep(1000);
    }
    return 0;
}