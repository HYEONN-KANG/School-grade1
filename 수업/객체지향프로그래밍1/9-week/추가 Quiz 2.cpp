// char 타입의 array1과 array2를 키보드로 입력받고, 두 개의 array가 동일한지 판단하여 결과 출력.

#include <iostream>
#include <iomanip>

using namespace std;

void originArray(char [], char [], int);
int compareArray(char [], char [], int);

int main(){
    char array1[10];
    char array2[10];

    for(int i = 0; i < 10; i++){
        cin >> array1[i] >> array2[i];
    }

    // array1과 array2 출력하기
    originArray(array1, array2, 10);

    // array1과 array2 비교하기
    int result = compareArray(array1, array2, 10);

    if(result == 1) cout << "array1과 array2는 동일합니다." << endl;
    else if(result == -1) cout << "array1과 array2는 동일하지 않습니다." << endl;
}

void originArray(char array1[], char array2[], int sizeofArray){
    cout << "Original array1:" << setw(4);
    for(int i = 0; i < sizeofArray; i++){
        cout << array1[i] << " ";
    }cout << endl;

    cout << "Original array2:" << setw(4);
    for(int i = 0; i < sizeofArray; i++){
        cout << array2[i] << " ";
    }cout << endl;
}

int compareArray(char array1[], char array2[], int sizeofArray){
    for(int i = 0; i < sizeofArray; i++){
        // 하나라도 값이 다르면 -1 반환
        if(array1[i] != array2[i]) return -1;  
    }
    // 모두 같으면 1 반환
    return 1;
}