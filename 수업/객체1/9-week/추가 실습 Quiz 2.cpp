/*
2.Char배열을 생성하고 키보드로 space가 없이 입력된 값(중복이 없음.)을 char 배열에 입력하고, char 배열을 버블 sorting 방법으로 정렬하여 출력하세요.
     char 배열을 입력하세요: kadswilmbc

     정렬 후 char : abcdiklmsw
*/

#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
void bubbleSort(char [], int);

int main(){

    char a[30];
    cout << "char 배열을 입력하세요: ";
    cin >> a;

    // bubble sorting
    bubbleSort(a, strlen(a));

    return 0;
}

void bubbleSort(char arr[], int len){
    char temp; 
    int exchange = 0;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len - 1; j++){
            if((int)arr[j] > (int)arr[j+1]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            exchange++;
        }
        }

        if(exchange == 0){
            cout << "정렬 후 char : " << setw(10);
            for(int i = 0; i < len; i++){
                cout << arr[i];
            }cout << endl;

            break;
        }

        exchange = 0;
    }
}