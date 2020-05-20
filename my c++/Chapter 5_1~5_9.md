<h3>5_1 ���� �帧 ���� Control flow</h3>

![image](https://user-images.githubusercontent.com/62539341/82325672-94862a00-9a16-11ea-9485-2fd448099146.png)

- �ߴ� Halt
- �ݺ�(����) Loops
  - while, do while, for
- ���� jump
  - goto, break, continue
- ���� �б� Conditional branches
  - if, switch
- ���� ó�� Exceptions
  - try, catch, throw

return 0;�� ���������� ���α׷��� ���� ��Ű�� �����ٴ� �����̰�<br>
exit(0);�� ����ϰ� ���������ٴ� ����?

```cpp
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    cout << "I love you" << endl;

    exit(0);

    cout << "I love you, too" << endl;

    return 0;
}
```

<h3>5_2 ���ǹ� if</h3>

```cpp
if(����){
    ������ ����
}
```

<h3>5_3 switch-case</h3>

```cpp
switch(����){
    case ���1:
        ������ ����
        ...
        break;
    case ���2:
    {
        ������ ����
        ...
        break;
    }
    case ���3:
        ������ ����
        ...
        break;
    default:
        ������ ����
        ...
        break;
}
```

<h3>5_4 goto</h3>

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x;

tryAgain :  // label

    cout << "Enter a non-negative number" << endl;
    cin >> x;
    
    if(x < 0.0){
        goto tryAgain;
    }

    cout << sqrt(x) << endl;
    
    return 0;
}
```

<h3>5_5 �ݺ��� while</h3>

```cpp
while(����){
    ������ ����;
    ������ ����;
    ������ ����;
}
```

<h3>5_6 �ݺ��� do-while</h3>
while���� ���ǿ� ���� �� �ѹ��� ������ ���� ���� ���� �ִµ� do-while ���� �ϴ� �ѹ� �����ϰ� ������ ���Ǵ� �����̴�.

```cpp
do{
    ������ ����;
}while(����);
```

<h3>5_7 �ݺ��� for</h3>

```cpp
for(�ʱⰪ; ����; ����?){
    ������ ����;
}
```

<h3>5_8 break, continue</h3>
break�� ���� ��Ͽ��� '����������'

```cpp
// 0���� 10���� ����ϴ� ���α׷�
#include <iostream>
using namespace std;

int main(){
    int count = 0;

    while(true){
        cout << count << endl;
        if(count == 10) break;
        count++;
    }
}
```

continue�� '�ǳʶڴ�'

```cpp
// Ȧ���� ����ϴ� ���α׷�
#include <iostream>
using namespace std;

int main(){
    for(int i = 0; i < 10; i++){
        if(i % 2 == 0) continue;
        
        cout << i << endl;
    }
}
```

<h3>5_9 ���� ����� random numbers</h3>
rand() �Լ��� ������� �ʰ� ����? ���� ���� 100�� ����غ���

```cpp
#include <iostream>

using namespace std;

unsigned int PRNG() // Pseudo Random Number Generator
{
    static unsigned int seed = 5523;    // seed number

    seed = 8253797 * seed + 2396403;

    return seed % 32768;
}

int main(){
    for(int count = 1; count <= 100; count++){
        cout << PRNG() << "\t";

        if(count % 5 == 0) cout << endl;
    }

    return 0;
}
```
��ǻ�ʹ� ����� �ƴϱ� ������ seed number�� �����Ǿ� ���� �� �����ϴ� random number ���� �����ϴ�.(������� �� �Ϻη� seed number �� ������Ų��.) time() �Լ��� �̿��ؼ� seed ���� �ٲ��ָ� random number�� ��¥ �������� ���� �� �ִ�.

```cpp
#include <iostream>
#include <cstdlib>  // std::rand(), std::srand()
#include <ctime>    // std::time()

using namespace std;

int main(){

    std::srand(time(0));   // seed

    for(int count = 1; count <= 100; count++){
        cout << std::rand() << "\t";

        if(count % 5 == 0) cout << endl;
    }

    return 0;
}
```

```cpp
#include <iostream>
#include <cstdlib>  // std::rand(), std::srand()
#include <ctime>    // std::time()

using namespace std;

int getRandomNumber(int min, int max){
    static const double fraction = 1.0 / (RAND_MAX + 1.0);  // RAND_MAX�� random number�� ����� �ִ� ���� ū �����̴�.

    return min + static_cast<int>((max - min + 1)*(rand() * fraction));
}

int main(){

    std::srand(time(0));   // seed

    for(int count = 1; count <= 100; count++){
        cout << getRandomNumber(5, 8) << "\t";

        if(count % 5 == 0) cout << endl;
    }

    return 0;
}
```

random device�� �����ؼ� �Ʒ��� ���� ����� �ָ�(�Ʊ� time(0)�� �־��� �Ͱ� ���� ����) ������ Ȯ���� �������� ���� �����ϴ�.

```cpp
#include <iostream>
#include <cstdlib>  // std::rand(), std::srand()
#include <ctime>    // std::time()
#include <random>

using namespace std;

int main(){
    std::random_device rd;  // ������ random device�� ����
    std::mt19937_64 mesenne(rd());  // create a mesenne twister
    std::uniform_int_distribution<> dice(1, 6);

    for(int count = 1; count <= 20; count++){
        cout << dice(mesenne) << endl;
    }
    
    return 0;
}
```