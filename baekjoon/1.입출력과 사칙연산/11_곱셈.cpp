#include <iostream>

int main(){
    using namespace std;

    int A, B;
    cin >> A >> B;

    int b = B;

    cout << A * (B % 10) << endl;
    B /= 10;
    cout << (A * (B % 10)) << endl;
    B /= 10;
    cout << (A * B) << endl;
    cout << A * b << endl;
}