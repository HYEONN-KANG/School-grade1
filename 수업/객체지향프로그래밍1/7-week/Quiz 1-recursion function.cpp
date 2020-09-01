/*
Write a recursive function in C to find GCD of two numbers. How to find GCD(Greatest Common Divisor) of two numbers using recursion in C++ program.
*/

#include <iostream>
using namespace std;

int gcd(int, int);

int main(){
    int num1, num2;
    cout << "Enter any two numbers to find GCD : ";
    cin >> num1 >> num2;

    cout << "GCD of " << num1 << " and " << num2 << " = " << gcd(num1, num2) << endl;
}

int gcd(int num1, int num2){
    if(num1 > num2){
        if(num1 % num2) return num2;
        else{
            return gcd(num2, num1 % num2);
        }
    }
    else if(num2 > num1){
        if(num2 % num1) return num1;
        else{
            return gcd(num1, num2 % num1);
        }
    }
    else{
        return num1;
    }
}