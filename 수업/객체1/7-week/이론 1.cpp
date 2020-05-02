#include <iostream>
using namespace std;

void callbyV(int);
void callbyR(int&);

int main(){
    int var = 10;
    cout << "add of local value var: " << &var << endl;
    callbyV(var);
    cout << "add of local value var after callbyV(): " << &var << endl;
    callbyR(var);
    cout << "add of local value var after callbyR(): " << &var << endl;
    return 0;
}

void callbyV(int var){
    cout << "add of var in callbyV(): " << &var << endl;
}

void callbyR(int &var){
    cout << "add of var in callbyR(): " << &var << endl;
}