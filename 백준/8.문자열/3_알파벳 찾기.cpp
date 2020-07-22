#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char S[100];
    cin >> S;

    int location[26];
    for(int i = 0; i < 26; i++){
        location[i] = -1;
    }

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < strlen(S); j++){
            if((int)S[j] == i + 97){
                location[i] = j;
                break;
            }
        }
    }

    for(int i = 0; i < 26; i++){
        cout << location[i] << " ";
    }
} 