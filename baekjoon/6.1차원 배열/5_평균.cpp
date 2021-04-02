#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    float grade[1000];
    for(int i = 0; i < N; i++){
        scanf("%f", &grade[i]);
    }

    // 최댓값 구하기
    int M;
    M = grade[0];
    for(int i = 1; i < N; i++){
        if(grade[i] > M) M = grade[i];
    }

    // 점수 조작하기
    float sum = 0;
    for(int i = 0; i < N; i++){
        grade[i] = (static_cast<float>(grade[i]) / M) * 100;
        sum += grade[i];
    }
    
    float average = sum / N;
    printf("%f", average);

    return 0;
}