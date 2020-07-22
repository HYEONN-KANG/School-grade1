#include <iostream>
#include <string.h>
using namespace std;

void changeArray(char [], int [], int);
int dialTime(int []);

int main(){
    char arr[16];
    cin >> arr;

    int num[10] = {0};

    // 입력받은 문자를 숫자로 변환
    changeArray(arr, num, strlen(arr));

    // 필요한 시간 계산
    cout << dialTime(num) << endl;
}

void changeArray(char arr[], int num[], int len){
    for(int i = 0; i < strlen(arr); i++){
        // num[(int)arr[i] - 65 + 2]++;
        if((int)arr[i] >= 87){
            num[9]++;
        }
        else if((int)arr[i] >= 80 && (int)arr[i] <= 83){
            num[7]++;
        }
        else if((int)arr[i] >= 84 && (int)arr[i] <= 86){
            num[8]++;
        }
        else{
            for(int j = 2; j < 7; j++){
                if((int)arr[i] >= 65 + (j - 2)*3 && (int)arr[i] <= 67 + (j - 2)*3){
                    num[j]++;
                }
            }
        }
    }
}

int dialTime(int num[]){
    int time = 0;
    for(int i = 2; i < 10; i++){
        time += (i + 1) * num[i];
    }

    return time;
}