/*
a, b, c, d�� �������� 100�� �����Ͽ� ���
a, b, c, d�� ���� Ƚ���� ���
[���� ���� ������ ���ĺ��� : a �Դϴ�]�� ������� ���� ���� ������ ���ĺ��� ���
*/

#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

int main(){
    srand(time(0));
    int count_a = 0, count_b = 0, count_c = 0, count_d = 0; // a = 1, b = 2, c = 3, d = 4

    int num;
    for(int i = 0; i < 100; i++){
        num = rand() % 4 + 1;
        switch(num){
            case 1:
                cout << "a";
                count_a++;
                break;
            case 2:
                cout << "b";
                count_b++;
                break;
            case 3:
                cout << "c";
                count_c++;
                break;
            case 4:
                cout << "d";
                count_d++;
                break;
        } cout << endl;
    }
    cout << "����Ƚ�� : a-" << count_a << " b-" << count_b << " c-" << count_c << " d-" << count_d << endl;
    int a = max(count_a, count_b);
    int b = max(count_c, count_d);
    if(a > b){
        if(a = count_a) cout << "[���� ���� ������ ���ĺ��� : a �Դϴ�]" << endl;
        else cout << "[���� ���� ������ ���ĺ��� : b �Դϴ�]" << endl;
    }
    if(b > a){
        if(b = count_c) cout << "[���� ���� ������ ���ĺ��� : c �Դϴ�]" << endl;
        else cout << "[���� ���� ������ ���ĺ��� : d �Դϴ�]" << endl;
    }
}