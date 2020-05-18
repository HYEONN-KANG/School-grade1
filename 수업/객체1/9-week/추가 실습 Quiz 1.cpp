/*
1.키보드 입력으로 sssaaaaddccekkkkk; 가 입력되었을 때
    새로운 배열을 생성하여 중복을 제외한 char를 저장하고 출력.

    Char배열 값을 입력하세요: sssaaaaddccekkkkk

    중복 제거 후 char : sadcek
*/

#include <iostream>
using namespace std;

#include <string.h>

int main(){
    cout << "Char배열 값을 입력하세요: ";
    char a[30];
    cin >> a;

    // 중복 제거
    int c = 0, i = 0;
    char b[strlen(a)];
    do
    {
        while(a[i] == a[i+1]){
            c++;
            i++;
        }
        b[i-c] = a[i];

        i++;
    } while (i < strlen(a));
    

    cout << "중복 제거 후 char : " << b << endl;
}