#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

int main(){
    srand(time(0));

    char arr1[5] = {0};
    char arr2[5] = {0};

    
    for(int i = 0; i < 5; i++){
        arr1[i] = rand() % 10;
        arr2[i] = rand() % 10;
    }


    cout << "arr1 = " << arr1 << ", arr2 = " << arr2 << " 이며" << endl;
    
    int a = strcmp(arr1, arr2);

    if(a < 0){
        cout << "arr1은 arr2보다 큽니다." << endl;
    }else if(a == 0){
        cout << "arr1은 arr2와 같습니다." << endl;
    }else{
        cout << "arr2은 arr1보다 큽니다." << endl;
    }
}