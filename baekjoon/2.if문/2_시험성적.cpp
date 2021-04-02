#include <iostream>

int main(){
    using namespace std;

    int grade;
    cin >> grade;

    if(grade >= 90 && grade <= 100) cout << "A" << endl;
    else if(grade >= 80 && grade <= 89) cout << "B" << endl;
    else if(grade >= 70 && grade <= 79) cout << "C" << endl;
    else if(grade >= 60 && grade <= 69) cout << "D" << endl;
    else cout << "F" << endl;
}