// Make function which can calculate Rectangle, triangle, circle area.

#include <iostream>
using namespace std;

int area(int, int);
float area(int);
float area(float, float);

int main(){
    int shape;
    cout << "please select shapce 1-rectangle, 2-circle, 3-triangle : ";
    cin >> shape;

    switch(shape){
        case 1:
            cout << "You are Select rectangle, please input two integer for length and height : ";
            int num1, num2;
            cin >> num1 >> num2;
            cout << "the area is : " << area(num1, num2) << endl;
            break;
        case 2:
            cout << "You are Select circle, please input one input integer number for radius : ";
            int r;
            cin >> r;
            cout << "the area is : " << area(r) << endl;
            break;
        case 3:
            cout << "You are Select triangle, please input two float number for endge and height : ";
            float number1, number2;
            cin >> num1 >> num2;
            cout << "the area is : " << area(num1, num2) << endl;
            break;
        default:
            cout << "Your input number is incorect try again...";
            break;
    }
}

int area(int num1, int num2){
    return num1 * num2;
}
float area(int number){
    return 3.14 * number * number;
}
float area(float num1, float num2){
    return (1/2) * num1 * num2;
}