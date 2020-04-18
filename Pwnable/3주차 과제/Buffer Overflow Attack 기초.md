출처 : https://drive.google.com/file/d/1nvRxum8J1q5pqYLTGrdQpYDY2PSps1HS/view

<h3>2.8086 Memory Architecture</h3>

![image](https://user-images.githubusercontent.com/62539341/79639911-82239100-81c9-11ea-8ac4-ed6de0f3de3e.png)

시스템이 초기화 되기 시작하면 시스템은 커널을 메모리에 넣고 Available Space를 확인한다. 시스템은 기본적인 명령어들을 커널에서 찾기 때문에 커널은 반드시 저 위치에 있어야 한다.

![image](https://user-images.githubusercontent.com/62539341/79640154-f874c300-81ca-11ea-990b-35148ab32933.png)


운영체제는 하나의 프로세스를 실행시키면 segment라는 단위로 묶어서 Available Space에 저장시킨다. segment는 하나의 프로세스를 묶은 것으로 실행 시점에 실제 메모리의 어느 위치에 저장될 지가 결정된다.<br>
segment는 code segment, data segment, stack segment로 구성되어 있다.

code segment에는 명령어(instruction)이 있다. instruction들은 메모리 상의 특정 위치에 있는 명령을 지정해 주어야 한다. 그런데 segment는 자신이 현재 메모리 상에 어느 위치에 저장될 지 컴파일 과정에서는 알 수 없기 때문에 logical address를 사용한다. logical address는 실제 메모리 상의 주소가 매핑되어있다. 즉 segment는 segment selector에 의해서 자신의 시작 위치(offset)를 찾을 수 있고 자신의 시작 위치로부터의 위치(logical address)에 있는 명령을 수행할 지를 결정. 따라서 실제 메모리 주소 physical address는 offset + logical address라고 할 수 있다.<br>
예를 들어 segment가 실제로 위치하고 있는 메모리상의 주소를 0x80010000이라고 가정하면, code segment 안에 들어있는 하나의 instruction IS 1를 가리키는 주소는 0x00000100 이다. 이것은 logical address이고 이 instruction의 실제 메모리 상의 주소는 segment offset인 0x80010000과 segment안의 주소 0x00000100을 더한 0x80010100이 된다.

data segment에는 데이터(전역변수)가 들어간다. data segment는 다시 네 개의 data segment로 나뉘어지는데, 각각 현재 모듈의 data structure, 상위 레벨로부터 받아들이는 데이터 모듈, 동적 생성 데이터, 다른 프로그램과 공유하는 공유 데이터 부분이다.

stack segment는 현재 수행되고 있는 handler, task, program이 저장하는 데이터 영역. 우리가 사용하는 버퍼가 이 곳에 자리잡는다. 또, 프로그램이 사용하는 multiple 스텍을 생성할 수 있고 각 스텍들간의 switch가 가능하다. 지역변수들이 위치한다. 스텍은 stack pointer라고 하는 레지스터가 스텍의 맨 꼭대기를 가리킨다. 스택에 데이터를 저정하고 읽어 들이는 과정은 PUSH와 POP instruction이 한다.

---------------------------------------------------------------------------
<h3>3.8086 CPU 레지스터 구조</h3>
레지스터의 종류

1. 범용 레지스터(General-Purpose register)<br>
논리 연산, 수리 연산에 사용되는 피연산자, 주소를 계산하는데 사용되는 피연산자, 그리고 메모리 포인터가 저장된다.<br>
2. 세그먼트 레지스터(segment register)<br>
code segment, data segment, stack segment를 가리키는 주소가 들어있다.<br>
3. 플래그 레지스터(Program status and control register)<br>
프로그램의 현재 상태나 조건 등을 검사하는데 사용되는 플래그들이 들어있다.<br>
4. 인스트럭션 포인터(instruction pointer)<br>
다음 수행해야 하는 명령(instruction)이 있는 메모리 상의 주소가 들어있다.

1. 범용 레지스터(General-Purpose register)

![image](https://user-images.githubusercontent.com/62539341/79640985-ca45b200-81cf-11ea-9548-672b0f14ca5e.png)

EAX - 피연산자와 연산 결과의 저장소
EBX - DS segment안의 데이터를 가리키는 포인터
ECX - 문자열 처리나 루프를 위한 카운터
EDX - I/O 포인터
ESI - DS 레지스터가 가리키는 data segment 내의 어느 데이터를 가리키고 있는 포인터. 문자열 처리에서 source를 가리킴.
EDI - ES 레지스터가 가리키고 있는 data segment 내의 어느 데이터를 가리키고 있는 포인터. 문자열 처리에서 destination을 가리킴.
ESP - SS 레지스터가 가리키는 stack segment의 맨 꼭대기를 가리키는 포인터
EBP - SS 레지스터가 가리키는 스텍상의 한 데이터를 가리키는 포인터

2. 세그먼트 레지스터(segment register)

![image](https://user-images.githubusercontent.com/62539341/79641158-b64e8000-81d0-11ea-923b-23bab3910659.png)

세그먼트 레지스터는 프로세스의 특정 세그먼트를 가리키는 포인터 역할을 한다.
CS 레지스터는 code segment를, DS, ES, FS, GS 레지스터는 data segment를, SS 레지스터는 stack segment를 가리킨다. 이렇게 세그먼트 레지스터가 가리키는 위치를 바탕으로 우리는 원하는 segment안의 특정 데이터, 명령어를 정확하게 끄집어 낼 수가 있게 된다.

3. 플래그 레지스터(Program status and control register)

![image](https://user-images.githubusercontent.com/62539341/79641398-4640f980-81d2-11ea-844b-a837cfcf16e7.png)

컨트롤 플래그 레지스터는 상태 플래그, 컨트롤 플래그, 시스템 플래그들의 집합이다. 시스템이 리셋되어 초기화 되면 이 레지스터는 0x00000002의 값을 가진다. 그리고 1, 3, 5, 15, 22~31번 비트는 예약되어 있어 조작할 수 없게 되어있다.

<각 플래그들의 역할>

1. Status flags <br>
CF - carry flag. 연산을 수행하면서 carry 혹은 borrow가 발생하면 1이 된다. Carry와 borrow는 덧셈 연산시 bit bound를 넘어가거나 뺄셈을 하는데 빌려오는 경우를 말한다.<br>
PF - Parity flag. 연산 결과 최하위 바이트의 값이 1이 짝수일 경우에 1이 된다. 패리티 체크를 하는데 사용.<br>
AF - Adjust flag. 연산 결과 carry나 borrow가 3bit 이상 발생할 경우 1이 된다.<br>
ZF - Zero flag. 결과가 zero임을 가리킴. if문 같은 조건문이 만족될 경우 set<br>
SF - Sign flag. 연산 결과 최상위 비트의 값과 같다. Signed 변수의 경우 양수이면 0, 음수이면 1이 된다.<br>
OF - Overflow flg. 정수형 결과값이 너무 큰 양수이거나 너무 작은 음수여서 피연산자의 데이터 타입에 모두 들어가지 않을 경우 1이 된다.

2. System flags<br>
IF - Interrupt enable flag. 프로세서에게 mask한 interrupt에 응답할 수 있게 하려면 1을 준다.<br>
TF - Trap flag. 디버깅을 할 때 single-step을 가능하게 하려면 1을 준다.<br>
IOPL - I/O privilege level field. 현재 수행중인 프로세스 혹은 task의 권한 레벨을 가리킨다. 현재 수행중인 프로세스의 권하능ㄹ 가리키는 CPL이 I/O address 영역에 접근하기 위해선 I/O privileg level보다 작거나 같아야 한다.<br>
NT - Nested task flag. Interrupt의 chain을 제어한다. 1이 되면 이전 실행 task와 현재 task가 연결되어 있음을 나타낸다.<br>
RF - Resume flag. Exception debug 하기 위해 프로세서의 응답을 제어한다.<br>
VM - Virtual-8086 mode flag. Virtual-8086 모드를 사용하려면 1을 준다.<br>
AC - Alignment check flag. 이 비트와 CR0 레지스터의 AM 비트가 set되어 있으면 메모리 레퍼런스의 alignment checking이 가능하다.<br>
VIF - Virtual interrupt flag. IF flag의 가상 이미지이다. VIP vlag와 결합시켜 사용한다.<br>
VIP - Virtual interrupt pending flag. 인터럽트가 pending(경쟁 상태) 되었음을 가리킨다.<br>
ID - Identification flag. CPUID instruction을 지원하는 CPU인지를 나타낸다.

3. Instructon Pointer<br>
Instruction pointer 레지스터는 다음 실행할 명령어가 있는 현재 code segment의 offset 값을 가진다. 이것은 하나의 명령어 범위에서 선형 명령 집합의 다음 위치를 가리킬 수 있다. 뿐만 아니라 JMP, Jcc, CALL, RET와 IRET instruction이 있는 주소값을 가진다. 

---------------------------------------------------------------------------
<h3>4.프로그램 구동 시 Segment에서는 어떤 일이?</h3>

```c
void function(int a, int b, int c){
    char buffer1[15];
    char buffer2[10];
}

void main(){
    function(1, 2, 3);
}
```
