#include <iostream>
#include "MY_CONSTANTS.h"
#define PRICE_PER_ITEM 30 // macro. not good at cpp.
using namespace std;

void printNumber(const int my_number){
    cout << my_number << endl;
}

int main(){
    printNumber(123);

    const double gravity {9.8}; // can't change variable

    constexpr int my_const(123);

    int number;
    cin >> number;
    constexpr int spaceial_number(number); // error! must use constant

    int price = number * PRICE_PER_ITEM;
    
    double radius;
    cin >> radius;
    
    double circumference = 2.0 * radius * constants::pi;

    return 0;
}