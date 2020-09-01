#include <iostream>
using namespace std;

bool isPrimeNumber(int n){
    for(int i = 2; i < n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

int prime = 1;
int count = 1;
void getNextPrime(){
    while(isPrimeNumber(++prime) == true) {
        cout << prime << endl;
        count++;
    }
}

int main(){
    while(count <= 10){
        getNextPrime();
    }
    return 0;
}