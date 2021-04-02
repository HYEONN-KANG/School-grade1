#include <iostream>

int main(){
    using namespace std;

    int N, sum = 0, result = -1;
    cin >> N;

    int n = N;
    int count = 0;
    while(n != result){
        sum = N / 10 + N % 10;
        result = (N % 10) * 10 + sum % 10;
        N = result;
        count++;
    }

    cout << count << endl;
}