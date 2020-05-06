/*
ppt 17~18page 샘플코드를 참고하여 size가 100인 배열을 생성하고 배열의 value는 5~15사이의 값을 랜덤으로 생성하여 값을 부여하고, 
19페이지의 출력의 형태와 동일하게 5~15사이의 값의 출현 횟수를 출력하고, 
마지막에 "가장 많이 출현된 수는 5이고, 출현 횟수는 20입니다" 처럼 가장 많이 출현된 수와 출현 횟수를 출력
*/
#include <iostream>
#include <ctime>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

int main(){
    int arr[100];

    srand(time(0));
    int i = 0;
    while(i < 100){
        arr[i] = rand() % 11 + 5;
        i++;
    }

    int frequency[11+5] = {0};
    for(int answer = 0; answer < 100; answer++){
        ++frequency[arr[answer]];
    }

    cout << "Rating" << setw(17) << "Frequency" << endl;
    for(int rating = 5; rating < 16; rating++){
        cout << setw(6) << rating << setw(17) << frequency[rating] << endl;
    }
    
    int max = frequency[5];
    int num = 5;
    for(int i = 5; i < 16; i++){
        if(frequency[i] > max){
            max = frequency[i];
            num = i;
        }
    }

    cout << "가장 많이 출현된 수는 " << num << " 이고, 출현 횟수는 " << max << " 입니다. " << endl;
    
    return 0;
}