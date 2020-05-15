/*
Wirte a program that print all results of repeated permutation when take 3 numbers in array {1, 2, 3, 4, 5}
111, 112, 113, 114, 115, 121, 122, ...
*/

#include <iostream>
using namespace std;

int main(){
    int array[] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                int sum = array[i]*100 + array[j]*10 + array[k]*1;
                cout << sum << " ";
            }
        }
        cout << endl;
    }
}