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

    // 나머지 배열 수 중 같은 값의 수를 세기
    int count = 0;

    for(int i = 0; i < 10; i++){
        int num = namuji[i];

        for(int j = 0; j < 10; j++){
            if(i != j && i < j){
                if(num == namuji[j]){
                    count++;
                }
            }
        }
    }

    cout << 10 - count << "\n";
}