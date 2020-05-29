#include <iostream>
using namespace std;

int* getPointer(int* x) {
    return x;
}

int* getPointer(int x) {
    return &x;
}

int main(){
    int x = 10;
    int* xptr = &x;
    int* xptr2 = getPointer(&x);
    cout << "x:" << x << endl;
    cout << "xptr:" << xptr << "\t";
    cout << "*xptr:" << *xptr << endl;
    cout << "xptr2:" << xptr2 << "\t";
    cout << "*xptr2:" << *xptr2 << endl;
    int *xptr3 = getPointer(x);
    cout << "xptr3:" << xptr3 << "\t";
    cout << "*xptr3:" << *xptr3 << endl;
    cout << endl << endl;
}