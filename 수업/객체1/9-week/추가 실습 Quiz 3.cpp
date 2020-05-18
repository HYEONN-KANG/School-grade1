/*
3.  Char배열을 생성하고 키보드로 space가 없이 입력된 값을 char 배열에 입력하고, 
    가장 작은 char를 맨 앞의 위치로 옮기고 a앞의 char를 배열의 뒤로 복사하여 새로운 배열 생성 및 출력.

     char 배열을 입력하세요: kadswilmbc

     새로 생성된 char : adswilmbck
*/

#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

int minArray(char [], int);
void replace1(char [], int, int);

int main(){
    char a[30];
    cout << "char 배열을 입력하세요: ";
    cin >> a;

    // min index 찾기
    int where = minArray(a, strlen(a));

    // 정렬하기
    replace1(a, strlen(a), where);

    // 출력하기
    cout << "새로 생성된 char:" << setw(8);
    for(int i = 0; i < strlen(a); i++){
        cout << a[i];
    }cout << endl;
}

// min index 찾기
int minArray(char arr[], int len){
    char min = arr[0];
    int index = 0;

    for(int i = 1; i < len; i++){
        if(arr[i] < min){
            min = arr[i];
            index = i;
        }
    }

    return index;
}

// 정렬하기
void replace1(char arr[], int len, int whereMin){
    // min 포함 뒤에 있는 글자들을 b에 저장
    char b[len-whereMin];
    for(int i = 0; i < len-whereMin; i++){
        b[i] = arr[whereMin + i];
    }

    // min 앞에 있는 글자 뒤로 보내기
    for(int i = 0; i < whereMin; i++){
        arr[len-whereMin+i] = arr[i];
    }

    // b에 있는 것을 앞으로 보내기
    for(int i = 0; i < len-whereMin; i++){
        arr[i] = b[i];
    }
}