/*
Randomly generate an integer array, whose length is 10, the values in the array is [0, 5). 
Remove the duplicates in-place such that each element appear only once and return the new length.
In-place, means do not allocate extra space for another array, you must do this by modifying the input array.
Print all remained elements .
For example
generate array [10] =  [0,2,1, 0, 1,2,0, 2, 0,4]
The remained elements are [0, 2, 1, 4]
*/
#include <iostream>
#include <ctime>

void modifyArray(int [], int);

int main(){
    using namespace std;

    srand(time(0));

    int array[10];
    for(int i = 0; i < 10; i++){
        array[i] = rand() % 5;
    }

    cout << "generate array [10] = [" ;
    for(int i = 0; i < 10; i++){
        if(i == 9){
            cout << array[i] << "]" << endl;
            break;
        }
        cout << array[i] << ", ";
    }

    modifyArray(array, 10);

    cout << "generate array [10] = [" ;
    for(int i = 0; array[i] != -1; i++){
        if(array[i+1] == -1){
            cout << array[i] << "]" << endl;
            break;
        }
        cout << array[i] << ", ";
    }
}

void modifyArray(int array[], int sizeofArray){
    int temp;
    for(int i = 0; i < sizeofArray; i++){
        temp = array[i];
        for(int j = i+1; j < sizeofArray; j++){
            if(array[j] == temp){
                array[j] = -1;
            }
        }
    }

    for(int i = 0; i < sizeofArray; i++){
        if(array[i] == -1){
            temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
        }
    }
}
