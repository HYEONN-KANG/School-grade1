#include <iostream>

int main(){
    using namespace std;

    int count;
    cin >> count;

    for(int i = 0; i < count; i++){
        int A, B;
        cin >> A >> B;
        cout << A + B << endl;
    }
}