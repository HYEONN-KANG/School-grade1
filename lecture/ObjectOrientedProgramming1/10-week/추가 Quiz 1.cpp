/*
Write a program that return the length of given word from user. 
Use char array with size 100 
char array[100];
cin>>array;
DO NOT use strlen() and sizeof()
*/
#include <iostream>

int main(){
    using namespace std;

    char array[100];
    cout << "Input string : ";
    cin >> array;

    int length = 0;
    for(int i = 0; array[i] != '\0'; i++){
        length++;
    }
    cout << "length of string : " << length << endl;
}