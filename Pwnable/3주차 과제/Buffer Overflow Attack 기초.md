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
Instruction pointer 레지스터는 다음 실행할 명령어가 있는 현재 code segment의 offset 값을 가진다. 이것은 하나의 명령어 범위에서 선형 명령 집합의 다음 위치를 가리킬 수 있다. 뿐만 아니라 JMP, Jcc, CALL, RET와 IRET instruction이 있는 주소값을 가진다. EIP 레지스터는 소프트웨어에 의해 바로 엑세스할 수 없고 control-transfer instruction(JMP, Jcc, CALL, RET)이나 interrupt와 exception에 의해서 제어된다. EIP 레지스터를 읽을 수 있는 방법은 CALL instruction을 수행하고 나서 프로시저 스텍(procedure stack)으로부터 리턴하는 instruction의 address를 읽는 것이다. 프로시저 스텍의 return instruction pointer의 값을 수정하고 return instruction(RET, IRET)을 수행해서 EIP 레지스터의 값을 간접적으로 지정해 줄 수 있다.

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

![image](https://user-images.githubusercontent.com/62539341/79680060-7b872f00-8246-11ea-828a-060771d821ee.png)


EIP는 main()함수의 시작점, ESP는 스텍의 맨 꼭대기를 가리킨다. ESP가 스텍의 맨 꼭대기를 가리키고 있는 이유는 프로그램이 수행되면서 수많은 PUSH와 POP을 할 것이기 때문에 이 지점에 다 PUSH를 해라, 이 지점에 있는 데이터를 POP해라는 의미이다. <br>
ebp를 저장하는 이유는 이전에 수행하던 함수의 데이터를 보존하기 위해서이다. 이것을 base pointer라고 부른다. 그래서 함수가 시작될 때 이렇게 stack pointer와 base pointer를 새로 지정하는데 이 과정을 함수 프롤로그 과정이라고 한다.


<h4>push %ebp</h4>
이전 함수의 base pointer를 저장하면 stack pointer는 4바이트 아래인 0xbffffa78을 가리키게 된다.

<h4>mov %esp, %ebp</h4>
ESP 값을 EBP에 복사함으로써 함수의 basepointer와 stack pointer가 같은 지점을 가리킨다.

<h4>sub $0x8, %esp</h4>
ESP에서 8을 빼는 명령. 따라서 ESP는 8바이트 아래 지점을 가리키게 되고 스텍에 8바이트의 공간이 생기게 된다. 이것을 스텍이 8바이트 확장되었다고 말한다. 이 명령이 수행되고 나면 ESP에는 0xbffffa70이 들어가게 된다.

<h4>and $0xfffffff0, %esp</h4>
ESP와 11111111 11111111 11111111 11110000과 AND 연산을 한다. 이것은 ESP의 주소값의 맨 뒤 4bit를 0으로 만들기 위함이다. 별 의미없는 명령이다.

<h4>mov $0x0, %eax</h4>
EAX 레지스터에 0을 넣고

<h4>sub %eax, %esp</h4>
ESP에 들어 있는 값에서 EAX에 들어 있는 값을 뺀다. 이것은 stack pointer를 EAX만큼 확장시키려는 것이지만 0이 들어있어서 의미없다.

<h4>sub $0x4, %esp</h4>
스텍을 4바이트 확장하였다. 따라서 ESP에 들어있는 값은 0xbffffa6c가 된다.


다음 수행할 명령은
<h4>push $0x03</h4>
<h4>push $0x02</h4>
<h4>push $0x01</h4>
이것은 function(1, 2, 3)을 수행하기 위해 인자값 1, 2, 3을 차례로 넣어준다.

<h4>call 0x80482f4</h4>
0x80482f4에 있는 명령을 수행하라는 것. 이곳은 function 함수가 있는 곳이다.<br>
call은 함수를 호출할 때 사용하는 명령으로 함수가 끝나면 다시 다음 명령을 계속 수행할 수 있도록 이 후 명령이 있는 주소를 스텍에 넣은 다음 EIP에 함수의 시작 지점의 주소를 넣는다. "add $x10, %esp" 명령이 있는 주소이다.<br>
따라서 함수 수행이 끝나고 나면 이제 어디에 있는 명령을 수행할지 스택에서 POP하여 알 수 있게 되는 것이다. 이것이 바로 buffer overflow에서 가장 중요한 return address 이다.<br>
이제 EIP에는 function 함수가 있는 0x80482f4 주소값이 들어간다.


<h4>push %ebp</h4>
<h4>mov %esp, %ebp</h4>
function() 함수도 마찬가지로 함수 프롤로그가 수행된다. main() 함수에서 사용하던 base pointer가 저장되고 stack pointer를 function()함수의 base pointer로 삼는다.

<h4>sub $0x28, %esp</h4>
이것은 스텍을 40바이트 확장한다. 40바이트가 된 이유는 functino() 함수에서 지역 변수로 buffer1[15]와 buffer2[10]을 선언했기 때문이다. buffer1[15]는 총 15바이트가 필요하지만 스텍은 word (4byte)단위로 자라기 때문에 16바이트를 할당, buffer2[10]은 12 바이트를 할당한다. <br>
이렇게 만들어진 버퍼에는 우리가 필요한 데이터를 쓸 수 있게 된다.
<h4>mov $0x41, [$esp-4]</h4>
<h4>mov $0x42, [$esp-8]</h4>
이런 형식으로 ESP를 기준으로 스텍의 특정 지점에 데이터를 복사해 넣는 방식으로 동작한다.

![image](https://user-images.githubusercontent.com/62539341/79680110-fd775800-8246-11ea-8c2c-7d4263b208ae.png)

이제 **leave** instruction을 수행했다. leave instruction은 함수 프롤로그 작업을 되돌리는 일을 한다. <br>
push %ebp<br>
mov %esp, %ebp<br>
이 두개를 되돌리는 것은<br>
mov %ebp, %esp<br>
pop %ebp<br>

stack pointer를 이전의 base pointer로 잡아서 function() 함수에서 확장했던 스텍 공간을 없애버리고 PUSH해서 저장해 두었던 이전 함수 즉, main()함수의 base pointer를 복원시킨다.

POP을 했으니까 stack pointer는 1 word 위로 올라간다.
그러면 이제 stack pointer는 return address가 있는 지점을 가리키고 있을 것이다.

ret instruction은 이전 함수로 return 하라는 의미. EIP 레지스터에서 return address를 POP하여 집어 넣는 역할을 한다.

<h4>ret</h4>
ret을 하면 return address는 POP되어 EIP에 저장되고 stack pointer는 1 word 위로 올라간다.

<h4>add $0x10, %esp</h4>
이것은 스텍을 16바이트 줄인다. 따라서 stack pointer는 0x804830c에 있는 명령을 수행하기 이전의 위치로 돌아가게 된다.

<h4>leave</h4>
<h4>ret</h4>
를 수행하게 되면 각 레지스터들의 값은 main()함수 프롤로그 작업을 되돌리고, main()함수 이전으로 돌아가게 된다. 이것은 아마 init_process()함수로 되돌아가게 될 것이다. 이 함수는 운영체제가 호출하는 함수.

---------------------------------------------------------------------------
<h3>5.Buffer overflow의 이해</h3>
버퍼(buffer)란?<br>
시스템이 연산 작업을 하는데 있어 필요한 데이터를 일시적으러 메모리 상에 저장하는데 그 저장공간을 말한다. 문자열을 처리할 것이라면 문자열 버퍼가 되고, 수열이라면 숫자형 데이터 배열이 된다. 대부분의 프로그램에서는 바로 이러한 버퍼를 스텍에다가 생성한다. 스텍은 함수 내에서 선언한 지역 변수가 저장되게 하고 함수가 끝나고 나면 반환된다. 이것은 malloc()과 같은 반영구적 (free()를 해 주지 않는 이상 이 영역을 계속 보존된다)인 데이터 저장 공간과는 다른 것이다.<br>
자 그러면 이제 buffer overflow가 어떤 원리로 동작하는지 살펴보자. buffer overflow는 미리 준비된 버퍼에 버퍼의 크기보다 더 큰 데이터를 쓸 때 발생한다. 40바이트 스텍이 준비되어 있는데 40바이트 보다 더 큰 데이터를 쓰면 버퍼가 넘치게 되고, 프로그램은 에러를 발생시키게 된다.<br>
여기서 시스템에게 첫 명령어를 간접적으로 내릴 수 있는 부분은 return address가 있는 위치이다. return address는 현재 함수의 base pointer 바로 위에 있으므로 그 위치는 변하지 않는다. 공격자가 base pointer를 직접적으로 변경하지 않는다면 정확히 해당 위치에 있는 값이 EIP에 들어가게 되어 있다. 따라서 buffer overflow 공격은 공격자가 메모리상의 임의의 위치에다 원하는 코드를 저장시켜 놓고 return address가 저장되어 있는 지점에 그 코드의 주소를 집어 넣어서 EIP에 공격자의 코드가 있는 곳의 주소가 들어가게 해서 공격을 하는 방법이다.

공격자는 버퍼가 넘칠 때, 즉 버퍼에 데이터를 쓸 때 원하는 코드를 넣을 수 있다. 물론 정확한 return address가 저장되는 곳을 찾아 return address도 정확하게 조작해 줘야 한다.

위에서 본 simple.c를 다시 한번 보자. function() 함수 안에서 정의한 buffer1[15]와 buffer2[10]의 버퍼가 있고 여기에는 40바이트의 버퍼가 할당되어 있다. 이 버퍼에 데이터를 쓰려한다고 생각해보자.

<h4>strcpy(buffer2, receive_from_client);</h4>
이 코드는 client로부터 수신한 데이터를 buffer2와 buffer1에 복사한다. strncpy() 같은 함수는 몇 바이트나 저장할지 지정해 주지만 strcpy 함수는 길이 체크를 해주지 않아서 receive_from_client 안의 데이터에서 NULL(\0)을 만날 때까지 복사한다.

![image](https://user-images.githubusercontent.com/62539341/79681050-7ed3e800-8251-11ea-9883-7dbbd0c005af.png)

클라이언트인 공격자가 전송하는 데이터는 receive_from_client에 저장되어 버퍼에 복사될 것이다. 그 데이터가 위와 같이 구성하여 전송한다고 가정하자.

![image](https://user-images.githubusercontent.com/62539341/79681129-5bf60380-8252-11ea-917c-a86233edb278.png)

strcpy가 호출되고 나면 스텍 안의 데이터는 아래와 같이 된다.

![image](https://user-images.githubusercontent.com/62539341/79681153-c7d86c00-8252-11ea-9574-b4e227d63c09.png)

<h4>Byte order</h4>
데이터가 저장되는 순서가 바뀐 이유는 바이트 정렬 방식이다. 두 가지의 바이트 순서(byte order)를 가지는데 big endian 방식과 little endian 방식이 있다. big endian 방식은 바이트 순서가 낮은 메모리 주소에서 높은 메모리 주소로 되고 little endian 방식은 높은 메모리 주소에서 낮은 메모리 주소로 되어 있다. IBM 370 컴퓨터와 RISC 기반의 컴퓨터들 그리고 모토로라의 마이크로프로세서는 big endian 방식으로 정렬, 그 외의 일반적인 IBM 호환 시스템, 알파 칩의 시스템들은 모두 little endian 방식을 사용한다.<br>
예를 들어 74E3FF59라는 16진수 값을 저장한다면 big endian에서는 낮은 메모리 영역부터 값을 채워 나가서 74E3FF59가 순서대로 저장된다. 반면 little endian에서는 59FFE374의 순서로 저장된다. little endian이 이렇게 저장순서를 뒤집어 놓는 이유는 수를 더하거나 빼는 셈을 할 때 낮은 메모리 주소 영역의 변화는 낮은 메모리 영역에 영향을 받고 높은 수의 변화는 높은 메모리 영역에 자리 잡게 하는 것이 little endian 방식의 논리이다. 높은 메모리에 있는 바이트가 변하면 수의 크기는 크게 변한다는 말이다. 하지만 한 바이트 내에서 bit의 순서는 big endian 방식으로 정렬된다.

이러한 byte order의 문제 때문에 공격 코드의 바이트를 정렬할 때에는 이러한 문제점을 고려해야 한다. 그러므로 little endian 시스템에 return address 값을 넣을 때는 바이트 순서를 뒤집어서 넣어주어야 한다.

위 그림에서, return address가 변경되었고 실제 명령이 들어있는 코드는 그 위에 있다. 이때까지는 아무 에러가 발생하지 않는다. 하지만 함수 실행이 끝나고 ret instruction을 만나면 return address가 있는 위치의 값을 EIP에 넣을 것이고 이제 EIP가 가리키는 곳의 명령을 수행할 것이다. 이 때 이 주소에 명령어가 들어 있지 않으면 프로그램은 오류가 발생한다. 또한 공격자는 자신이 만든 공격 코드를 실행하기를 원하므로 EIP에 return address 위에 있는 쉘 코드의 시작 주소를 넣고 싶어 한다. 어떻게 하면 이 주소를 알아낼 수 있을까?<br>
일단은 쉘 코드가 들어있는 지점의 정확한 주소를 찾았다고 생각하자. 

![image](https://user-images.githubusercontent.com/62539341/79681415-1d157d00-8255-11ea-857b-09d86e86f848.png)

위 그림에서 보여주는 공격 코드는 execv("/bin/sh", ...)이다. 즉 쉘을 뛰우는 것이다.<br>
쉘 코드의 시작 지점은 스텍상의 0xbffffa60이다. 따라서 함수가 리턴될 때 return address는 EIP에 들어가게 될 것이고 EIP는 0xbffffa60에 있는 명령을 수행할 것이므로 execve("/bin/sh", ...)를 수행한다. 이것이 buffer overflow를 이용한 공격방법이다.

<h4>만날 수 있는 문제점 한 가지</h4>
위 그림에서 공격 코드는 총 24byte 공간 안에 들어가 있다. 하지만 return address 위의 버퍼 공간이 쉘 코드를 넣을 만큼 충분하지 않다면 다른 공간을 찾아보는 수 밖에 없다. 위의 예에서 사용할 수 있는 공간ㅇㄴ 바로 90909090... 이 들어가 있는 function()함수가 사용한 스텍 공간이다. 이 공간은 40byte이고 추가로 main()함수의 base pointer가 저장되어 있는 4byte까지 무려 44byte라는 공간이 낭비되고 있다. 저 공간을 활용해보자. 그러면 문제는 return address가 EIP에 들어간 다음에 40byte의 스텍 공간의 명령을 수행할 수 있도록 해주어야 한다. return address에다 직접 40byte 공간의 주소를 적어주면 좋겠지만 해당 명령어가 있는 주소를 정확히 알아내는 것은 매우 어렵다. 따라서 간접적으로 그곳으로 명령 수행 지점을 변경해주는 방법을 사용한다.

![image](https://user-images.githubusercontent.com/62539341/79681576-500c4080-8256-11ea-9eaa-96f52a327080.png)

여기서 쉘 코드가 return address 아래에 있다. 즉 40 byte가 남아있던 그 공간이다. return address는 동일. 함수가 실행을 마치고 return할 때 return address가 스택에서 POP되어 EIP에 들어가고 나면 stack pointer는 1 word 위로 이동한다. 따라서 ESP는 return address가 있던 자리 위를 가리키게 된다. EIP는 0xbffffa60을 가리키고 있을 테니 그 곳에 있는 명령을 수행할 것이다. <그림 18>에서 쉘 코드가 있던 그 자리에는 다음과 같은 코드가 들어갔다. ESP가 가리키는 지점을 쉘 코드가 있는 위치를 가리키도록 48byte를 빼 주고 jmp %esp instruction을 수행하여 EIP에 ESP가 가리키는 지점의 주소를 넣도록 한다. 이 과정의 명령들을 쉘 코드로 변환했을 때 단 8byte만 있으면 충분하다. 다행히도 ESP 레지스터는 사용자가 직접 수정할 수 있는 레지스터이기 때문에 가능해진다.
