// fail to solve
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
 
#include <cstring>

void modify(char*, char*[], int);

int main() {
    char sentence[50];
    cout << "Please input 5 words: ";
    cin.getline(sentence, 50);
    char* tokenPtr;

    tokenPtr = strtok(sentence, " ");
    char* array[10];
    int i = 0;

    /*
    while (tokenPtr[i] != NULL) {
        cout << tokenPtr << "\n";
        array[i] = tokenPtr;
        tokenPtr = strtok(NULL, " ");
        i++;
    }
    int j = 0;
    while (i--) {
        strcat(tokenPtr, "_test");
        cout << array[j] << "  ";
        j++;
    }
    */
    modify(tokenPtr, array, i);

    return 0;
}

void modify(char* tokenPtr, char* array[], int i) {
    char add[] = "_test";
    while (tokenPtr[i] != NULL) {
        array[i] = tokenPtr;
        tokenPtr = strtok(NULL, " ");
        i++;
    }
    int j = 0;
    while (i--) {
        strcat(tokenPtr, add);
        cout << array[j] << "  ";
        j++;
    }
}