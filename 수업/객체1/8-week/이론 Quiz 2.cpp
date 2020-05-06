/*
ppt 17~18page �����ڵ带 �����Ͽ� size�� 100�� �迭�� �����ϰ� �迭�� value�� 5~15������ ���� �������� �����Ͽ� ���� �ο��ϰ�, 
19�������� ����� ���¿� �����ϰ� 5~15������ ���� ���� Ƚ���� ����ϰ�, 
�������� "���� ���� ������ ���� 5�̰�, ���� Ƚ���� 20�Դϴ�" ó�� ���� ���� ������ ���� ���� Ƚ���� ���
*/
#include <iostream>
#include <ctime>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

int main(){
    int arr[100];

    srand(time(0));
    int i = 0;
    while(i < 100){
        arr[i] = rand() % 11 + 5;
        i++;
    }

    int frequency[11+5] = {0};
    for(int answer = 0; answer < 100; answer++){
        ++frequency[arr[answer]];
    }

    cout << "Rating" << setw(17) << "Frequency" << endl;
    for(int rating = 5; rating < 16; rating++){
        cout << setw(6) << rating << setw(17) << frequency[rating] << endl;
    }
    
    int max = frequency[5];
    int num = 5;
    for(int i = 5; i < 16; i++){
        if(frequency[i] > max){
            max = frequency[i];
            num = i;
        }
    }

    cout << "���� ���� ������ ���� " << num << " �̰�, ���� Ƚ���� " << max << " �Դϴ�. " << endl;
    
    return 0;
}