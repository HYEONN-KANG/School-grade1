#include <iostream>
#include <ctime>
using namespace std;
#include <algorithm>

int main(){
    int arr[10];

    srand(time(0));
    for(int i = 0; i < 10; i++){
        int number;
        number = rand() % 98 + 3;
        arr[i] = number;
    }

    cout << "������ int �迭�� : " ;
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr, arr+10);
    cout << "�� �� ���� ū 3���� ���� ";
    for(int i = 9; i >= 7; i--){
        cout << arr[i] << " ";
    }cout << "�Դϴ�" << endl;
}
