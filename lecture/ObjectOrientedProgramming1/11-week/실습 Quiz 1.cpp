#include <iostream>
using namespace std;

int main(){
    int ele = 10;
    int *ptr;
    ptr = &ele;
    cout << "ele:" << ele << endl;
    cout << "&ele:" << &ele << endl;
    cout << "ptr:" << ptr << endl;
    cout << "&ptr:" << &ptr << endl;
    cout << "*ptr:" << *ptr << endl;
    cout << endl << endl;
}