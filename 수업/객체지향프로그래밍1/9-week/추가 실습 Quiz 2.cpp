/*
2.Char�迭�� �����ϰ� Ű����� space�� ���� �Էµ� ��(�ߺ��� ����.)�� char �迭�� �Է��ϰ�, char �迭�� ���� sorting ������� �����Ͽ� ����ϼ���.
     char �迭�� �Է��ϼ���: kadswilmbc

     ���� �� char : abcdiklmsw
*/

#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
void bubbleSort(char [], int);

int main(){

    char a[30];
    cout << "char �迭�� �Է��ϼ���: ";
    cin >> a;

    // bubble sorting
    bubbleSort(a, strlen(a));

    return 0;
}

void bubbleSort(char arr[], int len){
    char temp; 
    int exchange = 0;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len - 1; j++){
            if((int)arr[j] > (int)arr[j+1]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            exchange++;
        }
        }

        if(exchange == 0){
            cout << "���� �� char : " << setw(10);
            for(int i = 0; i < len; i++){
                cout << arr[i];
            }cout << endl;

            break;
        }

        exchange = 0;
    }
}