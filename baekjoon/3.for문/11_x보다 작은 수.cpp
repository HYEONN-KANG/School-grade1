#include <iostream>

int main(){
    using namespace std;

    int N, X;
    cin >> N >> X;

    cin.tie(NULL);

    int n, y;
    for(int i = 0; i < N; i++){
        cin >> n;
        if(n < X) cout << n << " ";
    }
}