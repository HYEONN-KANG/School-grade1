<h3>5_1 제어 흐름 개요 Control flow</h3>

![image](https://user-images.githubusercontent.com/62539341/82325672-94862a00-9a16-11ea-9485-2fd448099146.png)

- 중단 Halt
- 반복(루프) Loops
  - while, do while, for
- 점프 jump
  - goto, break, continue
- 조건 분기 Conditional branches
  - if, switch
- 예외 처리 Exceptions
  - try, catch, throw

return 0;는 정상적으로 프로그램을 종료 시키고 나간다는 느낌이고<br>
exit(0);는 긴급하게 빠져나간다는 느낌?

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

<h3>5_2 조건문 if</h3>

```cpp
if(조건){
    실행할 문장
}
```

<h3>5_3 switch-case</h3>

```cpp
switch(변수){
    case 상수1:
        실행할 문장
        ...
        break;
    case 상수2:
    {
        실행할 문장
        ...
        break;
    }
    case 상수3:
        실행할 문장
        ...
        break;
    default:
        실행할 문장
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

<h3>5_5 반복문 while</h3>

```cpp
while(조건){
    실행할 문장;
    실행할 문장;
    실행할 문장;
}
```

<h3>5_6 반복문 do-while</h3>
while문은 조건에 따라서 단 한번도 실행이 되지 않을 수도 있는데 do-while 문은 일단 한번 실행하고 조건을 살피는 구조이다.

```cpp
do{
    실행할 문장;
}while(조건);
```

<h3>5_7 반복문 for</h3>

```cpp
for(초기값; 조건; 증감?){
    실행할 문장;
}
```

<h3>5_8 break, continue</h3>
break는 현재 블록에서 '빠져나간다'

```cpp
// 0부터 10까지 출력하는 프로그램
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

continue는 '건너뛴다'

```cpp
// 홀수만 출력하는 프로그램
#include <iostream>
using namespace std;

int main(){
    for(int i = 0; i < 10; i++){
        if(i % 2 == 0) continue;
        
        cout << i << endl;
    }
}
```

<h3>5_9 난수 만들기 random numbers</h3>
