#include <iostream>

using std::cout;
using std::endl;

#include <cstring>

int main(){
    char sentence[] = "This is a sentence with 7 tokens";
    char *tokenPtr;

    cout << "The string to be tokenized is:\n" << sentence
         << "\n\nThe tokens are:\n\n";
    
    tokenPtr = strtok(sentence, " ");
    char *array[10];
    int i = 0;
    
    while(tokenPtr[i] != NULL){
        cout << tokenPtr << "\n";
        array[i] = tokenPtr;
        tokenPtr = strtok(NULL, " ");
        i++;
    }
    int j = 0;
    while(i--){
        cout << array[j] << "  ";
        j++;
    }
    cout << "\nAfter strtok, sentence = " << sentence << endl;

    return 0;
}