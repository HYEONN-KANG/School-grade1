// 아직 못품
#include <iostream>
#include <string.h>

int main(){
    using namespace std;

    int N;
    cin >> N;

    char word[100];
    int len, count = 0;
    for(int i = 0; i < N; i++){ // N번 반복
        cin >> word;
        len = strlen(word);

        int x = 1;
        char temp[len] = "0";

        for(int k = 0; k < len; k++){
                if(word[k] != word[k+1]){
                    temp[k] = word[k];
                }
            }
        for(int j = 0; j < len; j++){
            for(int k = 0; k < len; k++){
                if(k < j) continue;

                else if(word[k] == temp[j] && j != k){
                    x = -1;
                }
            }
        }

        if(x == 1) count++;
    }

    cout << count << endl;
}