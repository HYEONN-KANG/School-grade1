// 아직 못품
#include <iostream>
#include <string.h>

int main(){
    using namespace std;

    char S[1000000];
    cin >> S;

    int len = strlen(S);
    int count[26] = {0};
    for(int i = 0; i < len; i++){
        switch((int)S[i]){
            case 65: case 97:
                count[0]++;
                break;
        }
    }
}