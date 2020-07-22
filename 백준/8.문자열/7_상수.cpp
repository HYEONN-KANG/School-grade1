#include <iostream>

int main(){
    using namespace std;

    char A[3], B[3];
    cin >> A >> B;

    char temp[3];
    // temp는 A를 거꾸로 한 것
    for(int i = 0; i < 3; i++){
        temp[i] = A[2-i];
    }
    // A 거꾸로 저장
    for(int i = 0; i < 3; i++){
        A[i] = temp[i];
    }

    // temp는 B를 거꾸로 한 것
    for(int i = 0; i < 3; i++){
        temp[i] = B[2-i];
    }
    // B 거꾸로 저장
    for(int i = 0; i < 3; i++){
        B[i] = temp[i];
    }

    // A와 B 비교
    int select;
    for(int i = 0; i < 3; i++){
        // A가 크면 select = -1
        if(A[i] > B[i]){
            select = -1;
            break;
        }
        // B가 크면 select = 1
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