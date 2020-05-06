/*
ppt 15~16page 샘플코드를 참고하여 size가 20인 배열을 생성하고, 배열의 value는 0~20사이의 값을 랜덤으로 생성하여 값을 부여하고,
16페이지의 출력의 형태와 동일하게 배열 값만큼 별표를 출력.
*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main(){
    int arr[20]; // 배열 선언

    int i = 0;
    srand(time(0));
    while(i < 20){
        arr[i] = rand() % 21;
        i++;   // 배열 값 초기화
    }

    cout << "Element" << setw(13) << "Value" << setw(17) << "Printstars" << endl;
    for(int i = 0 ; i < 20; i++){
        cout << setw(7) << i << setw(13) << arr[i] << setw(9);

        for(int j = 0; j < arr[i]; j++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}