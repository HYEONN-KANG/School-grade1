/*
3.  Char�迭�� �����ϰ� Ű����� space�� ���� �Էµ� ���� char �迭�� �Է��ϰ�, 
    ���� ���� char�� �� ���� ��ġ�� �ű�� a���� char�� �迭�� �ڷ� �����Ͽ� ���ο� �迭 ���� �� ���.

     char �迭�� �Է��ϼ���: kadswilmbc

     ���� ������ char : adswilmbck
*/

#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

int minArray(char [], int);
void replace1(char [], int, int);

int main(){
    char a[30];
    cout << "char �迭�� �Է��ϼ���: ";
    cin >> a;

    // min index ã��
    int where = minArray(a, strlen(a));

    // �����ϱ�
    replace1(a, strlen(a), where);

    // ����ϱ�
    cout << "���� ������ char:" << setw(8);
    for(int i = 0; i < strlen(a); i++){
        cout << a[i];
    }cout << endl;
}

// min index ã��
int minArray(char arr[], int len){
    char min = arr[0];
    int index = 0;

    for(int i = 1; i < len; i++){
        if(arr[i] < min){
            min = arr[i];
            index = i;
        }
    }

    return index;
}

// �����ϱ�
void replace1(char arr[], int len, int whereMin){
    // min ���� �ڿ� �ִ� ���ڵ��� b�� ����
    char b[len-whereMin];
    for(int i = 0; i < len-whereMin; i++){
        b[i] = arr[whereMin + i];
    }

    // min �տ� �ִ� ���� �ڷ� ������
    for(int i = 0; i < whereMin; i++){
        arr[len-whereMin+i] = arr[i];
    }

    // b�� �ִ� ���� ������ ������
    for(int i = 0; i < len-whereMin; i++){
        arr[i] = b[i];
    }
}