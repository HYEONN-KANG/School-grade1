/*
Write a program that calculates area of circle
Write two functions using call by value and call by reference
Define PI=3.14 using const type or #define
area of circle = r*r*PI
prototype: double getArea(double r)
prototype: double getArea(double*)
*/
#include <iostream>
using namespace std;

const double PI = 3.14;

double getArea(double r);
double getArea(double*);

int main(){
    double r;
    cout << "Input value r: ";
    cin >> r;

    cout << "area of circle" << endl;
    cout << "call by value: " << getArea(r) << endl;
    cout << "call by reference: " << getArea(&r) << endl;
}

double getArea(double r){
    return r*r*PI;
}

double getArea(double *r){
    return (*r)*(*r)*PI;
}