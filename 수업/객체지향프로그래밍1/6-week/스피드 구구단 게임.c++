#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void gugudan();

int main(){
    cout << "[���ǵ� ������ ����]" << endl << endl
        << "����� ������ �Ƿ��� �׽�Ʈ �ϼ���." << endl
        << "10�� �׽�Ʈ �ϰڽ��ϴ�." << endl
        << "�غ�Ǹ� ���͸� ��������." << endl;
    getchar();
    system("cls");

    gugudan(); // ������ ���� �Լ�
}

void gugudan(){
    time_t start, end;
    double usedTime;
    
    start = time(NULL); // ���� ��ŸƮ �ð� ����
    srand(start);
    
    int score = 0;
    int correct = 1;

    // ���� 10�� �������� ����
    for(int i = 1; i <= 10; i++){
        int num1 = (rand() % 10) + 1;
        int num2 = (rand() % 10) + 1;
        int output;

        cout << "���� " << i << ":" << setw(2)
        << num1 << "*" << num2 << " = " ;
        cin >> output;
        if(output != num1*num2){
            cout << "Ʋ�Ƚ��ϴ�." << endl;
            correct = 0;
        }
        score++;
    }
    end = time(NULL);   // ���� ���� �ð� ����
    usedTime = static_cast<double>(end - start);    // ���� �̿� �ð� ����

    if(correct == 1){
        cout << "������ " << score << " ���� �̿� �ð��� " << usedTime << "��" << endl;
    }else{
        cout << "������ 0" << " ���� �̿� �ð��� " << usedTime << "��" << endl;
    }
    
}
