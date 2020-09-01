// Modify calculator program(week 5) using inline functions.
// convert function sum(), substract(), multiply(), division() to inline function.

#include <iostream>
#include <cmath>

using namespace std;

void calculator(float, float, int);

inline float sum(const float num1, const float num2){
    return num1 + num2;
}
inline float substract(const float num1, const float num2){
    return num1 - num2;
}
inline float multiply(const float num1, const float num2){
    return num1 * num2;
}
inline float division(const float num1, const float num2){
    return num1 / num2;
}

int main(){
    float x, y;
    cout << "Input 2 floats : ";
    cin >> x >> y;
    
    int Choose;
    cout << "Select" << endl
        << "sum - 1, "
        << "subtract - 2, "
        << "multiply - 3, "
        << "division - 4 : ";
    cin >> Choose;

    calculator(x, y, Choose);
}

void calculator(float num1, float num2, int select){
    switch(select){
        case 1 :
            cout << "x + y = " << sum(num1, num2) << endl;
            break;
        case 2 :
            cout << "x - y = " << substract(num1, num2) << endl;
            break;
        case 3 :
            cout << "x X y = " << multiply(num1, num2) << endl;
            break;
        case 4 :
            cout << "x / y = " << division(num1, num2) << endl;
            break;
        default:
            cout << "Error." << endl;
            break;
    }
}