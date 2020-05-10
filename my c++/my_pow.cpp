// pow 함수 구현해보기

#include <iostream>

template <typename T>
T pow(T x, T y){
    T number = 1;

    if(x == 1 || y == 0) return number;
    
    else if(y > 0){
        for(int i = 1; i <= y; i++){
            number *= x;
        }
    }
    return number;
}

int main(){
    using namespace std;

    int a = pow(2, 10);
    cout << "a is : " << a << endl;
}