#include <iostream>

int main(){
    using namespace std;

    // �׽�Ʈ ���� N �Է¹ޱ�
    int N;
    cin >> N;

    char ox[80];
    for(int i = 0; i < N; i++){
        cin >> ox;

        // ���� �հ� ����ϱ�
        int sum = 0;
        int count = 0;
        for(int i = 0; ox[i] != '\0'; i++){
            if(ox[i] == 'O'){
                count++;
                sum += count;
            }
            else{
                count = 0;
            }
        }

        cout << sum << endl;
    }
}