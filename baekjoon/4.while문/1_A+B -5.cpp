#include <iostream>

int main(){
    using namespace std;

    int A = 1, B = 1;
    cin.tie(0);
    while(A != 0 && B != 0){
        cin >> A >> B;
        if(A != 0 && B != 0) cout << A + B << "\n";
    }
}