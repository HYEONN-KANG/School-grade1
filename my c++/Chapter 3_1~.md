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
```
<h3>3_7 이진수 binary numbers</h3>
decimal number : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 ...<br>
binary number  : 0 1 10 11 100 101 110 111 1000 1001 1010 ...

decimal number : 337 = 10^2 * 3 + 10^1 * 3 + 10^0 * 7<br>
binary number  : 10 = 2^1 * 1 + 2^0 * 0 = 2(decimal)<br>

<b>0101 1110</b><br>
2^7*0 + 2^6*1 + 2^5*0 + 2^4*1 + 2^3*1 + 2^2*1 + 2^1*1 + 2^0*0<br>
= 64 + 16 + 8 + 4 + 2<br>
= 94

<b>1001 1110</b><br>
가장 첫번째 값이 1이므로 음수. 보수를 취하면 0110 0001. 여기에 1을 더하면 0110 0010 -> 98 -> (-98)

<b>unsigned 라면? </b><br>
1001 1110 -> 128 + 16 + 8 + 4 + 2

<h3>3_8 비트단위 연산자 bitwise operators 컴퓨터 작동원리</h3>

```cpp
#include <iostream>
#include <bitset>

int main(){
    using namespace std;

    unsigned int a = 1;
    
    cout << std::bitset<4>(a) << endl;  // output 0001
    a = 2;
    cout << std::bitset<4>(a) << endl;  // output 0010

    // left shift
    cout << std::bitset<8>(a << 1) << " " << (a << 1) << endl;  // output 00000100 4. 4 = 2 * 2^1
    cout << std::bitset<8>(a << 2) << " " << (a << 2) << endl;  // output 00001000 8. 8 = 2 * 2^2
    cout << std::bitset<8>(a << 3) << " " << (a << 3) << endl;  // output 00010000 16
    
    // right shift
    cout << std::bitset<8>(a >> 1) << " " << (a >> 1) << endl;  
    cout << std::bitset<8>(a >> 2) << " " << (a >> 2) << endl;  
    cout << std::bitset<8>(a >> 3) << " " << (a >> 3) << endl;

    // !는 logical not. bitwise not은 ~
    cout << std::bitset<8>(~a) << " " << (~a) << endl;  // output 11111101 4294967293

    // binary는 앞에 0b를 붙인다.
    unsigned int x = 0b1100;
    unsigned int y = 0b0110;

    cout << x << " " << y << endl;  // 12 6

    cout << std::bitset<4>(x & y) << endl;  // bitwise AND 둘다 1이면 1
    cout << std::bitset<4>(x | y) << endl;  // bitwise OR  둘 중 하나라도 1이면 1
    cout << std::bitset<4>(x ^ y) << endl;  // bitwise XOR 둘 중 하나'만' 1이면 1

    x &= y; // 이렇게 붙여 사용할 수 있다.
    
    return 0;
}
```

<h3>3_9 </h3>