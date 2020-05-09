#include <iostream>
#include <algorithm>
using namespace std;
#include <ctime>


int main(){
    int arr[10] = {5, 10, 36, 42, 49 ,53, 62, 71, 78, 82};

    int result[11];

    // generate a random element
    srand(time(0));
    int randomness = rand() % 101;

    int index = -1;
    for(int i = 0; i < 10; i++){
        if(randomness <= arr[i]){
            index = i;
            break;
        }
    }
    if(index == -1){
        index = 10;
    }

    for(int i = 0; i < index; i++){
        result[i] = arr[i];
    }
    result[index] = randomness;
    for(int i = index + 1; i < 11; i++){
        result[i] = arr[i - 1];
    }
    
    cout << "char1 is 5, 10, 36, 42, 49, 53, 62, 71, 79, 82" << endl;
    cout << "random num is : " << randomness << endl;
    cout << "new char array is : " << result << endl;
    // ? error... check later.......
}