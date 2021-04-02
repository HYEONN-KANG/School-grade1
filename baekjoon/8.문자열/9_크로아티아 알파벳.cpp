#include <iostream>
#include <string.h>

int main(){
    using namespace std;

    char S[100];
    cin >> S;

    const int len = strlen(S);

    int countC = 0;
    for(int i = 0; i < len; i++){
        if(S[i] == 'c'){
            if(S[i+1] == '=') {
                countC++;
                i++; continue;
            }
            else if(S[i+1] == '-') {
                countC++;
                i++; continue;
            }
        }
        else if(S[i] == 'd'){
            if(S[i+1] == 'z'){
                if(S[i+2] == '='){
                    countC++;
                    i += 2; continue;
                }
            }
            else if(S[i+1] == '-') {
                countC++;
                i++; continue;
            }
        }
        else if(S[i] == 'l'){
            if(S[i+1] == 'j') {
                countC++;
                i++; continue;
            }
        }
        else if(S[i] == 'n'){
            if(S[i+1] == 'j') {
                countC++;
                i++; continue;
            }
        }
        else if(S[i] == 's'){
            if(S[i+1] == '=') {
                countC++;
                i++; continue;
            }
        }
        else if(S[i] == 'z'){
            if(S[i+1] == '=') {
                countC++;
                i++; continue;
            }
        }

        countC++;
    }

    std::cout << countC << endl;
}