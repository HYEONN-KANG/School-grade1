출처 : https://www.inflearn.com/course/%EC%96%B4%EC%85%88%EB%B8%94%EB%A6%AC%EC%96%B4-%EB%B0%B0%EC%9A%B0%EA%B8%B0/lecture/1748

어셈블리어란 기계어와 1:1로 대응시켜 코드화한, 하드웨어와 가장 근접한 언어

어셈블리어는 Opcode와 Operand로 나뉜다.

```c
mov eax, 1 
```
Opcode가 mov, Operand가 eax, 1 부분이다.

하드웨어에는  CPU, RAM, 하드디스크 등이 있다. 연산은 CPU에서 일어나는데 CPU안의 저장공간을 Register라고 한다. 레지스터가 읽기, 쓰기할 때 속도가 가장 빠른 저장공간이다. 하지만 용량이 매우 작기 때문에 프로그램의 내용은 RAM에 있다. 데이터를 쓰거나 읽을때는 RAM에서, 직접적으로 연산을 할 때는 레지스터에서 저장을 한 뒤 계산한다.

----------------------------------------------------------------------------
<h3>범용 레지스터</h3>
- EAX : 연산에 사용, 함수의 리턴 값이 저장된다.<br>
- EBX : 간접 번지지정에 사용.<br>
- ECX : loop에서 count 역할<br>
- EDX : EAX 보조

<h3>포인터 레지스터</h3>
- ESP : Stack Pointer의 가장 최근에 저장된 공간의 주소를 저장.<br>
      Stack이 쌓일 때마다 ESP 값이 1씩 증가. Stack의 시작'주소'를 가짐.<br>
- EBP : Stack Pointer의 기준점(바닥)을 저장. 밑에는 return 값이 존재.<br>
- EIP : 다음 명령어의 위치를 저장

<h3>인덱스 레지스터</h3>
- ESI : 출발지 주소를 저장<br>
- EDI : 목적지 주소를 저장

<h3>메모리 주소와 접근</h3>

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

<h3>메모리 크기 지정</h3>

```c
mov byte ptr ds: [402000], al
mov byte ptr ds: [402000], al
mov byte ptr ds: [402000], al
```
Qword   = 8 Byte<br>
Dword   = 4 Byte<br>
Word    = 2 Byte<br>
Byte    = 1 Byte

CS      : 함수나 제어문 같은 명령어들이 저장되는 코드 세그먼트<br>
DS      : 주로 전역, 정적 변수 데이터가 들어있는 데이터 세그먼트<br>
SS      : 스택의 주소<br>
ES      : 추가 세그먼트<br>
FS, GS  : 추가 세그먼트

<h3>Little endian, Big endian</h3>
메모리에 데이터를 어떻게 저장하는가의 차이.

1. Little endian  : 작은 단위가 앞에 나오는 것
2. Big endian     : 큰 단위가 앞에 나오는 것

------------------------------------------------------------------------
출처 : https://peemangit.tistory.com/40

<h3>move 명령어</h3>

*mov*
- source operand를 destination operand에 복사해 넣는다.
- 피연산자들의 크기가 일치해야한다.

```c
mov reg, 값
mov reg, reg
mov reg, mem
mov mem, reg
```

*movzx(move with zero extention)*
- 데이터를 복사한 후 나머지 비트를 0으로 채운다.
- 부호가 없는 정수에만 사용된다.(unsigned)
- destination operand는 반드시 레지스터이어야 한다.

*movsx(mov with sign extention)*
- source operand를 destination operand에 복사해 넣은 후 나머지 비트 값을 부호 확장한다.
- 부호 있는 정수에만 사용된다.

*movs(mov data from string to string)*
- ESI가 가리키는 주소에 있는 데이터를 EDI가 가리키는 주소로 복사.
- 방향 플레그(DF)가 1이면 ESI와 EDI는 감소, 0이면 증가.

---------------------------------------------------------------------------
<h3>산술 논리 연산</h3>

*add*
- source operand를 동일한 크기에 destination operand에 더한다.
- 결과값은 destination operand에 저장.

*sub*
- destination operand에서 source operand를 뺀다.

*mul*
- 부호가 없는 al, ax, eax에 8, 16, 32 비트 연산자를 곱하는 명령어

*imul*
- 부호가 있는 곱셈(signed)
- 음수 부호 유지를 위한 상위 bit의 set은 overflow로 취급하지 않는다.

*div*
- 부호가 없는 al, ax, eax에 8, 16, 32 비트 연산자를 나누는 명령어
- 결과가 저장될 레지스터 크기보다 크면 integer overflow 오류가 발생한다.

*idiv*
- 부호가 있는 정수 나눗셈 수행.
- 나눗셈 수행 전에 cbw(2byte), cwd(4byte), cdq(8byte)로 부호 비트를 확장한다.

*inc*
- operand에 1을 증가.

*dec*
- operand에 1을 감소.

*and*
- 두 개의 operand에 매칭되는 비트 사이에 부울 and 연산 후 결과값을 destination operand에 저장.<br>
- 선택된 bit를 clear하고 나머지를 유지할 때 사용할 수 있다.

*or*
- 두 개의 operand에 매칭되는 비트 사이에 or 연산 후 결과를 destination operand에 저장.<br>
- 선택된 bit를 set하고 다른 것을 유지할 때 사용할 수 있다.

*xor*
- 두 개의 operand에 매칭되는 비트 사이에 배타적 or 연산. (같은 값 0, 다른 값 1)

*shl(shift left)*
- 피연산자 비트를 왼쪽으로 이동시키며 곱셈과 관련된 연산 수행.
- ex) shl d1, 2: shift left 연산을 2번 수행(기존 값(10)에 *2*2=40)

*shr(shift right)*
- 피연산자 비트를 오른쪽으로 이동시키며 나눗셈과 관련된 연산 수행.

*lea(load effective address)*
- 두 번째 operand 주소를 계산하고 첫 번째 operand에 저장한다.
- []연산자를 제외하고 두 번째 operand로 expression이 허용 X.

*scas(scan string)*
- al/ax/eax에 저장되어 있는 값과 EDI가 가르키는 곳의 값을 비교.
- 0개에서 2개까지 피연산자를 쓸 수 있다.
- byte, word, double word를 비교할 수 있다.<br><br>

- scasb : eax안에 있는 al과 EDI 안에 있는 1byte 값을 비교한다.
- scasw : eax안에 있는 ax와 EDI 안에 있는 2byte 값을 비교한다.

*stos(store string)*
- al/ax/eax에 저장되어 있는 값을 EDI가 가르키는 곳에 저장한다.<br><br>
- stosb : al의 내용을 EDI가 가르키는 offset위치의 메모리에 저장(1byte)

*rep(repeat)*
- movs, scac, stos 등 여러 명령어에 접두사 형식으로 사용되며 ecx 레지스터에 저장된 값 만큼 해당 명령어를 반복해서 실행한다.
- ex) rep movsb

-------------------------------------------------------------------------
<h3>Stack</h3>
- 프로그램 실행 시 사용되는 메모리 중 하나
- Thread 단위로 생성된다.
- 시작 위치는 Random.

*Stack의 용도*
1. 지역변수를 저장한다. (주목적)
2. 함수 매개변수를 전달한다.
3. 함수 호출관련 정보를 알려준다.
4. OS에서 필요할 경우 사용한다.
5. 임시 데이터 백업에 이용한다.

![image](https://user-images.githubusercontent.com/62539341/79862039-652ccf00-8410-11ea-8735-0ac9d5433e8f.png)

- 인텔에서는 full stack을 사용한다.

![image](https://user-images.githubusercontent.com/62539341/79862120-8e4d5f80-8410-11ea-8a97-50f28cdc0e60.png)

- 인텔에서는 descending stack을 사용한다.

*PUSH*
- 먼저 ESP를 감소, 16비트나 32비트 출발지 피연산자를 스텍에 복사한다.

![image](https://user-images.githubusercontent.com/62539341/79862378-f8660480-8410-11ea-9096-36e11e0cecd6.png)

- PUSH의 용도 : 지역변수를 위한 공간할당, 함수 인자 전달, 단순 백업

*POP*
- ESP가 가리키는 곳의 값을 목적지 피연산자에 저장 후 ESP값을 증가시킨다.

![image](https://user-images.githubusercontent.com/62539341/79862750-87731c80-8411-11ea-9668-c03afa21ae37.png)

--------------------------------------------------------------------------
<h3>EIP 값을 변경하는 명령어</h3>

*jmp*
- EIP 값을 변경하기 전에 스택에 백업을 하지 않는다.
- 조건 분기가 가능한 명령어 형태가 존재.(jz, jnz, ja, jb, jg 등)

*call*
- EIP 값을 변경하기 전에 스택에 백업을 해둔다.
- 조건 분기가 가능한 명령어 형태가 존재하지 않는다.

*retn*
- 의미상 POP EIP와 동일

![image](https://user-images.githubusercontent.com/62539341/79863006-f8b2cf80-8411-11ea-9169-bae7f6cafeac.png)
