#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;

    char num[100];
    int sum = 0;
    cin >> num;

    for(int i = 0; i < N; i++){
        sum += (int)num[i] - 48;
    }

    cout << sum << endl;
}