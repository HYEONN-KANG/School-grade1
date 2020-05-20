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
