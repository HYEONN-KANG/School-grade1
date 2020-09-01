// Write a program to print star of given row and symbol using function
#include <iostream>

using namespace std;

void printStar(int, char); // declare function printStar

int main(){
    int row;
    char sym;
    cout << "Input row : ";
    cin >> row;
    cout << "Input sym : ";
    cin >> sym;

    printStar(row, sym);
}

void printStar(int roww, char symbol){
    for (int i = 0; i < roww; i++){
        for (int j = 0; j <=i; j++){
            cout << symbol;
        }cout << endl;
    }
}