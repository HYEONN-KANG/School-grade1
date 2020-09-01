/*
Write a template functino that copies one array to another.
template <typename T1, typename T2>
T func(T1[], T2[], int sizeofarray);
*/

#include <iostream>
#include <iomanip>
using namespace std;

template <typename T1, typename T2>
void copyArray(T1 array[], T2 copyArray[], int sizeofArray){
    for(int i = 0; i < sizeofArray; i++){
        copyArray[i] = array[i];
    }
}

template <typename T>
T printArray(T array[], int sizeofArray){
    for(int i = 0; i < sizeofArray; i++){
        cout << array[i] << " ";
    }cout << endl;
}

#include <ctime>

int main(){
    // int array
    const int size = 5;
    int a[size] = {1 ,2, 3, 4, 5}, b[size] = {0};

    cout << "before int array copy" << endl;
    cout << "The array1 is:" << setw(4);
    printArray(a, size);
    cout << "The array2 is:" << setw(4);
    printArray(b, size);

    copyArray(a, b, size);
    cout << "after int array copy" << endl;
    cout << "The array1 is:" << setw(4);
    printArray(a, size);
    cout << "The array2 is:" << setw(4);
    printArray(b, size);
    cout << endl;

    // char array
    char array1[5] = {'a', 'b', 'c', 'd', 'e'}, array2[5];

    cout << "before char array copy" << endl;
    cout << "The array1 is:" << setw(4);
    printArray(array1, 5);
    cout << "The array2 is:" << setw(4);
    printArray(array2, 5);

    copyArray(array1, array2, 5);
    cout << "after char array copy" << endl;
    cout << "The array1 is:" << setw(4);
    printArray(array1, 5);
    cout << "The array2 is:" << setw(4);
    printArray(array2, 5);
    cout << endl;
}