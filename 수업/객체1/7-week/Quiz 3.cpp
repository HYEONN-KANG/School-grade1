/*
��ǻ�Ϳ� ���������� ������ �ϴ� ���α׷��� �ۼ�.
��ǻ�ʹ� ���Ƿ� ������������ ����(rand �Լ� ���)
EOF�� �Է� ���������� ������ ��� ����.
�������� ��ü ���� Ƚ��, user�� �¸� Ƚ���� �����.
*/

#include <iostream>
#include <ctime>
using namespace std;

void bobo(int, int&);

int main(){
    cout << "���������� ������ �����Ͻðڽ��ϱ�? �غ������ Enter�� �����ּ���!" << endl;
    getchar();
    system("cls");

    int count = 0;
    int win_count = 0;
    while(!cin.eof()){
        int choose;
        cout << "����-1, ����-2, ��-3 : ";
        cin >> choose;

        if (choose <1 || choose>3) {
            cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
            return 0;
        }
        bobo(choose, win_count);
        count++;
    }
    cout << "�� ���� Ƚ�� : " << count << " user�� �̱� Ƚ�� : " << win_count << endl;
}

void bobo(int choose, int &win_count){
    srand(time(0));
    int com = rand() % 3 + 1;
    switch(com){
        case 1: // ����
            if(choose == 1) cout << "�����ϴ�." << endl;
            else if(choose == 2){
                cout << "�̰���ϴ�." << endl;
                win_count++;
                }
            else cout << "�����ϴ�." << endl;
            break;
        case 2: // ����
            if(choose == 1) cout << "�����ϴ�." << endl;
            else if(choose == 2){
                cout << "�����ϴ�." << endl;
                }
            else {
                cout << "�̰���ϴ�." << endl;
                win_count++;
            }
            break;
        case 3: // ��
            if(choose == 1) {
                cout << "�̰���ϴ�." << endl;
                win_count++;
            }
            else if(choose == 2){
                cout << "�����ϴ�." << endl;
                }
            else cout << "�����ϴ�." << endl;
            break;
    }
}