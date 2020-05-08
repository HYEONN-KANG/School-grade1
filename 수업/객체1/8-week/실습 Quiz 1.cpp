#include <iostream>
using namespace std;
#include <string.h>

int main(){
    char arr1[] = "1234";
    char arr2[] = "5678";
    
    char copyarr[10];
    strcpy(copyarr, arr1);
    strcat(copyarr, arr2);

    cout << "arr1 = " << arr1 << ", arr2 = " << arr2 << endl;
    cout << "arr1 + arr2 = " << copyarr << endl;
}