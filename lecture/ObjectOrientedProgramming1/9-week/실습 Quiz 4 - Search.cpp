/*
Please input one sentence: Today is sunny day, I like sunny day.
In this sentence, there are 2 sunny.

Please input one sentence: sunny sunny sunny day, I like sunny day.
In this sentence, there are 4 sunny.
*/

#include <iostream>
using namespace std;
#include <string.h>

int main(){
    char sentence[100];
    cout << "Please input one sentence: ";
    cin.getline(sentence, 100);

    int len = strlen(sentence);
    int count = 0;
    for(int i = 0; i < len - 5; i++){
        if(sentence[i] == 's'){
            if(sentence[i+1] == 'u'){
                if(sentence[i+2] == 'n'){
                    if(sentence[i+3] == 'n'){
                        if(sentence[i+4] == 'y') count++;
                    }
                }
            }
        }
    }

    cout << "In this sentence, there are " << count << " sunny." << endl;
}