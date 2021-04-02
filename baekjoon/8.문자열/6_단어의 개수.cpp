#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char S[1000001];
    cin.getline(S, 1000001);

    int count = 0;
    for(int i = 1; i < strlen(S) - 1; i++){
        // space
        if(static_cast<int>(S[i]) == 32){
            count++;
        }
    }

    if(strlen(S) == 1){
        if(S[0] == ' '){
            cout << 0 << endl;
            return 0;
        }
    }

    cout << count + 1 << endl;

    return 0;
}