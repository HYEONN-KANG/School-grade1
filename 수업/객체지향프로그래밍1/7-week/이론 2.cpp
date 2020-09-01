// Write a swap function that exchanges the values of two variables using reference parameters.
// Parameters are Reference type variable.
#include <iostream>
using namespace std;

void swap(int&);

int main(){
    int value1 = 10;
    int value2 = 20;
    
    cout << "before call swap value1: " << value1 << endl;
    swap(value1);
    cout << "after call swap value1 : " << value1 << endl;

    cout << "before call swap value2: " << value2 << endl;
    swap(value2);
    cout << "after call swap value2 : " << value2 << endl;
}

void swap(int &value){
    value = value * 2;
}