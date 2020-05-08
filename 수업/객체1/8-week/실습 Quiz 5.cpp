#include <iostream>
#include <algorithm>
using namespace std;
#include <ctime>


int main(){
    int char1[10] = {5, 10, 36, 42, 49 ,53, 62, 71, 78, 82};

    sort(char1, char1 + 10);
    cout <<"char1 is ";
    
    for(int i = 0; i < 10; i++){
        cout << char1[i] << " ";
    }cout << endl;

    srand(time(0));
    int num = rand() % 101;
    cout << "rand number is : " << num << endl;
    
    sort(char1, char1 + 11);
    cout << "new char is ";
}