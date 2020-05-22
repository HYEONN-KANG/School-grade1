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
        int n = (int)S[i];

        if(n < 97){
            count[n - 65]++;
        }else{
            count[n - 97]++;
        }
    }

    int max = count[0];
    int index = 0;
    int c = 0;
    for(int i = 1; i < 26; i++){
        if(max < count[i]) {
            max = count[i];
            index = i;
        }
    }

    for(int i = 0; i < 26; i++){
        if(i == index) continue;

        else if(max == count[i]){
            c++;
            break;
        }
    }

    if(c != 0){
        cout << "?" << endl;
        return 0;
    }
    else{
        cout << char(index + 65) << endl;
        return 0;
    }
}