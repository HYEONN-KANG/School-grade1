#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    int R;
    char S[20];

    for(int i = 0; i < T; i++){
        cin >> R;
        cin >> S;

        for(int j = 0; j < strlen(S); j++){
            for(int i = 0; i < R; i++){
                cout << S[j];
            }
        }
        cout << endl;
    }
}