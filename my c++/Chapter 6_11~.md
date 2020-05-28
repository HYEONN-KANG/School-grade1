<h3>6_11 메모리 동적 할당(Dynamic Memory Allocation) new와 delete</h3>

우리가 만들 프로그램에 메모리가 할당되는 것은 세 가지 종류로 나뉜다. 첫 번째, Static Memory Allocation 정적 메모리 할당. 전역변수나 static 변수와 같이 한번 만들면 프로그램이 끝날 때까지 계속 메모리를 갖고 있는 것들을 의미한다. 그 다음으로, 자동 메모리 할당이 있다. 우리가 변수를 선언하거나 정적 배열을 선언했을 때 블록 밖으로 나가면 전부 사라지고 다시 메모리가 OS로 할당된다. 세 번째, 동적 메모리 할당이다. 

정적으로 할당하는 메모리는 stack에 들어간다. 그런데 stack은 용량이 작다. stack과 heap 이 있다. 동적으로 할당되는 메모리는 heap 에 들어간다. 그리고 heap은 용량이 훨씬 크다. 이러한 이유 때문에 동적 메모리 할당을 잘 사용하는 것이 필수적이다. 

여태 흔히 integer형 변수를 선언할 때 int var; 와 같이 변수를 선언했다. 이번에는 새롭게, new int 라는 것이 있다. new int는 integer size(4byte)에 맞춰서 OS에서 메모리를 받아 온 다음에 그 메모리 주소를 우리한테 알려준다. 

중요한 것은 할당받은 메모리를 OS에게 다시 돌려주는 것이다. 이것이 중요한 이유는 빅데이터나 인공지능, 딥러닝 이런 것을 하면 컴퓨터 한 대가 감당할 수 없는 데이터 양을 사용해야 한다. 메모리에 한번에 데이터가 모두 들어가지 못할 수도 있기 때문이다.    

```cpp
#include <iostream>

using namespace std;

int main(){
    // int var;
    // var = 7;

    int *ptr = new (std::nothrow) int(7);   // std::nothrow는 오류를 발생시키지 않도록 예방하는 것
    // *ptr = 7;

    if(ptr){
        cout << ptr << endl;
        cout << *ptr << endl;
    }else{
        cout << "Could not allocate memory" << endl;
    }

    delete ptr;
    ptr = nullptr;

    cout << "After delete" << endl;
    if(ptr != nullptr){
        cout << ptr << endl;
        cout << *ptr << endl;
    }

    return 0;
}

/*output
0xd51460
7
After delete
*/
```

메모리를 사용하지는 않고 계속 OS로부터 메모리를 받으면 굉장히 안 좋다. 

```cpp
#include <iostream>

using namespace std;

int main(){
    // memory leak
    while(true){
        int *ptr = new int;
        cout << ptr << endl;
    }

    return 0;
}
```

이 문제가 있는지 파악하는 방법으로
메모리 할당 받은 것이 클 경우에는 CPU 의 메모리 점유율을 확인 해볼 수 있다. (new와 delete은 속도가 조금 느리다. OS에 한번 갔다 오는 거라.. 적게 사용하는 것이 좋다.)

<h3>6_12 동적 할당 배열</h3>
