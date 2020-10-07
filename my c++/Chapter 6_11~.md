<h3>6_11 �޸� ���� �Ҵ�(Dynamic Memory Allocation) new�� delete</h3>

�츮�� ���� ���α׷��� �޸𸮰� �Ҵ�Ǵ� ���� �� ���� ������ ������. ù ��°, Static Memory Allocation ���� �޸� �Ҵ�. ���������� static ������ ���� �ѹ� ����� ���α׷��� ���� ������ ��� �޸𸮸� ���� �ִ� �͵��� �ǹ��Ѵ�. �� ��������, �ڵ� �޸� �Ҵ��� �ִ�. �츮�� ������ �����ϰų� ���� � 迭 �� �������� �� ���� ������ ������ ���� ������� �ٽ� �޸𸮰� OS�� �Ҵ�ȴ�. �� ��°, ���� �޸� �Ҵ��̴�.

�������� �Ҵ��ϴ� �޸𸮴� stack�� ����. �׷��� stack�� �뷮�� �۴�. stack�� heap �� �ִ�. �������� �Ҵ�Ǵ� �޸𸮴� heap �� ����. �׸��� heap�� �뷮�� �ξ� ũ��. �̷��� ���� ������ ���� �޸� �Ҵ��� �� ����ϴ� ���� �ʼ����̴�.

���� ���� integer�� ������ ������ �� int var; �� ���� ������ �����ߴ�. �̹����� ���Ӱ�, new int ��� ���� �ִ�. new int�� integer size(4byte)�� ��� 缭 OS���� �޸𸮸� �޾� �� ������ �� �޸� �ּҸ� �츮���� �˷��ش�.

�߿��� ���� �Ҵ���� �޸𸮸� OS���� �ٽ� �����ִ� ���̴�. �̰��� �߿��� ������ �����ͳ� �ΰ�����, ������ �̷� ���� �ϸ� ��ǻ�� �� �밡 ������ �� ���� ������ ���� ����ؾ� �Ѵ�. �޸𸮿� �ѹ��� �����Ͱ� ��� ���� ���� ���� �ֱ� �����̴�.

```cpp
#include <iostream>

using namespace std;

int main(){
    // int var;
    // var = 7;

    int *ptr = new (std::nothrow) int(7);   // std::nothrow�� ������ �߻���Ű�� �ʵ��� �����ϴ� ��
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

�޸𸮸� ��������� �ʰ� ��� OS�κ��� �޸𸮸� ������ ������ �� ����.

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

�� ������ �ִ��� �ľ��ϴ� �������
�޸� �Ҵ� ���� ���� Ŭ ��쿡�� CPU �� �޸� �������� Ȯ�� �غ� �� �ִ�. (new�� delete�� �ӵ��� ���� ������. OS�� �ѹ� ���� ���� �Ŷ�.. ���� ����ϴ� ���� ����.)

<h3>6_12 동적 할당 배열</h3>

```cpp
#include <iostream>

using namespace std;

int main() {
	int length;
	cin >> length;

	int* array = new int[length]();

	array[0] = 1;
	array[1] = 2;

	for (int i = 0; i < length; ++i) {
		cout << (uintptr_t)&array[i] << endl;
		cout << array[i] << endl;
	}

	delete[] array;

	return 0;
}
```
