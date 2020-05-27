// ppt p22의 결과가 나올 수 있게 코드를 구현
#include <iostream>
using namespace std;

int main(){
    const int arraySize = 4;
    int b[arraySize] = {10, 20, 30, 40};

    cout << "Array b printed with:\n\n";

    cout << "Array subscript notation\n";
    for(int i = 0; i < arraySize; i++){
        cout << "b[" << i << "] = " << b[i] << endl;
    }
    cout << endl;

    cout << "Pointer/offset notation where the pointer is the array name\n";
    for(int i = 0; i < arraySize; i++){
        cout << "*(b + " << i << ") = " << *(b + i) << endl;
    }
    cout << endl;

    int *bPtr[arraySize];
    for(int i = 0; i < arraySize; i++){
        bPtr[i] = &b[i];
    }

    cout << "Pointer subscript notation\n";
    for(int i = 0; i < arraySize; i++){
        cout << "bPtr[" << i << "] = " << *bPtr[i] << endl;
    }
    cout << endl;

    cout << "Pointer/offset notation\n";
    for(int i = 0; i < arraySize; i++){
        cout << "*(bPtr + " << i << ") = " << *(bPtr[0] + i) << endl;
    }
}