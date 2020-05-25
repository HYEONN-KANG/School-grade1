<h3>6_1 배열 기초 array[1 of 2]</h3>
배열은 0부터 시작된다. 헷갈리지 말기!

```cpp
#include <iostream>

using namespace std;

int main(){
    int my_array[5] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++)
        cout << my_array[i];

    return 0;
}
```

배열은 구조체, enum와도 함께 사용 가능하다.

```cpp
#include <iostream>

using namespace std;

struct Rectangle{
    int length;
    int width;
};

enum StudentName{
    Sam,        // 0
    Brian,      // 1
    Jinny,      // 2
};

int main(){
    cout << sizeof(Rectangle) << endl;

    Rectangle rect_arr[10];

    cout << sizeof(rect_arr) << endl;

    rect_arr[0].length = 1;
    rect_arr[0].width = 1;

    int my_array[5] = {1, 2, 3, 4, 5};

    cout << my_array[0] << endl;
    cout << my_array[1] << endl;
    cout << my_array[2] << endl;


    cout << "\nenum " << my_array[Sam] << endl;

    return 0;
}
```

<h3>6_2 배열 기초 array[2 of 2]</h3>
배열은 이름 자체가 내부적으로 주소로 사용되기 때문에 &를 붙인 값과 안 붙인 값이 똑같다.<br>
doSomething() 괄호 안에 있는 매개변수 int students_scores[20] 은 엄밀히 말하자면 배열이 아니라 포인터이다. 그러니까 배열의 모든 원소를 복사해서 가져오는 것이 아니라 배열의 첫번째 주소값만 복사해오는 것이다. 따라서 doSomething() 함수 안의 students_scores는 '포인터 변수'이기 때문에 이 자체의 주소는 실제 배열의 주소와 다른 값이 나온다.

아래 sizeof(students_score)은 int 20 * 4 = 80 으로 나오는데<br>
doSomething 에서의 sizeof(students_scores)는 8로 나오는 이유는 
32 비트에서의 포인터 변수의 사이즈는 4바이트인데 64비트에서의 포인터 변수의 사이즈는 8바이트 이기 때문이다.

```cpp
#include <iostream>

using namespace std;

void doSomething(int students_scores[]){
    cout << (long long)&students_scores << endl;
    cout << students_scores[0] << endl;
    cout << students_scores[1] << endl;
    cout << students_scores[2] << endl;

    cout << "size in doSomething " << sizeof(students_scores) << endl;
}
int main(){
    const int num_students = 20;

    int students_score[num_students] = {1, 2, 3, 4, 5};
    
    cout << (long long)students_score << endl;
    cout << (long long)&students_score << endl;
    cout << "size in main " << sizeof(students_score) << endl;

    doSomething(students_score);

    return 0;
}
```

<h3>6_3 배열과 반복문</h3>

```cpp
#include <iostream>

using namespace std;

int main(){
    int scores[] = {84, 92, 76, 81, 56};
    const int num_students = sizeof(scores) / sizeof(int);

    int max_score = 0;
    int min_score = 100;
    int total_score = 0;

    for(int i = 0; i < num_students; i++){
        total_score += scores[i];
        if(scores[i] > max_score) max_score = scores[i];
        if(scores[i] < min_score) min_score = scores[i];
    }

    double avg_scores = static_cast<double>(total_score) / num_students;

    cout << avg_scores << endl;
    cout << max_score << endl;
    cout << min_score << endl;

    return 0;
}
```

<h3>6_4 배열과 선택 정렬 selection sort</h3>

              value   index
    3 5 2 1 4   1       3
    1 5 2 3 4   2       2 
    1 2 5 3 4   3       3
    1 2 3 5 4   5       3
    1 2 3 4 5
이렇게 출력할 수 있도록 selection sort를 배열을 이용해서 구현해보기

```cpp
#include <iostream>

using namespace std;

void printArray(int array[], int length){
    for(int index = 0; index < length; index++){
       cout << array[index] << " ";
   }cout << endl;
}

void sortArray(int array[], int length, int min, int minIndex);

int main(){
   const int length = 5;

   int array[length] = {3, 5, 2, 1, 4};

   printArray(array, length);

   for(int i = 0; i < length - 1; i++){
       sortArray(array, length, array[i], i);
       printArray(array, length);
   }

    return 0;
}

void sortArray(int array[], int length, int min, int minIndex){
    int originMin = min;
    int originIndex = minIndex;

    for(int i = minIndex; i < length; i++){
        if(min > array[i]){
            min = array[i];
            minIndex = i;
        }
    }

    array[originIndex] = min;
    array[minIndex] = originMin;
}
```

이번엔 bubble sort로 구현해보자.

```cpp
#include <iostream>

using namespace std;

void printArray(int array[], int length){
    for(int index = 0; index < length; index++){
       cout << array[index] << " ";
   }cout << endl;
}

int sortArray(int array[], int length);

int main(){
   const int length = 5;

   int array[length] = {3, 5, 2, 1, 4};

   printArray(array, length);

   for(int i = 0; i < length - 1; i++){
       if(sortArray(array, length) == 0) break;
       printArray(array, length);
   }

    return 0;
}

int sortArray(int array[], int length){
    int exchange = 0;

    for(int i = 0; i < length - 1; i++){
        if(array[i] > array[i+1]){
            int temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;

            exchange++;
        }
    }

    return exchange;
}
```

<h3>6_5 정적 다차원 배열 Multi-dimensional Array</h3>

```cpp
#include <iostream>

using namespace std;

int main(){
    const int num_rows = 3;
    const int num_columns = 5;

    for(int row = 0; row < num_rows; row++){
        for(int col = 0; col < num_columns; col++){
            cout << "[" << row << "]" << "[" << col << "]" << "\t";
        }
        cout << endl;
    }

    int array[num_rows][num_columns] =
    {
        {1, 2, },
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };

    for(int row = 0; row < num_rows; row++){
        for(int col = 0; col < num_columns; col++){
            cout << array[row][col] << "\t";
        }
        cout << endl;
    }

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

int main(){
    int array[5][4][3] = {0};

    for(int row = 0; row < 5; row++){
        for(int col = 0; col < 4; col++){
            for(int col2 = 0; col2 < 3; col2++)
                cout << (long long)array[row][col] << "\t";
        }
        cout << endl;
    }

    return 0;
}
```

<h3>6_6 C언어 스타일의 배열 문자열</h3>
문자열 맨 뒤에는 우리 눈엔 보이지 않지만 null charater 이 있다. 따라서 아래의 문자열의 길이는 총 7 인 것이다.

```cpp
#include <iostream>

using namespace std;

int main(){
    char myString[] = "string";

    cout << sizeof(myString) / sizeof(char) << endl;

    return 0;
}
```

<h3>6_7 포인터의 기본적인 사용법 Pointer</h3>

지역변수는 '스택' 메모리를 사용하고, 동적 할당 메모리는 '힙' 메모리를 사용한다.

큰 메모리에 저장되어 있는 데이터 중에서 일부분을 CPU가 사용하기 위하여 메모리로부터 가져올 때는 메모리 전체를 모두 뒤지면서 찾는 것이 아니라 필요한 데이터가 저장되어 있는 '주소'를 사용하여 직접 접근하여 가져온다.

de-refernce는 포인터가 "저쪽 주소에 가면 이 데이터가 있어요"라고 간접적으로 가리키기만 하는 것에 대해서 "그럼 거기에 진짜 뭐가 있는지 내가 들여다볼게"라며 직접적으로 접근하겠다는 의미이다.

```cpp
#include <iostream>
using namespace std;

int main(){
    int x = 5;

    cout << x << endl;
    cout << &x << endl; // & : address-of operator

    // de-reference operator (*)

    cout << *(&x) << endl;  // output 5

    return 0;
}
```

포인터는 메모리 '주소'를 담는 변수이다. 포인터를 선언할 때에서 앞에 데이터 타입이 필요한 이유는 de-referenceing을 할 때 갖고 올 데이터 타입을 필요로 하기 때문이다.<br>
32bit에서는 포인터 변수의 크기는 4byte, 64bit에서는 포인터 변수의 크기는 8byte

```cpp
#include <iostream>
#include <typeinfo>
using namespace std;

struct Something{
    int a, b, c, d;
};

int main(){
    int x = 5;
    double d = 1.0;

    // typedef int* pint;
    int *ptr_x = &x;
    double *ptr_d = &d;
    // pint ptr_x = &x;

    cout << ptr_x << endl;
    cout << *ptr_x << endl;

    cout << ptr_d << endl;
    cout << *ptr_d << endl;

    cout << typeid(ptr_x).name() << endl;

    cout << sizeof(x) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(&x) << " " << sizeof(ptr_x) << endl;
    cout << sizeof(&d) << " " << sizeof(ptr_d) << endl;

    Something ss;
    Something *ptr_s;

    cout << sizeof(Something) << endl;
    cout << sizeof(ptr_s) << endl;

    return 0;
}
```

<h3>6_7a 널 포인터 Null Pointer</h3>

포인터의 위험성 중에서 쓰레기 주솟값이 들어간 경우에 de-referencing을 시도하면 메모리에 데이터가 잘 담겨있는 곳이 아니라 엉뚱한 곳에 가서 메모리를 찾는다. 따라서 null pointer를 사용한다.

```cpp
#include <iostream>
#include <cstddef>
using namespace std;

void doSomething(double *ptr){
    cout << "address of pointer variable in doSomething() " << &ptr << endl;

    if(ptr != nullptr){
        cout << *ptr << endl;
    }
    else{
        cout << "Null ptr, do nothing" << endl;
    }
}

int main(){
    double *ptr = nullptr;  // modern C++
    // double *ptr = NULL;  C++ style
    // double *ptr = 0;  C style

    doSomething(ptr);
    doSomething(nullptr);

    double d = 123.4;

    doSomething(&d);

    ptr = &d;
    doSomething(ptr);

    cout << "address of pointer variable in main() " << &ptr << endl;

    return 0;
}
```

<h3>6_8 포인터와 정적 배열</h3>

배열 == 포인터

```cpp
#include <iostream>
using namespace std;

int main(){
    int array[5] = {9, 7, 5, 3, 1};

    cout << array << endl;
    cout << &array[0] << endl;

    cout << *array << endl;

    int *ptr = array;
    cout << ptr << endl;
    cout << *ptr << endl;
}

/* output
0x78fe00
0x78fe00
9
0x78fe00
9
*/
```

printArray 함수 내부에서 array 변수의 size를 출력해보면 8이 나온다. 왜 20이 아니라 8 이 나올까? 함수의 파라미터로 있는 array[]은 배열처럼 보이지만 사실은 포인터이다. 따라서 포인터 size 크기인 8이 출력된다.

```cpp
#include <iostream>
using namespace std;

// void printArray(int *array)
void printArray(int array[]){
    cout << sizeof(array) << endl;
    cout << *array << endl;

    *array = 100;
}

int main(){
    int array[5] = {9, 7, 5, 3, 1};

    cout << sizeof(array) << endl;

    int *ptr = array;
    cout << sizeof(ptr) << endl;

    printArray(array);

    cout << array[0] << " " << *array << endl;
}

/*output
20
8
8
9
100 100
*/
```

array가 구조체나 class 안에 들어있을 때는 포인터로 강제 변환되지 않고 array 자체가 전달된다.

```cpp
#include <iostream>
using namespace std;

struct Mystruct{
    int array[5] = {9, 7, 5, 3, 1};
};

void doSomething(Mystruct *ms){
    cout << sizeof((*ms).array) << endl;
}

int main(){
    Mystruct ms;
    cout << ms.array[0] << endl;
    cout << sizeof(ms.array) << endl;

    doSomething(&ms);
}

/*output
9
20
20
*/
```

<h3>6_9 포인터 연산과 배열 인덱싱(Indexing)</h3>

포인터를 선언할 때 데이터 타입의 역할은! 포인터 연산을 할 때 의미하는 저 1이 몇 byte인가를 알려준다.

```cpp
#include <iostream>
using namespace std;

int main(){
    short value = 7;
    short *ptr = &value;

    cout << uintptr_t(ptr - 1) << endl;
    cout << uintptr_t(ptr) << endl;
    cout << uintptr_t(ptr + 1) << endl;
    cout << uintptr_t(ptr + 2) << endl;
}

/*output
7929364
7929366
7929368
7929370
*/
```

```cpp
#include <iostream>
using namespace std;

int main(){
    int array[] = {9, 7, 5, 3, 1};
    int *ptr = array;

    for(int i = 0; i < 5; i++){
        cout << array[i] << " " << (uintptr_t)&array[i] << endl;
    }cout << endl;

    for(int i = 0; i < 5; i++){
        cout << *(ptr+i) << " " << (uintptr_t)(ptr+i) << endl;
    }
}

/*output
9 7929328
7 7929332
5 7929336
3 7929340
1 7929344

9 7929328
7 7929332
5 7929336
3 7929340
1 7929344
*/
```

```cpp
#include <iostream>
using namespace std;

int main(){
    char name[] = "hello";

    const int n_name = sizeof(name) / sizeof(char);

    char *ptr = name;

    for(int i = 0; i < n_name; i++){
        cout << *(name + i);
    }
    for(int i = 0; i < n_name; i++){
        cout << *(ptr + i);
    }
}

/*output
hello hello
*/
```

(연습문제) 포인터 연산을 사용해서 null character을 제외하고 출력하기

```cpp
#include <iostream>
using namespace std;

int main(){
    char name[] = "hello";

    const int n_name = sizeof(name) / sizeof(char);

    char *ptr = name;

    for(int i = 0; i < n_name; i++){
        if(*(name + i) == '\0') break;
        cout << *(name + i);
    }
    for(int i = 0; i < n_name; i++){
        if(*(ptr + i) == '\0') break;
        cout << *(ptr + i);
    }
}

/*output
hellohello
*/
```

<h3>6_10 C언어 스타일의 문자열 심볼릭Symbolic 상수</h3>

```cpp
#include <iostream>
using namespace std;

const char *getName(){
    return "hello";
}

int main(){
    // char name[] = "hello";
    const char *name = getName();
    const char *name2 = getName();

    cout << (uintptr_t)name << endl;
    cout << (uintptr_t)name2 << endl;
}

/*output
4943873
4943873
*/
```

```cpp
#include <iostream>
using namespace std;

int main(){
    int int_arr[5] = {1, 2, 3, 4, 5};
    char char_arr[] = "Hello, World!";
    const char *name = "Harry Porter";

    cout << int_arr << endl;
    cout << char_arr << endl;
    cout << name << endl;
}

/*output
0x78fe00
Hello, World!
Harry Porter
*/
```