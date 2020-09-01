/*
자리수(length)가 10인 수를[char 배열을 사용] 랜덤으로 생성하고, 해당 수를 거꾸로 출력(또는 변환 후 출력)할 수 있는
재귀(recursion) 함수를 작성하여 거꾸로 된 수를 출력하세요.
미완성
*/
#include <iostream>
#include <ctime>
using std::cout;
using std::endl;

int main(){
    char arr[10];
    srand(time(0));
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 2;
    }

    cout << "랜덤으로 생성한 수는 : ";
    for(int i = 0; i < 10; i++){
        cout << arr[i];
    }
    
    return 0; 
}