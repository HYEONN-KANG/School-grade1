#include <iostream>
using namespace std;

// 셀프 넘버 판별
int selfNum(int n){
    int sum;
    for(int i = 1; i <= n; i++){
        sum = i + (i/1000)%10 + (i/100)%10 + (i/10)%10 + i%10;
        if(n == sum) return -1;
    }
    return 1;
}

int main(){
    int n = 10000;

    for(int i = 1; i <= n; i++){
        int result = selfNum(i);
        if(result == 1) cout << i << endl; 
    }
}