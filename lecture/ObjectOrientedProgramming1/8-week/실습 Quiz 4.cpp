#include <iostream>
using namespace std;

int main(){

    char arr[100];
    cout << "char �迭�� �Է��ϼ��� : ";
    cin >> arr;

    const int number = strlen(arr);

    char temp[number];

    for(int i = 0; i < number; i++){
        temp[i] = arr[number-(i+1)];
    }

    cout << "�Ųٷ� �迭�� �����Ͽ��� �迭�� : " << temp << endl;
}