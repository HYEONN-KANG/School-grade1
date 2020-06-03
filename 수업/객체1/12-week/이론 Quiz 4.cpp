#include <iostream>

using std::cout;
using std::endl;

#include <cstring>

int main(){
    char sentence[] = "This is a sentence with 7 tokens";
    char *tokenPtr[10];

    cout << "The string to be tokenized is:\n" << sentence
         << "\n\nThe tokens are:\n\n";
    
    tokenPtr[0] = strtok(sentence, " ");
    int i = 0;
    
    while(tokenPtr[i] != NULL){
        cout << tokenPtr[i] << "\n";
        i++;
        tokenPtr[i] = strtok(NULL, " ");
    }

    cout << "\nAfter strtok, sentence = " << sentence << endl;

    return 0;
}