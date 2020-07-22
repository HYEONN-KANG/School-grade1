#include <iostream>
using namespace std;

int main(){
    int arr[9];
    for(int i = 0; i < 9; i++){
        cin >> arr[i];
    }

    int max = arr[0];
    int num = 0;

    for(int i = 0; i < 9; i++){
        if(arr[i] > max) {
            max = arr[i];
            num = i;
        }
    }

    cout << max << "\n" << num + 1 << "\n";
}