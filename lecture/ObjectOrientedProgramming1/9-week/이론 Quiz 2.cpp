/*
-배열의 값을 랜덤값으로 셋팅하는 함수를 구현.
-배열 출력 함수 구현.
-max 값을 찾는 함수를 구현하고 출력창에 max 값 출력.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int arrayRand(int [], const int);
void OriginalArray(int [], const int);
int arrayMax(int [], const int);

int main(){
    const int arraySize = 100;
    int a[arraySize];

    arrayRand(a, arraySize);

    OriginalArray(a, arraySize);

    int max = arrayMax(a, arraySize);

    cout << "\nMax value in array :" << setw(4) << max << endl;
}

#include <ctime>

int arrayRand(int array[], const int sizeOfArray){

    srand(time(0));

    for(int i = 0; i < sizeOfArray; i++){
        array[i] = rand() % 101;
    }
}

void OriginalArray(int arr[], const int sizeOfArray){
    cout << "Original :" << setw(4);
    for(int i = 0; i < sizeOfArray; i++){
        cout << arr[i] << " ";
    }
}

int arrayMax(int arr[], const int sizeOfArray){
    int max = arr[0];
    for(int i = 0; i < sizeOfArray; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}
