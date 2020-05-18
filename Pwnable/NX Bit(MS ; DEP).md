<h1>NX Bit(MS : DEP)</h1>

<h3>NX Bit(MS : DEP)</h3>

- NX Bit(Never eXecute bit, 실행 방지 비트)는 무엇일까?

프로세스 명령어나 코드 또는 데이터 저장을 위한 메모리 영역을 따로 분리하는 CPU 기술이다. NX 로 지정된 메모리는 데이터 저장을 위해서만 사용되며, 프로세서 명령어가 그 곳에 있지 않게 해서 실행되지 않도록 만들어 준다.

- DEP(Data Execution Prevention)이란?

마이크로소프트 윈도우 운영체제에 있는 보안 기능이다. 악의적인 코드가 실행되는 것을 막기 위해 메모리를 추가로 확인하는 기술이다.

DEP는 두 가지 모드로 실행된다.

1. 하드웨어 DEP : 메모리에 명시적으로 실행 코드가 포함되어 있는 경우를 제외하고 프로세스의 모든 메모리 위치에서 실행할 수 없도록 표시한다.(대부분의 최신 프로세서는 하드웨어 적용 DEP를 지원한다.)
2. 소프트웨어 DEP : CPU가 하드웨어 DEP를 지원하지 않으면 사용한다.

- 예를 들어 공격자가 Heap, Stack 영역에 Shellcode를 저장하고 실행하기 위해서는 excute 권한이 있어야 한다.

DEP가 적용되지 않으면? 쉘코드가 실행 된다.<br>
DEP가 적용되면? excute 권한이 없으니까 쉘코드가 실행되지 않는다.

<h3>Example program</h3>

bof 취약점이 있는 프로그램에 빌드 할 때 스택에 excute 권한을 설정하여 컴파일 한다.

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

- DEP enabled의 경우 실행권한(--x-)을 가지고 있는 영역은 5곳
- DEP disabled의 경우 실행권한(--x-)을 가지고 있는 영역은 17

![image](https://user-images.githubusercontent.com/62539341/82214093-34c54b80-9950-11ea-9d82-c3888b32095f.png)

![image](https://user-images.githubusercontent.com/62539341/82214112-40187700-9950-11ea-897b-cd435d376a62.png)

<h3>How to detect NX in the "Checksec.sh" file</h3>

- Binary

바이너리의 NX 설정여부를 확인한다.<br>
readelf 명령어를 이용해 파일의 세그멘트 헤더 정보에서 NX 여부를 확인<br>
파일의 세그먼트 헤더 정보에서 'GNU_STACK'의 Flg 값이 'RWE'이라면 NX가 활성화되었다고 판단

![image](https://user-images.githubusercontent.com/62539341/82216254-ac48aa00-9953-11ea-9753-e81f5e8cd803.png)

NX가 적용된 바이너리의 Flg 값이 'RW'
NX가 적용되지 않은 바이너리의 Flg 값이 'RWE'

![image](https://user-images.githubusercontent.com/62539341/82216486-fb8eda80-9953-11ea-8c5f-6b40628fa520.png)

- Process

다음의 방법으로 NX 설정여부를 확인한다.
Binary 확인 방식과 똑같고, 전달되는 파일의 경로는 다음과 같이 다르다.
  -EX) /proc/<\pid\>/exe

![image](https://user-images.githubusercontent.com/62539341/82217530-83c1af80-9955-11ea-8fdf-e91e019c1fa4.png)

- CPU

"/proc/cpuinfo" 파일에서 'nx' 문자가 있는지 확인한다.

![image](https://user-images.githubusercontent.com/62539341/82217936-1b270280-9956-11ea-97b3-7dfa19b5ba31.png)
