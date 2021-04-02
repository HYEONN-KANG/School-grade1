#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "Input decimal number : ";
    cin >> num;

    int binary, sum = 0, i = 1;

    while(num>0)
    {
        binary = num % 2;
        sum += binary * i;
        num = num / 2;
        i *= 10;
    }
    cout << "to binary ... : " << sum << endl;
}