#include <iostream>

int main(){
    using namespace std;

    char A[3], B[3];
    cin >> A >> B;

    char temp[3];
    // temp�� A�� �Ųٷ� �� ��
    for(int i = 0; i < 3; i++){
        temp[i] = A[2-i];
    }
    // A �Ųٷ� ����
    for(int i = 0; i < 3; i++){
        A[i] = temp[i];
    }

    // temp�� B�� �Ųٷ� �� ��
    for(int i = 0; i < 3; i++){
        temp[i] = B[2-i];
    }
    // B �Ųٷ� ����
    for(int i = 0; i < 3; i++){
        B[i] = temp[i];
    }

    // A�� B ��
    int select;
    for(int i = 0; i < 3; i++){
        // A�� ũ�� select = -1
        if(A[i] > B[i]){
            select = -1;
            break;
        }
        // B�� ũ�� select = 1
        else if(B[i] > A[i]){
            select = 1;
            break;
        }
    }

    if(select == -1){
        for(int i = 0; i < 3; i++){
            cout << A[i];
        }cout << endl;
    }else if(select == 1){
        for(int i = 0; i < 3; i++){
            cout << B[i];
        }cout << endl;
    }
}