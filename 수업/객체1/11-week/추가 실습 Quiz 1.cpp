/*
1. size�� 10�� ����Ʈ �迭�� �����ϰ�, 
������ 5�� �迭�� ����Ʈ �迭�� ���������� �����ϰ� 
"this is my second test"�� ����� �ǰ� ���α׷� �ۼ�.

char array1[]="this"
char array2[]="is"
char array3[]="my"
char array4[]="second"
char array5[]="test."
*/

#include <iostream>

using namespace std;

void storeArray(char *ptr[], char arr[]){
    for(int i = 0; arr[i] != '\0'; i++){
        ptr[i] = &arr[i];
    }
    for(int i = 0; arr[i] != '\0'; i++){
        cout << *ptr[i];
    }cout << endl;
}

int main(){
    const int size = 10;
    char *ptr_arr[size];

    char array1[]="this";
    char array2[]="is";
    char array3[]="my";
    char array4[]="second";
    char array5[]="test.";

    storeArray(ptr_arr, array1);
    storeArray(ptr_arr, array2);
    storeArray(ptr_arr, array3);
    storeArray(ptr_arr, array4);
    storeArray(ptr_arr, array5);
}