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


    cout << "arr1 = " << arr1 << ", arr2 = " << arr2 << " �̸�" << endl;
    
    int a = strcmp(arr1, arr2);

    if(a < 0){
        cout << "arr1�� arr2���� Ů�ϴ�." << endl;
    }else if(a == 0){
        cout << "arr1�� arr2�� �����ϴ�." << endl;
    }else{
        cout << "arr2�� arr1���� Ů�ϴ�." << endl;
    }
}