/*
Write a program that print result of Arithmetic progression and GEometric progression
Given initial term, common difference d(or common ratio r), n(the number of terms).
*/

#include <iostream>
using namespace std;

void Arithmetic_progression(int, int, int);
void Geometric_progression(int, int, int);

int main(){
    cout << "Arithmetic(A)�� Geometric(G) �� �ϳ��� �����ϼ���: ";
    char select;
    cin >> select;

    if(select == 'A'){
        cout << "int Ÿ���� a, d, n ���� ���������� �Է��ϼ���: ";
        int a, d, n;
        cin >> a >> d >> n;
        Arithmetic_progression(a, d, n);
    }else if(select == 'G'){
        cout << "int Ÿ���� a1, d, n ���� ���������� �Է��ϼ���: ";
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