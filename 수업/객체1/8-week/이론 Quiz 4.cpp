/*
�ڸ���(length)�� 10�� ����[char �迭�� ���] �������� �����ϰ�, �ش� ���� �Ųٷ� ���(�Ǵ� ��ȯ �� ���)�� �� �ִ�
���(recursion) �Լ��� �ۼ��Ͽ� �Ųٷ� �� ���� ����ϼ���.
�̿ϼ�
*/
#include <iostream>
#include <ctime>
using std::cout;
using std::endl;

int main(){
    char arr[10];
    srand(time(0));
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 2;
    }

    cout << "�������� ������ ���� : ";
    for(int i = 0; i < 10; i++){
        cout << arr[i];
    }
    
    return 0; 
}