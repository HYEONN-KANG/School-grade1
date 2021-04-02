#include <iostream>

int main(){
    using namespace std;

    int num;
    cin >> num;

    for(int i = 1; i <= 9; i++){
        cout << num << " * " << i << " = " << num * i << endl;
    }
}