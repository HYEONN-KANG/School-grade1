<h3>3_1 ������ �켱 ������ ���չ�Ģ</h3>

![image](https://user-images.githubusercontent.com/62539341/81494901-428f2700-92e7-11ea-95ac-21c09a13c76f.png)
https://en.cppreference.com/w/cpp/language/operator_precedence �� �����ϱ�

```cpp
#include <cmath> // ���� ���� �Լ����� �ִ� ���̺귯��

int main(){
    int x = std::pow(2,3);  // x = 2^3.
    std::cout << x << std::endl; // output 8

    return 0;
}
```
cmath �ȿ� pow �Լ��� �ִ�. pow�� ���� �Լ�.

<h3>3_2 ��� ������ arithmetic operator</h3>

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

<h3>3_3 ���� ������ increment/decrement operator</h3>

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

<h3>3_4  sizeof, ��ǥ ������ comma operator, ���� ������ conditional operator</h3>

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
<h3>3_5 ���� ������ relational operators</h3>

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

<h3>3_6 �� ������ logical operators</h3>

```cpp
int main(){
    using namespace std;

    int v = 1;

    if(v == 0 || v == 1)
        cout << "v is 0 or 1" << endl;

    // short circuit evaluation
    int x = 2;
    int y = 2;

    if(x == 1 && y++ = 2){  // x = 1 �� �ƴϹǷ� �������� ����� ���� X.
        // do something
    }
    
    cout << y << endl;  // output 2
    
    return 0;
}
```
<h3>3_7 ������ binary numbers</h3>
decimal number : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 ...<br>
binary number  : 0 1 10 11 100 101 110 111 1000 1001 1010 ...

decimal number : 337 = 10^2 * 3 + 10^1 * 3 + 10^0 * 7<br>
binary number  : 10 = 2^1 * 1 + 2^0 * 0 = 2(decimal)<br>

<b>0101 1110</b><br>
2^7*0 + 2^6*1 + 2^5*0 + 2^4*1 + 2^3*1 + 2^2*1 + 2^1*1 + 2^0*0<br>
= 64 + 16 + 8 + 4 + 2<br>
= 94

<b>1001 1110</b><br>
���� ù��° ���� 1�̹Ƿ� ����. ������ ���ϸ� 0110 0001. ���⿡ 1�� ���ϸ� 0110 0010 -> 98 -> (-98)

<b>unsigned ���? </b><br>
1001 1110 -> 128 + 16 + 8 + 4 + 2

<h3>3_8 ��Ʈ���� ������ bitwise operators ��ǻ�� �۵�����</h3>

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

    // !�� logical not. bitwise not�� ~
    cout << std::bitset<8>(~a) << " " << (~a) << endl;  // output 11111101 4294967293

    // binary�� �տ� 0b�� ���δ�.
    unsigned int x = 0b1100;
    unsigned int y = 0b0110;

    cout << x << " " << y << endl;  // 12 6

    cout << std::bitset<4>(x & y) << endl;  // bitwise AND �Ѵ� 1�̸� 1
    cout << std::bitset<4>(x | y) << endl;  // bitwise OR  �� �� �ϳ��� 1�̸� 1
    cout << std::bitset<4>(x ^ y) << endl;  // bitwise XOR �� �� �ϳ�'��' 1�̸� 1

    x &= y; // �̷��� �ٿ� ����� �� �ִ�.
    
    return 0;
}
```

<h3>3_9 ��Ʈ �÷���, ��Ʈ ����ũ ���� Bit Flags, Bit masks</h3>

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

- bitflag �� �������� ���Ǵ� ����
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

- �������� Ǯ���
1. ������ ��쿡 ���� �÷��׸� �ٲ㺸����.
- ��縦 ���� ��
- ����� ���ƿ並 Ŭ������ ��
- ����� ���ƿ並 �ٽ� Ŭ������ ��
- �� ��縸 ������ ��

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
    cout << "���� �÷���:" << setw(4) << bitset<8>(my_article_flags) << endl;

    // ��縦 ���� ��
    my_article_flags |= option_viewed;
    cout << "��縦 ���� ��:" << setw(4) << bitset<8>(my_article_flags) << endl;    

    // ����� ���ƿ並 Ŭ������ ��
    my_article_flags |= option_liked;
    cout << "����� ���ƿ並 Ŭ������ ��:" << setw(4) << bitset<8>(my_article_flags) << endl;

    // ����� ���ƿ並 �ٽ� Ŭ������ ��
    my_article_flags &= ~option_liked;
    cout << "����� ���ƿ並 �ٽ� Ŭ������ ��:" << setw(4) << bitset<8>(my_article_flags) << endl;

    // �� ��縸 ������ ��
    my_article_flags &= option_deleted;
    cout << "�� ��縸 ������ ��:" << setw(4) << bitset<8>(my_article_flags) << endl;

    return 0;
}
```
2. �Ʒ� �� ���� �� �����ϰ� �۵��ϴ��� �����غ�����.

```cpp
myflags &= ~(option4 | option5);
myflags &= ~option4 & ~option5;
```

���� : ��𸣰��� ��Ģ?�̶� ����� ������� �����Ѵ�.
�����ϰ� ���� ��� option4 == 0001�̰� option5 == 0110�̶�� �����ϸ� ù �ٿ��� ()�ȿ� option4 | option5 �� 0111�� �ǰ� �� ���� ~�� �ٿ����Ƿ� �캯�� ���� 1000�� �ȴ�. �ι�° �ٿ��� ~option4�� 1110, ~option5�� 1001�̰� �� �ΰ��� & �����Ƿ� �캯�� ���� 1000�� �ȴ�. ���� �� �� ��� �����ϰ� �۵��ϴ� ���̴�.