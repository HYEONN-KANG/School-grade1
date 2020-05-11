#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    // 윗부분 역삼각형 출력
    for(int i = 0; i < 2*N; i+=2){
        for(int k = 0; k < i / 2; k++) cout << " ";
        for(int j = 2*N -1; j > i; j--) cout << "*";
        cout << "\n";
    }
    
    // 아래부분 삼각형 출력
    for(int i = 0; i < N - 1; i++){
        for(int j = N-i-2; j > 0; j--) cout << " ";
        for(int j = 0; j < 3 + 2*i; j++) cout << "*";
        cout << "\n";
    }
}