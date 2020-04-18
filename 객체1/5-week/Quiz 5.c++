// Write a program to calculate the fibonacci program using function
// Print n-th fibonacci number
#include <iostream>
using namespace std;

int fibonacci(int);

int main(){
    int num;
    cout << "Input n-th fibo num : ";
    cin >> num;

    cout << "n-th fibo num : " << fibonacci(num) << endl; 
}

int fibonacci(int x){
    int arr[100];

    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2; i < 100; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    return arr[x];
}