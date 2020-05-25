<h3>6_1 �迭 ���� array[1 of 2]</h3>
�迭�� 0���� ���۵ȴ�. �򰥸��� ����!

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

�迭�� ����ü, enum�͵� �Բ� ��� �����ϴ�.

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

<h3>6_2 �迭 ���� array[2 of 2]</h3>
�迭�� �̸� ��ü�� ���������� �ּҷ� ���Ǳ� ������ &�� ���� ���� �� ���� ���� �Ȱ���.<br>
doSomething() ��ȣ �ȿ� �ִ� �Ű����� int students_scores[20] �� ������ �����ڸ� �迭�� �ƴ϶� �������̴�. �׷��ϱ� �迭�� ��� ���Ҹ� �����ؼ� �������� ���� �ƴ϶� �迭�� ù��° �ּҰ��� �����ؿ��� ���̴�. ���� doSomething() �Լ� ���� students_scores�� '������ ����'�̱� ������ �� ��ü�� �ּҴ� ���� �迭�� �ּҿ� �ٸ� ���� ���´�.

�Ʒ� sizeof(students_score)�� int 20 * 4 = 80 ���� �����µ�<br>
doSomething ������ sizeof(students_scores)�� 8�� ������ ������ 
32 ��Ʈ������ ������ ������ ������� 4����Ʈ�ε� 64��Ʈ������ ������ ������ ������� 8����Ʈ �̱� �����̴�.

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

<h3>6_3 �迭�� �ݺ���</h3>

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

<h3>6_4 �迭�� ���� ���� selection sort</h3>

              value   index
    3 5 2 1 4   1       3
    1 5 2 3 4   2       2 
    1 2 5 3 4   3       3
    1 2 3 5 4   5       3
    1 2 3 4 5
�̷��� ����� �� �ֵ��� selection sort�� �迭�� �̿��ؼ� �����غ���

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

�̹��� bubble sort�� �����غ���.

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

<h3>6_5 ���� ������ �迭 Multi-dimensional Array</h3>

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

<h3>6_6 C��� ��Ÿ���� �迭 ���ڿ�</h3>
���ڿ� �� �ڿ��� �츮 ���� ������ ������ null charater �� �ִ�. ���� �Ʒ��� ���ڿ��� ���̴� �� 7 �� ���̴�.

```cpp
#include <iostream>

using namespace std;

int main(){
    char myString[] = "string";

    cout << sizeof(myString) / sizeof(char) << endl;

    return 0;
}
```

<h3>6_7 �������� �⺻���� ���� Pointer</h3>

���������� '����' �޸𸮸� ����ϰ�, ���� �Ҵ� �޸𸮴� '��' �޸𸮸� ����Ѵ�.

ū �޸𸮿� ����Ǿ� �ִ� ������ �߿��� �Ϻκ��� CPU�� ����ϱ� ���Ͽ� �޸𸮷κ��� ������ ���� �޸� ��ü�� ��� �����鼭 ã�� ���� �ƴ϶� �ʿ��� �����Ͱ� ����Ǿ� �ִ� '�ּ�'�� ����Ͽ� ���� �����Ͽ� �����´�.

de-refernce�� �����Ͱ� "���� �ּҿ� ���� �� �����Ͱ� �־��"��� ���������� ����Ű�⸸ �ϴ� �Ϳ� ���ؼ� "�׷� �ű⿡ ��¥ ���� �ִ��� ���� �鿩�ٺ���"��� ���������� �����ϰڴٴ� �ǹ��̴�.

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

�����ʹ� �޸� '�ּ�'�� ��� �����̴�. �����͸� ������ ������ �տ� ������ Ÿ���� �ʿ��� ������ de-referenceing�� �� �� ���� �� ������ Ÿ���� �ʿ�� �ϱ� �����̴�.<br>
32bit������ ������ ������ ũ��� 4byte, 64bit������ ������ ������ ũ��� 8byte

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

<h3>6_7a �� ������ Null Pointer</h3>

�������� ���輺 �߿��� ������ �ּڰ��� �� ��쿡 de-referencing�� �õ��ϸ� �޸𸮿� �����Ͱ� �� ����ִ� ���� �ƴ϶� ������ ���� ���� �޸𸮸� ã�´�. ���� null pointer�� ����Ѵ�.

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

<h3>6_8 �����Ϳ� ���� �迭</h3>

�迭 == ������

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

printArray �Լ� ���ο��� array ������ size�� ����غ��� 8�� ���´�. �� 20�� �ƴ϶� 8 �� ���ñ�? �Լ��� �Ķ���ͷ� �ִ� array[]�� �迭ó�� �������� ����� �������̴�. ���� ������ size ũ���� 8�� ��µȴ�.

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

array�� ����ü�� class �ȿ� ������� ���� �����ͷ� ���� ��ȯ���� �ʰ� array ��ü�� ���޵ȴ�.

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

<h3>6_9 ������ ����� �迭 �ε���(Indexing)</h3>

�����͸� ������ �� ������ Ÿ���� ������! ������ ������ �� �� �ǹ��ϴ� �� 1�� �� byte�ΰ��� �˷��ش�.

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

(��������) ������ ������ ����ؼ� null character�� �����ϰ� ����ϱ�

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

<h3>6_10 C��� ��Ÿ���� ���ڿ� �ɺ���Symbolic ���</h3>

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