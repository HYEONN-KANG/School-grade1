/*
a, b, c, d를 랜덤으로 100개 생성하여 출력
a, b, c, d의 생성 횟수를 출력
[가장 많이 생성된 알파벳은 : a 입니다]의 방식으로 가장 많이 생성된 알파벳을 출력
*/

#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

int main(){
    srand(time(0));
    int count_a = 0, count_b = 0, count_c = 0, count_d = 0; // a = 1, b = 2, c = 3, d = 4

    int num;
    for(int i = 0; i < 100; i++){
        num = rand() % 4 + 1;
        switch(num){
            case 1:
                cout << "a";
                count_a++;
                break;
            case 2:
                cout << "b";
                count_b++;
                break;
            case 3:
                cout << "c";
                count_c++;
                break;
            case 4:
                cout << "d";
                count_d++;
                break;
        } cout << endl;
    }
    cout << "생성횟수 : a-" << count_a << " b-" << count_b << " c-" << count_c << " d-" << count_d << endl;
    int a = max(count_a, count_b);
    int b = max(count_c, count_d);
    if(a > b){
        if(a = count_a) cout << "[가장 많이 생성된 알파벳은 : a 입니다]" << endl;
        else cout << "[가장 많이 생성된 알파벳은 : b 입니다]" << endl;
    }
    if(b > a){
        if(b = count_c) cout << "[가장 많이 생성된 알파벳은 : c 입니다]" << endl;
        else cout << "[가장 많이 생성된 알파벳은 : d 입니다]" << endl;
    }
}