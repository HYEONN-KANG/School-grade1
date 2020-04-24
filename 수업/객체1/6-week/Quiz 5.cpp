#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;

    do{
        cout << num % 10;
        num = num / 10;
    }while(num != 0);

    cout << endl;
    return 0;
}