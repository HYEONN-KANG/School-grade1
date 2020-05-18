��ó : https://www.inflearn.com/course/%EC%96%B4%EC%85%88%EB%B8%94%EB%A6%AC%EC%96%B4-%EB%B0%B0%EC%9A%B0%EA%B8%B0/lecture/1748

�������� ����� 1:1�� �������� �ڵ�ȭ��, �ϵ����� ���� ������ ���

�������� Opcode�� Operand�� ������.

```c
mov eax, 1 
```
Opcode�� mov, Operand�� eax, 1 �κ��̴�.

�ϵ�����  CPU, RAM, �ϵ��ũ ���� �ִ�. ������ CPU���� �Ͼ�µ� CPU���� ��������� Register��� �Ѵ�. �������Ͱ� �б�, ������ �� �ӵ��� ���� ���� ��������̴�. ������ �뷮�� �ſ� �۱� ������ ���α׷��� ������ RAM�� �ִ�. �����͸� ���ų� �������� RAM����, ���������� ������ �� ���� �������Ϳ��� ������ �� �� ����Ѵ�.

----------------------------------------------------------------------------
<h3>���� ��������</h3>
- EAX : ���꿡 ���, �Լ��� ���� ���� ����ȴ�.<br>
- EBX : ���� ���������� ���.<br>
- ECX : loop���� count ����<br>
- EDX : EAX ����

<h3>������ ��������</h3>
- ESP : Stack Pointer�� ���� �ֱٿ� ����� ������ �ּҸ� ����.<br>
      Stack�� ���� ������ ESP ���� 1�� ����. Stack�� ����'�ּ�'�� ����.<br>
- EBP : Stack Pointer�� ������(�ٴ�)�� ����. �ؿ��� return ���� ����.<br>
- EIP : ���� ��ɾ��� ��ġ�� ����

<h3>�ε��� ��������</h3>
- ESI : ����� �ּҸ� ����<br>
- EDI : ������ �ּҸ� ����

<h3>�޸� �ּҿ� ����</h3>

```c
mov [402000], al
mov byte ptr ds: [402000], al
```
al�� �ִ� ���� �ּҰ� 402000�� �޸𸮿� �־��.

```c
mov cl, [402000]
mov cl, byte ptr ds: [402000]
```
402000�� �ִ� �����͸� cl�� �־��.

<h3>�޸� ũ�� ����</h3>

```c
mov byte ptr ds: [402000], al
mov byte ptr ds: [402000], al
mov byte ptr ds: [402000], al
```
Qword   = 8 Byte<br>
Dword   = 4 Byte<br>
Word    = 2 Byte<br>
Byte    = 1 Byte

CS      : �Լ��� ��� ���� ��ɾ���� ����Ǵ� �ڵ� ���׸�Ʈ<br>
DS      : �ַ� ����, ���� ���� �����Ͱ� ����ִ� ������ ���׸�Ʈ<br>
SS      : ������ �ּ�<br>
ES      : �߰� ���׸�Ʈ<br>
FS, GS  : �߰� ���׸�Ʈ

<h3>Little endian, Big endian</h3>
�޸𸮿� �����͸� ��� �����ϴ°��� ����.

1. Little endian  : ���� ������ �տ� ������ ��
2. Big endian     : ū ������ �տ� ������ ��

------------------------------------------------------------------------
��ó : https://peemangit.tistory.com/40

<h3>move ��ɾ�</h3>

*mov*
- source operand�� destination operand�� ������ �ִ´�.
- �ǿ����ڵ��� ũ�Ⱑ ��ġ�ؾ��Ѵ�.

```c
mov reg, ��
mov reg, reg
mov reg, mem
mov mem, reg
```

*movzx(move with zero extention)*
- �����͸� ������ �� ������ ��Ʈ�� 0���� ä���.
- ��ȣ�� ���� �������� ���ȴ�.(unsigned)
- destination operand�� �ݵ�� ���������̾�� �Ѵ�.

*movsx(mov with sign extention)*
- source operand�� destination operand�� ������ ���� �� ������ ��Ʈ ���� ��ȣ Ȯ���Ѵ�.
- ��ȣ �ִ� �������� ���ȴ�.

*movs(mov data from string to string)*
- ESI�� ����Ű�� �ּҿ� �ִ� �����͸� EDI�� ����Ű�� �ּҷ� ����.
- ���� �÷���(DF)�� 1�̸� ESI�� EDI�� ����, 0�̸� ����.

---------------------------------------------------------------------------
<h3>��� �� ����</h3>

*add*
- source operand�� ������ ũ�⿡ destination operand�� ���Ѵ�.
- ������� destination operand�� ����.

*sub*
- destination operand���� source operand�� ����.

*mul*
- ��ȣ�� ���� al, ax, eax�� 8, 16, 32 ��Ʈ �����ڸ� ���ϴ� ��ɾ�

*imul*
- ��ȣ�� �ִ� ����(signed)
- ���� ��ȣ ������ ���� ���� bit�� set�� overflow�� ������� �ʴ´�.

*div*
- ��ȣ�� ���� al, ax, eax�� 8, 16, 32 ��Ʈ �����ڸ� ������ ��ɾ�
- ����� ����� �������� ũ�⺸�� ũ�� integer overflow ������ �߻��Ѵ�.

*idiv*
- ��ȣ�� �ִ� ���� ������ ����.
- ������ ���� ���� cbw(2byte), cwd(4byte), cdq(8byte)�� ��ȣ ��Ʈ�� Ȯ���Ѵ�.

*inc*
- operand�� 1�� ����.

*dec*
- operand�� 1�� ����.

*and*
- �� ���� operand�� ��Ī�Ǵ� ��Ʈ ���̿� �ο� and ���� �� ������� destination operand�� ����.<br>
- ���õ� bit�� clear�ϰ� �������� ������ �� ����� �� �ִ�.

*or*
- �� ���� operand�� ��Ī�Ǵ� ��Ʈ ���̿� or ���� �� ����� destination operand�� ����.<br>
- ���õ� bit�� set�ϰ� �ٸ� ���� ������ �� ����� �� �ִ�.

*xor*
- �� ���� operand�� ��Ī�Ǵ� ��Ʈ ���̿� ��Ÿ�� or ����. (���� �� 0, �ٸ� �� 1)

*shl(shift left)*
- �ǿ����� ��Ʈ�� �������� �̵���Ű�� ������ ���õ� ���� ����.
- ex) shl d1, 2: shift left ������ 2�� ����(���� ��(10)�� *2*2=40)

*shr(shift right)*
- �ǿ����� ��Ʈ�� ���������� �̵���Ű�� �������� ���õ� ���� ����.

*lea(load effective address)*
- �� ��° operand �ּҸ� ����ϰ� ù ��° operand�� �����Ѵ�.
- []�����ڸ� �����ϰ� �� ��° operand�� expression�� ��� X.

*scas(scan string)*
- al/ax/eax�� ����Ǿ� �ִ� ���� EDI�� ����Ű�� ���� ���� ��.
- 0������ 2������ �ǿ����ڸ� �� �� �ִ�.
- byte, word, double word�� ���� �� �ִ�.<br><br>

- scasb : eax�ȿ� �ִ� al�� EDI �ȿ� �ִ� 1byte ���� ���Ѵ�.
- scasw : eax�ȿ� �ִ� ax�� EDI �ȿ� �ִ� 2byte ���� ���Ѵ�.

*stos(store string)*
- al/ax/eax�� ����Ǿ� �ִ� ���� EDI�� ����Ű�� ���� �����Ѵ�.<br><br>
- stosb : al�� ������ EDI�� ����Ű�� offset��ġ�� �޸𸮿� ����(1byte)

*rep(repeat)*
- movs, scac, stos �� ���� ��ɾ ���λ� �������� ���Ǹ� ecx �������Ϳ� ����� �� ��ŭ �ش� ��ɾ �ݺ��ؼ� �����Ѵ�.
- ex) rep movsb

-------------------------------------------------------------------------
<h3>Stack</h3>
- ���α׷� ���� �� ���Ǵ� �޸� �� �ϳ�
- Thread ������ �����ȴ�.
- ���� ��ġ�� Random.

*Stack�� �뵵*
1. ���������� �����Ѵ�. (�ָ���)
2. �Լ� �Ű������� �����Ѵ�.
3. �Լ� ȣ����� ������ �˷��ش�.
4. OS���� �ʿ��� ��� ����Ѵ�.
5. �ӽ� ������ ����� �̿��Ѵ�.

![image](https://user-images.githubusercontent.com/62539341/79862039-652ccf00-8410-11ea-8735-0ac9d5433e8f.png)

- ���ڿ����� full stack�� ����Ѵ�.

![image](https://user-images.githubusercontent.com/62539341/79862120-8e4d5f80-8410-11ea-8a97-50f28cdc0e60.png)

- ���ڿ����� descending stack�� ����Ѵ�.

*PUSH*
- ���� ESP�� ����, 16��Ʈ�� 32��Ʈ ����� �ǿ����ڸ� ���ؿ� �����Ѵ�.

![image](https://user-images.githubusercontent.com/62539341/79862378-f8660480-8410-11ea-9096-36e11e0cecd6.png)

- PUSH�� �뵵 : ���������� ���� �����Ҵ�, �Լ� ���� ����, �ܼ� ���

*POP*
- ESP�� ����Ű�� ���� ���� ������ �ǿ����ڿ� ���� �� ESP���� ������Ų��.

![image](https://user-images.githubusercontent.com/62539341/79862750-87731c80-8411-11ea-9668-c03afa21ae37.png)

--------------------------------------------------------------------------
<h3>EIP ���� �����ϴ� ��ɾ�</h3>

*jmp*
- EIP ���� �����ϱ� ���� ���ÿ� ����� ���� �ʴ´�.
- ���� �бⰡ ������ ��ɾ� ���°� ����.(jz, jnz, ja, jb, jg ��)

*call*
- EIP ���� �����ϱ� ���� ���ÿ� ����� �صд�.
- ���� �бⰡ ������ ��ɾ� ���°� �������� �ʴ´�.

*retn*
- �ǹ̻� POP EIP�� ����

![image](https://user-images.githubusercontent.com/62539341/79863006-f8b2cf80-8411-11ea-9169-bae7f6cafeac.png)