#include <iostream>

int main(){
    using namespace std;

    int n;
    cin >> n;

    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
    }

    cout << sum << endl;
}