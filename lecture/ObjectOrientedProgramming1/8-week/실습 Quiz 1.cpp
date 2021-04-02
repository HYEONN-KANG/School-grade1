#include <iostream>
using namespace std;
#include <string.h>

int main(){
    char arr1[] = "1234";
    char arr2[] = "5678";
    
    char result[10];

    for(int i = 0; i < 8; i++){
        if(i < 4){
            result[i] = arr1[i];
        }
        else{
            result[i] = arr2[i - 4];
        }
    }

    for(int i = 0; i < 10; i++){
        cout << result[i];
    }
    cout << endl;
}