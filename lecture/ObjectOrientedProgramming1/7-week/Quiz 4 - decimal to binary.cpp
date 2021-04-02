// Write a program to convert decimal number to binary number
#include <iostream>
using namespace std;

void convert(int);

int main(){
    int decimal;
    cout << "Input decimal num : ";
    cin >> decimal; 

    cout << "to binary.. : ";
    convert(decimal);
    cout << endl;
}

void convert(int decimal){
    if(decimal == 0 || decimal == 1) cout << decimal % 2;
    else{
        convert(decimal / 2);
        cout << decimal % 2;
    }
}