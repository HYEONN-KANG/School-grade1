/*
Write a program that swaps 3 elements using pointer.
var1->var2 , var2->var3, var3->var1
Use pointers to function parameters.
prototype : void swap3elem(int*, int*, int*)
*/
#include <iostream>
using namespace std;

void swap3elem(int *, int *, int *);

int main(){
    int var1 = 10, var2 = 20, var3 = 30;
    cout << "before swap: " << endl <<
            "var1 : " << var1 <<
            " var2 : " << var2 <<
            " var3 : " << var3 << endl;

    swap3elem(&var1, &var2, &var3);

    cout << "after swap: " << endl <<
            "var1 : " << var1 <<
            " var2 : " << var2 <<
            " var3 : " << var3 << endl;
}

void swap3elem(int *var1, int *var2, int *var3){
    int temp;
    temp = *var3;
    *var3 = *var2;
    *var2 = *var1;
    *var1 = temp;
}