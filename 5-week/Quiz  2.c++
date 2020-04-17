#include <iostream>
#include <cmath>

void printCmath(double);

using namespace std;

int main(){
    double x;
    cout << "Input x : ";
    cin >> x;

    printCmath(x);
}

void printCmath(double num){
    cout << "ceil(x) : " << ceil(num) << endl;
    cout << "exp(x) : " << exp(num) << endl;
    cout << "log(x) : " << log(num) << endl;
    cout << "sqrt(x) : " << sqrt(num) << endl;
    cout << "fabs(x) : " << fabs(num) << endl;
    cout << "pow(x,2) : " << pow(num,2) << endl;
}