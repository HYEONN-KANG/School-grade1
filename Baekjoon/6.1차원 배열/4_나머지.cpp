// 아직 못품.

#include <iostream>
using namespace std;

int main(){
    int arr[10];
    for(int i = 0; i < 10; i++){
        cin >> arr[i];
    }

    // 입력받은 수를 42로 나눈 나머지 배열 선언
    int namuji[10];
    for(int i = 0; i < 10; i++){
        namuji[i] = 42;
    }
    for(int i = 0; i < 10; i++){
        namuji[i] = arr[i] % 42;
    }

    // 나머지 배열 수 중 서로 다른 값의 수를 세기
    int count = 0;
    int sum = 0;

    for(int j = 0; j <= 41; j++){
        for(int i = 0; i < 10; i++){
            if(namuji[i] - j == 0) count++;
        }
        if(count != 0) sum++;
        count = 0;
    }

    cout << sum << "\n";
}