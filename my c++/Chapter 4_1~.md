<h3>4_1 ��������, ����(Scope), ���ӱⰣ(Duration)</h3>

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
:: �� scope resolution operator.

<h3>4_2 ���� ����(Global Variable), ���� ����(Static Variable), ���ο���(Internal Linkage), �ܺο���(External Linkage)</h3>

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
���������� ������������ �켱������ ���� ������ �ι�° cout���� �������� value�� ���� 1�� ��µȴ�. �������� value�� ����� �ڿ� �������� value�� ������� ���ϴ� ���� �ƴϴ�. operator :: �� ����ϸ� ���� ���� �������� value�� ����� �� �ִ�.<br>
���������� external linkage �� �� �ִ�. (static ���� ������ X)

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
static�� �̹� ���� ������ �����Ͽ� �޸𸮸� �Ҵ��ߴٸ� �ٽ� ������ �������� �ʴ´�. ���� �� �ڵ�� ���ʴ�� 2, 3, 4, 5�� ����Ѵ�.

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
extern void doSomething();  // extern�� ������ �� O
extern int a;

int main(){
    doSomething();  // output Hello

    cout << a << endl;  // output 123

    return 0;
}
```

�̷��� test.cpp�� main.cpp �ΰ��� ������ �����Ͽ���. main.cpp���� extern void doSomething()�� �����Ϸ����� doSomething()�� ���ǰ� ��򰡿� ������ ���߿� linking �� ��� �����ִ� ���̴�.

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
�̷��� ���ָ� ������ �޸𸮿� �ִ� const ���� pi�� gravity�� �ݺ������� ����ϴ� ���̱� ������ ���ʿ��� �޸� ���� �߻����� �ʴ´�.

<h3>4_3 Using���� ��ȣ��</h3>

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

namespace �� ������ �۰� �ϴ� ���� ����! ������� �����ִ� ���� ���̱�!

<h3>4_4 auto Ű����� �ڷ��� �߷�</h3>

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
auto�� ������ �ʱ�ȭ�� ��, �ʱ�ȭ ���� �̿��Ͽ� ������ Ÿ���� �ڵ����� �����ش�. �Լ��� ��ȯ���� ���� auto�� ����� �� �ִ�. ��, auto�� parameter���� �� ���� ����. (�� ���� template�� �̿��ϰ� �ȴ�.)

```cpp
auto add(int x, int y) -> int;
auto add(int x, int y) -> double;
```
�̷������ε� ��� �����ϴ�.

<h3>4_5 ����ȯ Type conversion</h3>

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
typeid�� ����Ͽ� ������ ���ͷ��� ������ Ÿ���� �� �� �ִ�.

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
�̷��� ū ������ Ÿ���� ���� ������ Ÿ�Կ� ������ �ϸ� �ǵ�ġ ���� ������ �ս��̳� ������ �߻��� �� �־� �����ؾ� �Ѵ�.

```cpp
#include <iostream>
#include <iomanip>

int main(){
    using namespace std;

    // numeric conversion
    cout << 5u - 10u;    // output 4294967291

    // �켱����
    // int, unsigned int, long, unsigned long,
    // long long, unsigned long long, float, double,
    // long double

    int i = static_cast<int>(4.0);

    return 0;
}
```

<h3>4_6 ���ڿ� std string �Ұ�</h3>
