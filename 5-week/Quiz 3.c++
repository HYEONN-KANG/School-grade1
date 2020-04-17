//calculator program. Using switch-case statement

#include <iostream>
#include <cmath>

using namespace std;

void calculator(float, float, int);

int main(){
    float x, y;
    cout << "Input 2 floats : ";
    cin >> x >> y;
    
    int Choose;
    cout << "Select" << endl
        << "sum - 1, "
        << "subtract - 2, "
        << "multiply - 3, "
        << "division - 4 :";
    cin >> Choose;

    calculator(x, y, Choose);
}

void calculator(float num1, float num2, int select){
    switch(select){
        case 1 :
            cout << "x + y = " << num1 + num2 << endl;
            break;
        case 2 :
            cout << "x - y = " << num1 - num2 << endl;
            break;
        case 3 :
            cout << "x X y = " << num1 * num2 << endl;
            break;
        case 4 :
            cout << "x / y = " << num1 / num2 << endl;
            break;
        default:
            cout << "Error." << endl;
            break;
    }
}