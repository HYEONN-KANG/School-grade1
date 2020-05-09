#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

int main(){
    srand(time(0));

    char arr1[5] = {0};
    char arr2[5] = {0};

    
    for(int i = 0; i < 5; i++){
        arr1[i] = '0' + rand() % 10; // ASCII 코드에 '0'과 48은 같은 의미.
        arr2[i] = '0' + rand() % 10;
    }

    int compareResult = 0;
    // if compareResult == -1, arr1 < arr2. Else if compareResult == 1, arr1 > arr2
    for(int i = 0; i < 5; i++){
        if(arr1[i] > arr2[i]){
            compareResult = 1;
            break;
        }
        else if(arr1[i] < arr2[i]){
            compareResult = -1;
            break;
        }
    }

    // print the two arrays
    cout << "char1 = ";
    for(int i = 0; i < 5; i++){
        cout << arr1[i];
    }
    cout << ", char2 = ";
    for(int i = 0; i < 5; i++){
        cout << arr2[i];
    }

    if(compareResult == 0){
        cout << ", char1 == char2" << endl;
    }
    else if(compareResult == -1){
        cout << ", char1 < char2" << endl;
    }
    else if(compareResult == 1){
        cout << ", char1 > char2" << endl;
    }

    return 0;
}