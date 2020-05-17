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

<h3>3_9 비트 플래그, 비트 마스크 사용법 Bit Flags, Bit masks</h3>

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main(){
    const unsigned char opt0 = 1 << 0; 
    const unsigned char opt1 = 1 << 1; 
    const unsigned char opt2 = 1 << 2; 
    const unsigned char opt3 = 1 << 3; 

    cout << bitset<8>(opt0) << endl;
    cout << bitset<8>(opt1) << endl;
    cout << bitset<8>(opt2) << endl;
    cout << bitset<8>(opt3) << endl;

    unsigned char items_flag = 0;
    cout << "No item " << bitset<8>(items_flag) << endl;

    // item0 on
    items_flag |= opt0;
    cout << "Item0 obtained " << bitset<8>(items_flag) << endl;

    // item3 on
    items_flag |= opt3;
    cout << "Item3 obtained " << bitset<8>(items_flag) << endl;

    // item3 lost
    items_flag &= ~opt3;
    cout << "Item3 lost " << bitset<8>(items_flag) << endl;

    // do you have item1 ?
    if(items_flag & opt1){
        cout << "I have item1" << endl;
    }else{
        cout << "Not have item1" << endl;
    }

    // do you have item0 ?
    if(items_flag & opt0){
        cout << "I have item0" << endl;
    }else{
        cout << "Not have item0" << endl;
    }

    // obtain item 2, 3
    items_flag |= (opt2 | opt3);
    cout << bitset<8>(opt2 | opt3) << endl;
    cout << "Item2, Item3 obtained " << bitset<8>(items_flag) << endl;

    if((items_flag & opt2) && !(items_flag & opt1)){
        items_flag ^= opt2;
        items_flag ^= opt1;
    }

    cout << bitset<8>(items_flag) << endl;

    return 0;
}
```

- bitflag 가 실전에서 사용되는 예제
```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main(){
    const unsigned int red_mask = 0xFF0000;
    const unsigned int green_mask = 0x00FF00;
    const unsigned int blue_mask = 0x0000FF;

    cout << std::bitset<32>(red_mask) << endl;
    cout << std::bitset<32>(green_mask) << endl;
    cout << std::bitset<32>(blue_mask) << endl;

    unsigned int pixel_color = 0xFFD700;

    cout << std::bitset<32>(pixel_color) << endl;

    unsigned char red = (pixel_color & red_mask) >> 16;
    unsigned char green = (pixel_color & green_mask) >> 8;
    unsigned char blue = pixel_color & blue_mask;

    cout << "red " << bitset<8>(red) << " " << int(red) << endl; 
    cout << "green " << bitset<8>(green) << " " << int(green) << endl; 
    cout << "blue " << bitset<8>(blue) << " " << int(blue) << endl; 

    return 0;
}
```

- 연습문제 풀어보기
1. 다음의 경우에 대해 플래그를 바꿔보세요.
- 기사를 봤을 때
- 기사의 좋아요를 클릭했을 때
- 기사의 좋아요를 다시 클릭했을 때
- 본 기사만 삭제할 때

```cpp
#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

int main(){
    unsigned char option_viewed = 0x01;
    unsigned char option_liked = 0x04;
    unsigned char option_deleted = 0x80;

    cout << bitset<8>(option_viewed) << endl;
    cout << bitset<8>(option_liked) << endl;
    cout << bitset<8>(option_deleted) << endl;

    unsigned char my_article_flags = 0;
    cout << "기존 플래그:" << setw(4) << bitset<8>(my_article_flags) << endl;

    // 기사를 봤을 때
    my_article_flags |= option_viewed;
    cout << "기사를 봤을 때:" << setw(4) << bitset<8>(my_article_flags) << endl;    

    // 기사의 좋아요를 클릭했을 때
    my_article_flags |= option_liked;
    cout << "기사의 좋아요를 클릭했을 때:" << setw(4) << bitset<8>(my_article_flags) << endl;

    // 기사의 좋아요를 다시 클릭했을 때
    my_article_flags &= ~option_liked;
    cout << "기사의 좋아요를 다시 클릭했을 때:" << setw(4) << bitset<8>(my_article_flags) << endl;

    // 본 기사만 삭제할 때
    my_article_flags &= option_deleted;
    cout << "본 기사만 삭제할 때:" << setw(4) << bitset<8>(my_article_flags) << endl;

    return 0;
}
```
2. 아래 두 줄이 왜 동일하게 작동하는지 설명해보세요.

```cpp
myflags &= ~(option4 | option5);
myflags &= ~option4 & ~option5;
```

이유 : 드모르간의 법칙?이랑 비슷한 원리라고 생각한다.
간단하게 예를 들어 option4 == 0001이고 option5 == 0110이라고 가정하면 첫 줄에서 ()안에 option4 | option5 는 0111이 되고 이 값에 ~를 붙였으므로 우변의 값은 1000이 된다. 두번째 줄에서 ~option4는 1110, ~option5는 1001이고 이 두값을 & 했으므로 우변의 값은 1000이 된다. 따라서 두 식 모두 동일하게 작동하는 것이다.