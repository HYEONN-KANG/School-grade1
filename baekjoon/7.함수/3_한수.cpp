#include <iostream>

// 한수인지 아닌지 판별하는 함수
int Hansoo(int number){
    int count = 0;

    // 한자리수, 두자리수는 모두 한수이므로 그대로 리턴
    if(number <= 99) return number;

    // 세자리 수
    count = 99; // 두자리수까지의 한수의 개수
    for(int i = 100; i <= number; i++){
        if(i/100 - (i/10)%10 == (i/10)%10 - i%10){
            count++;
        }
    }
    return count;
}

int main(){
    using namespace std;

    int N;
    cin >> N;

    cout << Hansoo(N) << endl;
}