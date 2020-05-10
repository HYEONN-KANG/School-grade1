<h3>3_1 연산자 우선 순위와 결합법칙</h3>

![image](https://user-images.githubusercontent.com/62539341/81494901-428f2700-92e7-11ea-95ac-21c09a13c76f.png)
https://en.cppreference.com/w/cpp/language/operator_precedence 를 참고하기

```cpp
#include <cmath> // 여러 수학 함수들이 있는 라이브러리

int main(){
    int x = std::pow(2,3);  // x = 2^3.
    std::cout << x << std::endl; // output 8

    return 0;
}
```
cmath 안에 pow 함수가 있다. pow는 제곱 함수.

<h3>3_2 산술 연산자 arithmetic operator</h3>

```cpp
int main(){
    int x = 7;
    int y = 4;

    std::cout << x / y << std::endl;    // output 1
    std::cout << float(x) / y << std::endl; // output 1.75
    std::cout << x / float(y) << std::endl; // output 1.75
    std::cout << float(x) / float(y) < std::endl;   // output 1.75
}
```

<h3>3_3 증감 연산자 increment/decrement operator</h3>

```cpp
int main(){
    using namespace std;

    int x = 5;
    int y = ++x;    // y = 6
    cout << y << endl;  // output 6

    int a = 6, b = 6;
    cout << ++a << " " << --b << endl;  // output 7 5
    cout << a++ << " " << b-- << endl;  // output 7 5
}
```

<h3>3_4  sizeof, 쉼표 연산자 comma operator, 삼항 연산자 conditional operator</h3>

```cpp
int main(){
    // sizeof operator
    float val;
    cout << sizeof(float) << endl;  // 4 (byte)
    cout << sizeof(val)<< endl;  // 4 (byte)

    // comma operator
    int x = 3;
    int y = 10;
    int z =(++x, ++y);

    cout << z << endl;  // output 11

    int a = 1, b = 10;
    int c;
    c = a, b;

    cout << c << endl; // output 1

    // conditional operator
    bool onSale = true;
    
    const int price = (onSale = true) ? 10 : 100;
    
    cout << price << endl;  // output 10

    int num = 5;
    cout << ((x % 2 == 0) ? "even" : "odd")<< endl;
}
```
<h3>3_5 관계 연산자 relational operators</h3>

```cpp
int main(){
    double d1(100 - 99.99); // d1 = 0.001
    double d2(10 - 9,99);   // d2 = 0.001

    if(d1 == d2)
        cout << "equal" << endl;
    else{
        cout << "Not equal" << endl;
        
        if(d1 > d2) cout << "d1 > d2" << endl;
        else        cout << "d1 < d2" << endl;
    }

    // output Not equl, d1 > d2
}
```

```cpp
// floating point numbers

#include <iostream>
#include <iomanip>
#include <limits>

int main(){
    using namespace std;

    float f(123456789.0f)   // 10 significant digits

    cout << std::setprecision(9);
    cout << 1.0 / 3.0 << endl;

    double d(0.1);
    
    cout << d << endl;  // output 0.1
    cout << std::setprecision(17);
    cout << d << endl;  // output 0.1000000~00001
}
```

<h3>3_6 논리 연산자 logical operators</h3>

```cpp
int main(){
    using namespace std;

    int v = 1;

    if(v == 0 || v == 1)
        cout << "v is 0 or 1" << endl;

    // short circuit evaluation
    int x = 2;
    int y = 2;

    if(x == 1 && y++ = 2){  // x = 1 이 아니므로 오른쪽은 계산을 하지 X.
        // do something
    }
    
    cout << y << endl;  // output 2
    
    return 0;
}