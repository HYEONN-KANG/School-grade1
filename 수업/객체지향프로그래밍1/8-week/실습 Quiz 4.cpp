#include <iostream>
using namespace std;

int main(){

    char arr[100];
    cout << "char 배열을 입력하세요 : ";
    cin >> arr;

    const int number = strlen(arr);

    char temp[number];

    for(int i = 0; i < number; i++){
        temp[i] = arr[number-(i+1)];
    }

    cout << "거꾸로 배열을 생성하였고 배열은 : " << temp << endl;
}