<h3>4_1 지역변수, 범위(Scope), 지속기간(Duration)</h3>

```cpp
#include <iostream>

using namespace std;

int main(){
    int apple = 5;

    cout << apple << endl;  // output 5

    {
        int apple = 1;
        cout << apple << endl;  // output 1
    }

    cout << apple << endl;  // output 5

    return 0;
}
```

```cpp
#include <iostream>
using namespace std;

namespace work1
{
    int a = 1;
    void doSomething(){
        a += 3;
    }
}

namespace work2
{
    int a = 1;
    void doSomething(){
        a += 5;
    }
}

int main(){
    work1::a;
    work1::doSomething();

    work2::a;
    work2::doSomething();

    return 0;
}
```
:: 는 scope resolution operator.

<h3>4_2 전역 변수(Global Variable), 정적 변수(Static Variable), 내부연결(Internal Linkage), 외부연결(External Linkage)</h3>

```cpp
#include <iostream>
using namespace std;

int value = 3;

int main(){
    cout << value << endl;  // output 3

    int value = 1;

    cout << value << endl;  // output 1

    cout << ::value << endl;    // output 3

    return 0;
}
```
지역변수는 전역변수보다 우선순위가 높기 때문에 두번째 cout에서 지역변수 value의 값인 1이 출력된다. 지역변수 value가 선언된 뒤에 전역변수 value를 사용하지 못하는 것은 아니다. operator :: 를 사용하면 위와 같이 전역변수 value를 출력할 수 있다.<br>
전역변수는 external linkage 될 수 있다. (static 전역 변수는 X)

```cpp
#include <iostream>
using namespace std;

void doSomething(){
    static int a = 1;
    ++a;
    cout << a << endl;
}

int main(){
    doSomething();  // output 2
    doSomething();  // output 3
    doSomething();  // output 4
    doSomething();  // output 5

    return 0;
}
```
static은 이미 전에 변수를 선언하여 메모리를 할당했다면 다시 변수를 선언하지 않는다. 따라서 위 코드는 차례대로 2, 3, 4, 5를 출력한다.

- Linkage

```cpp
// test.cpp
#include <iostream>

extern int a = 123;

void doSomething(){
    using namespace std;

    cout << "Hello" << endl;
}
```

```cpp
// main.cpp
#include <iostream>

using namespace std;

// forward declaration
extern void doSomething();  // extern은 생략할 수 O
extern int a;

int main(){
    doSomething();  // output Hello

    cout << a << endl;  // output 123

    return 0;
}
```

이렇게 test.cpp와 main.cpp 두개의 파일을 선언하였다. main.cpp에서 extern void doSomething()은 컴파일러에게 doSomething()의 정의가 어딘가에 있으니 나중에 linking 해 라고 말해주는 것이다.

```h
// My Constants.h
#pragma once

namespace Constants {
    extern const double gravity;
    extern const double pi;
}
```
```cpp
// test.cpp
#include <iostream>
#include "My Constants.h"

extern int a = 123;

void doSomething() {
    using namespace std;

    cout << "Hello" << endl;

    cout << &Constants::pi << endl;
}
```
```cpp
// main.cpp
#include <iostream>
#include "My Constants.h"

using namespace std;

// forward declaration
extern void doSomething();
extern int a;

int main() {
    doSomething();

    cout << a << endl;

    cout << "In main.cpp file " << &Constants::pi << endl;

    return 0;
}
```
```cpp
// My Constants.cpp
namespace Constants
{
    extern const double pi(3.141592);
    extern const double gravity(9.8);
}
```
이렇게 해주면 동일한 메모리에 있는 const 변수 pi와 gravity를 반복적으로 사용하는 것이기 때문에 불필요한 메모리 낭비가 발생하지 않는다.

<h3>4_3 Using문과 모호성</h3>

```cpp
#include <iostream>

namespace a{
    int my_var = 3;
}
namespace b{
    int my_var = 5;
}

int main(){
    using namespace std;

    {
        using namespace a;
        cout << my_var << endl; // output 3
    }

    {
        using namespace b;
        cout << my_var << endl; // output 5
    }

    return 0;
}
```

namespace 는 범위를 작게 하는 것이 좋다! 블록으로 감싸주는 습관 들이기!

<h3>4_4 auto 키워드와 자료형 추론</h3>

```cpp
#include <iostream>

auto add(int x, int y){
    return x + (double)y;
}

int main(){
    using namespace std;

    auto a = 123;
    auto d = 123.0;
    auto c = 1 + 2;
    auto f = 1.2f;
    auto result = add(1, 2);

    return 0;
}
```
auto는 변수를 초기화할 때, 초기화 값을 이용하여 변수의 타입을 자동으로 정해준다. 함수의 반환값도 따라서 auto를 사용할 수 있다. 단, auto는 parameter에는 쓸 수가 없다. (이 경우는 template를 이용하게 된다.)

```cpp
auto add(int x, int y) -> int;
auto add(int x, int y) -> double;
```
이런식으로도 사용 가능하다.

<h3>4_5 형변환 Type conversion</h3>

```cpp
#include <iostream>
#include <typeinfo>

int main(){
    using namespace std;

    int a = 123;
    cout << typeid(a).name() << endl;   // output int
    cout << typeid(4.0).name() << endl; // output double
}
```
typeid를 사용하여 변수나 리터럴의 데이터 타입을 알 수 있다.

```cpp
#include <iostream>
#include <typeinfo>
#include <iomanip>

int main(){
    using namespace std;

    // numeric conversion
    double d = 0.123456789;
    float f = d;

    cout << std::setprecision(12) << d << endl; // output 0.123456789
    cout << std::setprecision(12) << f << endl; // output 0.123456791043

    return 0;
}
```
이렇게 큰 데이터 타입을 작은 데이터 타입에 넣으려 하면 의도치 않은 데이터 손실이나 오류가 발생할 수 있어 주의해야 한다.

```cpp
#include <iostream>
#include <iomanip>

int main(){
    using namespace std;

    // numeric conversion
    cout << 5u - 10u;    // output 4294967291

    // 우선순위
    // int, unsigned int, long, unsigned long,
    // long long, unsigned long long, float, double,
    // long double

    int i = static_cast<int>(4.0);

    return 0;
}
```

<h3>4_6 문자열 std string 소개</h3>
