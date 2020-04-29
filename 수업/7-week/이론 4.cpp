/*
Use Template instead of function overloading to solve 이론 3.
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

template <typename T>
T absolute(T number){
    return abs(number);
}

int main(){
    cout << "abs int num of -10 = " << absolute(-10) << endl;
    cout << "abs double num of -3.4 = " << absolute(-3.4) << endl;
    cout << "abs long int num of -20 = " << absolute(-20) << endl;
}

