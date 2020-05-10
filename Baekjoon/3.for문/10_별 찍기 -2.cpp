#include <iostream>

int main(){
    using namespace std;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int k = N-1; k > i; k--){
            cout << " ";
        }
        for(int j = 0; j <= i; j++){
            cout << "*";
        }
        cout << "\n";
    }
}