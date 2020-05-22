#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char array[100];
    cout << "input a word : ";
    cin >> array;

    char new_array[strlen(array)];
    cout << "reversed : ";
    for(int i = 0; i < strlen(array); i++){
        new_array[i] = array[strlen(array) -1 -i];
    }

    for(int i = 0; i < strlen(array); i++){
        cout << new_array[i];
    }cout << endl;
}