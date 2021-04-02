#include <iostream>

int main(){
    using namespace std;

    // 테스트 개수 N 입력받기
    int N;
    cin >> N;

    char ox[80];
    for(int i = 0; i < N; i++){
        cin >> ox;

        // 점수 합계 계산하기
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