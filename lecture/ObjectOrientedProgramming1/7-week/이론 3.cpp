/*
Generate Absolute value program.
Write a function that convert input to absolute value.
And Overload function with int, double, long int type.
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int absolute(int);
double absolute(double);
long int absolute(long int);

int main(){
    cout << "abs int num of -10 = " << absolute(-10) << endl;
    cout << "abs double num of -3.4 = " << absolute(-3.4) << endl;
    cout << "abs long int num of -20 = " << absolute(-20) << endl;
}

int absolute(int number){
    return abs(number);
}

double absolute(double number){
    return abs(number);
}

long int absolute(long int number){
    return abs(number);
}