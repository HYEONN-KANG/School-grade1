/*
Write a program that print result of Arithmetic progression and GEometric progression
Given initial term, common difference d(or common ratio r), n(the number of terms).
*/

#include <iostream>
using namespace std;

void Arithmetic_progression(int, int, int);
void Geometric_progression(int, int, int);

int main(){
    cout << "Arithmetic(A)과 Geometric(G) 중 하나를 선택하세요: ";
    char select;
    cin >> select;

    if(select == 'A'){
        cout << "int 타입의 a, d, n 값을 순차적으로 입력하세요: ";
        int a, d, n;
        cin >> a >> d >> n;
        Arithmetic_progression(a, d, n);
    }else if(select == 'G'){
        cout << "int 타입의 a1, d, n 값을 순차적으로 입력하세요: ";
        int a1, d, n;
        cin >> a1 >> d >> n;
        Geometric_progression(a1, d, n);
    }
}

void Arithmetic_progression(int a, int d, int n){
    for(int i = 1; i <= n + 1; i++){
        if(i == n + 1) {
            cout << a + (i - 1)*d << endl;
            break;
        }
        cout << a + (i - 1)*d << ", ";
    }
}

#include <cmath>

void Geometric_progression(int a1, int d, int n){
    for(int i = 1; i <= n + 1; i++){
        if(i == n + 1){
            cout << a1 * pow(d, i-1) << endl;
            break;
        }
        cout << a1 * pow(d, i-1) << ", ";
    }
}