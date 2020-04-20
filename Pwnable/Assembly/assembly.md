출처 : https://www.inflearn.com/course/%EC%96%B4%EC%85%88%EB%B8%94%EB%A6%AC%EC%96%B4-%EB%B0%B0%EC%9A%B0%EA%B8%B0/lecture/1748

어셈블리어란 기계어와 1:1로 대응시켜 코드화한, 하드웨어와 가장 근접한 언어

어셈블리어는 Opcode와 Operand로 나뉜다.

```c
mov eax, 1 
```
Opcode가 mov, Operand가 eax, 1 부분이다.

하드웨어에는  CPU, RAM, 하드디스크 등이 있다. 연산은 CPU에서 일어나는데 CPU안의 저장공간을 Register라고 한다. 레지스터가 읽기, 쓰기할 때 속도가 가장 빠른 저장공간이다. 하지만 용량이 매우 작기 때문에 프로그램의 내용은 RAM에 있다. 데이터를 쓰거나 읽을때는 RAM에서, 직접적으로 연산을 할 때는 레지스터에서 저장을 한 뒤 계산한다.

<h4>mov</h4>

```c
mov reg, 값
mov reg, reg
mov reg, mem
mov mem, reg
// mov mem, mem 로 하는 건 X
```

<h4>범용 레지스터</h4>
EAX : 연산에 사용, 함수의 리턴 값이 저장된다.<br>
EBX : 간접 번지지정에 사용.<br>
ECX : loop에서 count 역할<br>
EDX : EAX 보조

<h4>포인터 레지스터</h4>
ESP : Stack Pointer의 가장 최근에 저장된 공간의 주소를 저장.<br>
      Stack이 쌓일 때마다 ESP 값이 1씩 증가.<br>
EBP : Stack Pointer의 기준점(바닥)을 저장. 밑에는 return 값이 존재.<br>
EIP : 다음 명령어의 위치를 저장

<h4>인덱스 레지스터</h4>
ESI : 출발지 주소를 저장<br>
EDI : 목적지 주소를 저장

<h4>메모리 주소와 접근</h4>

```c
mov [402000], al
mov byte ptr ds: [402000], al
```
al에 있는 값을 주소가 402000인 메모리에 넣어라.

```c
mov cl, [402000]
mov cl, byte ptr ds: [402000]
```
402000에 있는 데이터를 cl에 넣어라.

<h4>메모리 크기 지정</h4>

```c
mov byte ptr ds: [402000], al
mov byte ptr ds: [402000], al
mov byte ptr ds: [402000], al
```
Qword   = 8 Byte<br>
Dword   = 4 Byte<br>
Word    = 2 Byte<br>
Byte    = 1 Byte

CS      : 함수나 제어문 같은 명령어들이 저장되는 코드 세그먼트
DS      : 주로 전역, 정적 변수 데이터가 들어있는 데이터 세그먼트
SS      : 스택의 주소
ES      : 추가 세그먼트
FS, GS  : 추가 세그먼트

<h4>Little endian, Big endian</h4>
