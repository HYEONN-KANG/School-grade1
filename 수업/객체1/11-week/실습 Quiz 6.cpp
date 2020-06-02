/*
Write a program that calculates input words statistics.
Keyboard input a sentence.
Print out how many words are inputed, and print the length of each word.
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int wordsize(char *word){
    int size = 0;

    while(word[size] != '\0'){
        size++;
    }
    return size;
}

int main(){
    char word[100];
    int num = 0;
    while(num++ < 20){
        word[num] == '0';
    }
    cout << "Please input one sentence: ";
    cin >> word;
    while(word[0] != '0'){
        cout << word << "\t The size of ";
        cout << wordsize(word) << "\n";
        cin >> word;
    }

    return 0;
}