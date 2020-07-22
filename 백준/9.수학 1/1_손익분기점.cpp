#include <iostream>

int main(){
    using namespace std;

    long long A, B, C;
    cin >> A >> B >> C;

    if(B >= C){
        cout << -1 << endl;
        return 0;
    }
    cout << A / (C - B) + 1;
    return 0;
}