<h1>NX Bit(MS : DEP)</h1>

<h3>NX Bit(MS : DEP)</h3>

- NX Bit(Never eXecute bit, ���� ���� ��Ʈ)�� �����ϱ�?

���μ��� ��ɾ �ڵ� �Ǵ� ������ ������ ���� �޸� ������ ���� �и��ϴ� CPU ����̴�. NX �� ������ �޸𸮴� ������ ������ ���ؼ��� ���Ǹ�, ���μ��� ��ɾ �� ���� ���� �ʰ� �ؼ� ������� �ʵ��� ����� �ش�.

- DEP(Data Execution Prevention)�̶�?

����ũ�μ���Ʈ ������ �ü���� �ִ� ���� ����̴�. �������� �ڵ尡 ����Ǵ� ���� ���� ���� �޸𸮸� �߰��� Ȯ���ϴ� ����̴�.

DEP�� �� ���� ���� ����ȴ�.

1. �ϵ���� DEP : �޸𸮿� ��������� ���� �ڵ尡 ���ԵǾ� �ִ� ��츦 �����ϰ� ���μ����� ��� �޸� ��ġ���� ������ �� ������ ǥ���Ѵ�.(��κ��� �ֽ� ���μ����� �ϵ���� ���� DEP�� �����Ѵ�.)
2. ����Ʈ���� DEP : CPU�� �ϵ���� DEP�� �������� ������ ����Ѵ�.

- ���� ��� �����ڰ� Heap, Stack ������ Shellcode�� �����ϰ� �����ϱ� ���ؼ��� excute ������ �־�� �Ѵ�.

DEP�� ������� ������? ���ڵ尡 ���� �ȴ�.<br>
DEP�� ����Ǹ�? excute ������ �����ϱ� ���ڵ尡 ������� �ʴ´�.

<h3>Example program</h3>

bof ������� �ִ� ���α׷��� ���� �� �� ���ÿ� excute ������ �����Ͽ� ������ �Ѵ�.

```cpp
#include <stdio.h>
#include <stdlib.h>
 
int main(){
    char str[256];
    char *chare = (char*)malloc(100);
 
    printf("Input: ");
    gets(str);
    printf("%p\n", str);
}
```

<h3>Check the protection techniques of binary files</h3>

- Checksec.sh
  - DEP-disabled file: NX disabled
  - DEP-enabled file : NX enabled

![image](https://user-images.githubusercontent.com/62539341/82213852-cc766a00-994f-11ea-9e5c-d2112c6743bc.png)


<h3>Checking Permissions in Memory</h3>

- DEP enabled�� ��� �������(--x-)�� ������ �ִ� ������ 5��
- DEP disabled�� ��� �������(--x-)�� ������ �ִ� ������ 17

![image](https://user-images.githubusercontent.com/62539341/82214093-34c54b80-9950-11ea-9d82-c3888b32095f.png)

![image](https://user-images.githubusercontent.com/62539341/82214112-40187700-9950-11ea-897b-cd435d376a62.png)

<h3>How to detect NX in the "Checksec.sh" file</h3>

- Binary

���̳ʸ��� NX �������θ� Ȯ���Ѵ�.<br>
readelf ��ɾ �̿��� ������ ���׸�Ʈ ��� �������� NX ���θ� Ȯ��<br>
������ ���׸�Ʈ ��� �������� 'GNU_STACK'�� Flg ���� 'RWE'�̶�� NX�� Ȱ��ȭ�Ǿ��ٰ� �Ǵ�

![image](https://user-images.githubusercontent.com/62539341/82216254-ac48aa00-9953-11ea-9753-e81f5e8cd803.png)

NX�� ����� ���̳ʸ��� Flg ���� 'RW'
NX�� ������� ���� ���̳ʸ��� Flg ���� 'RWE'

![image](https://user-images.githubusercontent.com/62539341/82216486-fb8eda80-9953-11ea-8c5f-6b40628fa520.png)

- Process

������ ������� NX �������θ� Ȯ���Ѵ�.
Binary Ȯ�� ��İ� �Ȱ���, ���޵Ǵ� ������ ��δ� ������ ���� �ٸ���.
  -EX) /proc/<\pid\>/exe

![image](https://user-images.githubusercontent.com/62539341/82217530-83c1af80-9955-11ea-8fdf-e91e019c1fa4.png)

- CPU

"/proc/cpuinfo" ���Ͽ��� 'nx' ���ڰ� �ִ��� Ȯ���Ѵ�.

![image](https://user-images.githubusercontent.com/62539341/82217936-1b270280-9956-11ea-97b3-7dfa19b5ba31.png)
