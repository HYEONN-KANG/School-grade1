#include <iostream>
using namespace std;

int changeG(int grade){
    if(grade < 40) grade = 40;
    return grade;
}

int main(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    a = changeG(a);
    b = changeG(b);
    c = changeG(c);
    d = changeG(d);
    e = changeG(e);

    int average = 0;
    average = (a + b + c + d + e) / 5;
    cout << average << endl;
}