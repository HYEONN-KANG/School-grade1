/*
1.Ű���� �Է����� sssaaaaddccekkkkk; �� �ԷµǾ��� ��
    ���ο� �迭�� �����Ͽ� �ߺ��� ������ char�� �����ϰ� ���.

    Char�迭 ���� �Է��ϼ���: sssaaaaddccekkkkk

    �ߺ� ���� �� char : sadcek
*/

#include <iostream>
using namespace std;

#include <string.h>

int main(){
    cout << "Char�迭 ���� �Է��ϼ���: ";
    char a[30];
    cin >> a;

    // �ߺ� ����
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
    

    cout << "�ߺ� ���� �� char : " << b << endl;
}