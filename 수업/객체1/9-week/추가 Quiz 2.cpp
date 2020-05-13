// char Ÿ���� array1�� array2�� Ű����� �Է¹ް�, �� ���� array�� �������� �Ǵ��Ͽ� ��� ���.

#include <iostream>
#include <iomanip>

using namespace std;

void originArray(char [], char [], int);
int compareArray(char [], char [], int);

int main(){
    char array1[10];
    char array2[10];

    for(int i = 0; i < 10; i++){
        cin >> array1[i] >> array2[i];
    }

    // array1�� array2 ����ϱ�
    originArray(array1, array2, 10);

    // array1�� array2 ���ϱ�
    int result = compareArray(array1, array2, 10);

    if(result == 1) cout << "array1�� array2�� �����մϴ�." << endl;
    else if(result == -1) cout << "array1�� array2�� �������� �ʽ��ϴ�." << endl;
}

void originArray(char array1[], char array2[], int sizeofArray){
    cout << "Original array1:" << setw(4);
    for(int i = 0; i < sizeofArray; i++){
        cout << array1[i] << " ";
    }cout << endl;

    cout << "Original array2:" << setw(4);
    for(int i = 0; i < sizeofArray; i++){
        cout << array2[i] << " ";
    }cout << endl;
}

int compareArray(char array1[], char array2[], int sizeofArray){
    for(int i = 0; i < sizeofArray; i++){
        // �ϳ��� ���� �ٸ��� -1 ��ȯ
        if(array1[i] != array2[i]) return -1;  
    }
    // ��� ������ 1 ��ȯ
    return 1;
}