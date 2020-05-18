출처 : https://opentutorials.org/index.php/course/62

<h1>PHP 강의 요약</h1>
<h3>PHP란 무엇인가?</h3>

![](https://grm-project-template-bucket.s3.ap-northeast-2.amazonaws.com/lesson/les_ZVCZS_1533200934311/39b799024e850d787d9eb469f4e7a8c5f892fa1b4425b937dc242dc4757dfbc9.png)

Client는 Server에 요청, Server은 Client의 요청에 응답하는 역할을 한다.

우리는 흔히 네이버나 구글과 같은 사이트에 접속할 때, 웹 브라우저(Web Browser)을 사용한다. 이것을 *Web Client*라고도 부른다. 반대로 서버 쪽에는 *Web Server*가 존재한다.

*Web Client*의 종류에는 파이어폭스, 인터넷 익스플로어, 크롬, 사파리 등이 있다. *Web Server*의 종류에는 Apache, IIS, nginx 등이 있다.

예를 들어 도메인에 o2.org/topic.php 라고 적고 Enter 키를 누르면 Web  Server에서 확장자가 php라는 것을 확인하고, 이것을 PHP engine 으로 보낸다. PHP engine 으로부터 결과값을 Web Server가 돌려 받으면, 이것을 Web Client에 전달한다. 이렇게 Web Server와 PHP engine 사이의 통신 규약, 약속을 CGI(Common Gateway Interface) 라고 한다.

PHP(Hypertext Preprocessor)는 서버쪽에서 실행 되는 프로그래밍 언어

PHP의 장점
1. 웹에 최적화된 언어
2. 웹개발에 필요한 수많은 로직들이 함수의 형태로 미리 제공됨
3. 거의 모든 데이터베이스를 지원
4. 컴파일이 필요없는 interpreter방식의 언어
----------------------------------------------------------------------------
<h3>첫번째 PHP 애플리케이션</h3>

확장자명이 .php로 끝나는 파일을 생성해보자.

```php
<?php
echo "Hello world";
?>
```
echo는 뒤에 따라오는 데이터를 출력해주는 역할을 한다.

![image](https://user-images.githubusercontent.com/62539341/79328251-ae80a880-7f50-11ea-8804-e0eb62b9db17.png)<br><br>

```php
<html>
<body>
echo "Hello world";
<?php
echo "Hello world";
?>
</body>
</html>
```
echo 구문을 php 구문 사이에 있을 때와 body 태그 안에 있을 때 어떻게 결과가 달라질까? 

![image](https://user-images.githubusercontent.com/62539341/79328008-5a75c400-7f50-11ea-803a-0e6f1d36f3cf.png)


----------------------------------------------------------------------------
<h3>서버측 언어를 사용하는 이유</h3>
왜 우리는 server side script를 쓰는가?

Web Browser와 Web Server가 요청하고 응답하는 과정을 거치는 것이 초창기의 모습이었다. PHP나 Java, Python, perl 같은 서버쪽에서 실행되는 언어들은 없었다.

이 과정에서 Web Browser가 사용자에게 정보를 보여줄 때, 정보가 담겨있는 메세지가 HTML 이다. 그리고 HTML을 Server와 Client가 주고 받기 위한 규약이 HTTP이다.
URI, URL을 우리가 브라우저의 주소창에 입력하면 이에 해당되는 HTML 문서를 찾아서 클라이언트가 그 문서를 다운로드 할 수 있게 된다.

그런데 인터넷이 폭발적으로 성장하기 시작하면서 문제가 발생하기 시작했다.
웹사이트가 성장하면서 많은 사람들이 이용하게 되고 Web Server 만으로는 모든 일을 처리하기에 버거워졌다. 이때 고안한 것이 바로 CGI 이다.

Web Server와 PHP, Java, Python, perl 등의 프로그래밍 언어 사이에 서로 커뮤니케이션하기 위한 통신규약이 CGI이다.

PHP, Java, Python, perl 들은 Web Browser가 요청한 것이 HTML이 아니면 Web Server가 이 정보를 처리할 수 없고 해당 언어를 호출해서 사용자가 요청한 파일을 수행한다. 수행 결과를 Web Server를 매개로 Web Browser에게 마치 HTML인 것처럼 전송하는 것이다.

DB에 해당되는 것은 MySQL, ORACLE 등이 있는데 이것은 데이터를 저장하는 것에 특화되어 있다. 제목이나 본문같은 것의 데이터가 필요하면 프로그래밍언어가 DB에서 해당 데이터를 뽑아서 쓴다.
결론적으로 개발자가 PHP파일을 하나 만들면, 파일이나 구현정보, 데이터 등의 변경사항이 모두 적용되는 것이다.

----------------------------------------------------------------------------
<h3>숫자와 문자</h3>

```php
<?php
echo 1;
?>
```
echo 1 이라고 하면 1이라는 숫자를 화면에 출력한다
```php
<?php
var_dump(6);
?>
```
var_dump(데이터)는 데이터가 어떠한 형식인지를 보여준다.

![image](https://user-images.githubusercontent.com/62539341/79335610-43899e80-7f5d-11ea-89be-24b379d107b3.png)

```php
<?php
echo var_dump(1234);
echo var_dump("1234");
?>
```
php에서 문자열을 의미할 때는 "" 또는 ''로 표현한다. 

![image](https://user-images.githubusercontent.com/62539341/79336240-551f7600-7f5e-11ea-8a56-728ba0b8cdd8.png)

```php
<?php
echo "hello"." "."world";
?>
```
문자와 문자를 결합하고 싶다면 이렇게 php에서는 독특하게 +대신 .을 사용한다.

----------------------------------------------------------------------------
<h3>변수</h3>

```php
<html>
<body>
<?php
$a=1;
echo $a+1; #2
echo "<br />";
$a=2;
print $a+1; #3
?>
</body>
</html>
```
php에서는 변수를 선언할 때 '$변수'로 변수 앞에 $를 붙인다. 주석을 달 때는 #을 붙인다. 주석을 여러줄 달고 싶으면 /**/를 사용하면 된다.
```php
<html>
<body>
<?php
$first = "coding";
echo $first." everybody";
?>
</body>
</html>
```
이렇게 변수 안에는 숫자 뿐만 아니라 문자열도 들어갈 수 있다.<br><br>

우리는 변수를 왜 쓰는 걸까?
```php
<html>
<body>
<?php
echo 100+10;
echo '<br />';
echo (100+10)/10;
echo '<br />';
echo ((100+10)/10)-10;
echo '<br />';
echo (((100+10)/10)-10)*10;
echo '<br />';
?>
</body>
</html>
```
이 코드에서 100을 1000으로 바꿔야 한다면?
아주 번거롭고 귀찮다. 하지만 변수를 사용한다면 변수의 값만 변경해주면 되므로 편리하다.
```php
<html>
<body>
<?php
$a = 100;
$a = $a + 10;
print $a.'<br />';
$a = $a / 10;
print $a.'<br />';
$a = $a - 10;
print $a.'<br />';
$a = $a * 10 ;    
print $a.'<br />';
?>
</body>
</html>
```
```php
<html>
<body>
<?php
define('TITLE', 'PHP Tutorial');
echo TITLE;
define('TITLE', 'JAVA Tutorial');
?>
</body>
</html>
```
상수는 변수와 다르게 값을 변경할 수 없다. 첫번째 define에서 상수 TITLE에 PHP Tutorial 이라는 값을 저장했다. 그런데 그 밑에 다시 상수 TITLE에 다른 값을 넣으려 했으므로 여기서 error가 발생한다.

변수에 담긴 데이터 형을 검사하고 변경하기
```html
<html>
<body>
<?php
$a = 100;
echo gettype($a);
settype($a, 'double');
echo '<br />';
echo gettype($a);
?>
</body>
</html>
```
------------------------------------------------------------------
<h3>비교</h3>
프로그래밍에서 비교란 주어진 값들이 같은지, 다른지, 큰지, 작은지를 구분하는 것을 의미한다. 이 때 비교 연산자를 사용하는데 비교 연산자의 결과는 true나 false 중의 하나다. -> 데이터형이 Boolean !

1. "=="  : 좌항과 우항의 값이 같다면 true, 다르면 false
2. "!="  : ==와 결과가 정반대
3. ">"   : 좌항의 값이 우항의 값보다 크다면 true, 아니면 false
4. ">="  : 좌항의 값이 우항의 값보다 크거나 같다면 true, 아니면 false
5. "<"   : 좌항의 값이 우항의 값보다 작으면 true, 아니면 false
6. "<="  : 좌항의 값이 우항의 값보다 작거나 같다면 true, 아니면 false
7. "===" : 좌항과 우항의 값이 '정확하게' 같다면 true, 아니면 false

------------------------------------------------------------------
<h3>입출력 그리고 폼과 HTTP</h3>
프로그램은 입력 값을 가질 수 있다. 그리고 입력 값에 따라서 동작 방법이 달라지거나 입력된 값을 저장/삭제/출력 할 수 있다. 이번 시간에는 PHP의 문법에 대한 내용에서 잠깐 빠져나와서 PHP 에플리케이션이 데이터를 입력 받는 방법에 대해서 알아본다.

```php
<?php
echo $_GET['id'];
?>
```
처음 보는 $_GET[]이 등장하는 데 지금은 이것은 배열(array)이라는 것만 알고 넘어가자. 이 코드를 실행해보면

![image](https://user-images.githubusercontent.com/62539341/79403993-6783c900-7fcb-11ea-8f3a-d7b57df3971d.png)

이렇게 URL이 이상하다. 여기서 egoing을 k8805로 바꾸면 화면에 egoing 대신 k8805가 출력된다. 즉, 입력한 값에 따라 다른 출력값을 내보내는 User와 상호작용하는 애플리케이션이 되었다라는 것이다.<br>

URL에 있는 *localhost/입출력.php?id=egoing*을 한번 살펴보자.<br>
입출력.php라는 php 애플리케이션을 찾아내는 주소가 *localhost/입출력.php*라면 ?를 기준으로 뒤에 있는 *id=egoing* 은 주소가 가리키는 php 애플리케이션으로 전달되는 값이 들어오는 영역이다.<br>
여기서 다시, *id=egoing*을 살펴보면, =을 기준으로 앞에 있는 id 는 값에 대한 이름이고, = 뒤에 있는 egoing은 값이다.

조금 더 복잡하게, 이번엔 password까지 입력받아보자.
```php
<?php
echo $_GET['id'].','.$_GET['password'];
?>
```

![image](https://user-images.githubusercontent.com/62539341/79404830-bfbbca80-7fcd-11ea-8275-39a90efd9565.png)

 &은 값과 값을 구분하는 구분자이다.

그런데 매번 이렇게 사용자가 id나 password같은 정보를 URL에 적어서 전달하는 것은 매우 불편하다. 그래서 사용하는 것이 바로 폼(form)이다.

```html
<html>
<body>
    <form method="get" action="2.php">
        id :  <input type="text" name="id" />
        password :  <input type="text" name="password" />
        <input type="submit" />
    </form>
</body>
</html>
```

![image](https://user-images.githubusercontent.com/62539341/79405358-25f51d00-7fcf-11ea-974e-6185e38f25ad.png)

![image](https://user-images.githubusercontent.com/62539341/79406374-e11eb580-7fd1-11ea-85ac-450268f092ab.png)
<br><br>

이번엔 Get 방식과 Post 방식의 차이점에 대해 살펴보자. 지금까지 우리가 사용한 것은 Get 방식이다.

get 방식으로 데이터를 전송할 때 URL에 데이터를 포함시키는 것이 비해서 POST 방식으로 데이터를 전송할 때는 전송하는 데이터를 URL에 포함시키지 않고 전송 할 수 있다. 이러한 차이로 인해서 GET 방식은 정보에 대한 링크로 많이 사용되고, POST 방식은 사용자의 아이디나 비밀번호와 같은 데이터를 전송하는 방식으로 주로 사용한다.

```html
<html>
<body>
    <form method="POST" action="4.php">
        id :  <input type="text" name="id" />
        password :  <input type="text" name="password" />
        <input type="submit" />
    </form>
</body>
</html>
```
```php
<?php
echo $_POST['id'].','.$_POST['password'];
?>
```

![image](https://user-images.githubusercontent.com/62539341/79406460-1c20e900-7fd2-11ea-9121-14af3c0ae040.png)
이렇게 아까와는 다르게 URL에 데이터가 드러나지 않게 된다.

------------------------------------------------------------------
<h3>조건문</h3>

php에서 조건문의 기본 문법은 다른 프로그래밍 언어와 동일하다.
```php
<?php
if(조건){
    조건이 true라면 실행할 명령
}
?>
```

<br>
조건문을 응용해보자.

```html
<html>
<body>
    <form method="post" action="13.php">
        id :  <input type="text" name="id" />
        password : <input type="password" name="password" />
        <input type="submit" />
    </form>
</body>
</html>
```
```php
<?php
if($_POST['id'] === 'egoing'){
    if($_POST['password'] === '111111'){
        echo 'right';
    } else {
        echo 'password wrong';
    }   
} else {
    echo 'id wrong';
}
?>
?>
```
id와 password의 값을 입력받아 조건문을 이용하면, 값이 맞는지 확인할 수 있다. <br>조건문은 중첩 가능!

조건문에 사용할 수 있는 논리 연산자

1. and : and는 좌항과 우항이 모두 참(true)일 때 참이된다. &&를 사용해도 된다.
2. or  : or는 or의 좌우항 중에 하나라도 true라면 true가 되는 논리 연산자다.
3. !   : !(not)는 부정의 의미로, true를 false로 false를 true로 만든다.

------------------------------------------------------------------
<h3>반복문</h3>

반복문에서 가장 많이 사용되는 것은 while과 for가 있다.

while문의 문법은 다음과 같다.
```php
while(조건){
    코드
    코드
}
```
(예)
```php
<?php
# i의 값으로 0을 할당한다. 
$i = 0;
# 종료조건으로 i의 값이 5보다 작다면 true, 같거나 크다면 false
while($i < 5){
    echo 'coding everybody';
    # 반복문이 실행될 때마다 i의 값을 1씩 증가시킨다. 그 결과 i의 값이 5가 되면 종료조건이 false가 되면서 반복문이 종료된다.
    $i += 1;
}
?>
```

![image](https://user-images.githubusercontent.com/62539341/79409512-1e3a7600-7fd9-11ea-8ca4-231f1c0dd7cb.png)

for문의 문법은 다음과 같다.
```php
for(초기화; 반복 지속 여부; 반복 실행){
    코드;
}
```
(예)
```php
<?php
for($i = 0; $i < 10; $i++){
    echo 'coding everybody'.$i."<br />";
}
?>
```

![image](https://user-images.githubusercontent.com/62539341/79409578-43c77f80-7fd9-11ea-8a4a-7a68145c2f4a.png)<br><br>

반복작업을 중간에 중단시키고 싶다면 어떻게 해야할까?  break를 사용하면 된다. 아래의 예제는 위에서 살펴본 예제를 일부 변형한 것이다.
```php
<?php
for($i = 0; $i < 10; $i++){
    if($i === 5){
        break;
    }
    echo "coding everybody{$i}<br />";
}
?>
```

![image](https://user-images.githubusercontent.com/62539341/79409746-a6208000-7fd9-11ea-959a-62f087a11e02.png)

그럼 실행을 즉시 중단 하면서 반복은 지속돼게 하려면 어떻게 해야 할까? continue를 사용하면 된다.
```php
<?php
for($i = 0; $i < 10; $i++){
    if($i === 5){
        continue;
    }
    echo "coding everybody{$i}<br />";
}
?>
```

![image](https://user-images.githubusercontent.com/62539341/79409945-19c28d00-7fda-11ea-917c-7ef2edcd8722.png)

------------------------------------------------------------------
<h3>함수</h3>
함수(function)란 하나의 로직을 재실행 할 수 있도록 하는 것으로 코드의 재사용성을 높여준다. 그 이후부터 등장하는 함수나 객체지향과 같은 개념들은 그것 자체가 프로그래밍의 연산이나 논리에 직접적으로 관여하는 것이라기 보다는 방대한 양의 코드를 줄여주고, 유지보수를 쉽게하고, 버그가 발생할 여지를 줄여주는 것들이라고 할 수 있다. 

함수의 문법
```php
function 함수명( [인자...[,인자]] ){
   코드
   return 반환값;
}
```
(예)
```php
<?php
function get_member1(){
    return 'egoing';
}
 
 
function get_member2(){
    return 'k8805';
}
 
echo get_member1();
echo ',';
echo get_member2();
?>
```

![image](https://user-images.githubusercontent.com/62539341/79410253-d3216280-7fda-11ea-9e9a-3094800ce6f3.png)

<br>
이렇게 함수에 인자값을 받아서 실행시킬 수도 있다.

```php
<?php
function get_arguments($arg1, $arg2){
    return $arg1 + $arg2;
}
echo get_arguments(10, 20);
echo get_arguments(20, 30);
?>
```
------------------------------------------------------------------
<h3>배열</h3>
배열이란 연관된 데이터를 모아서 관리하기 위해서 사용하는 데이터 타입이다. 변수가 하나의 데이터를 임시로 저장하기 위한 것이라면 배열은 여러 개의 데이터를 저장하기 위한 것이라고 할 수 있다.

```php
<?php
$member = ['egoing', 'k8805', 'sorialgi'];
?>
```
```php
<?php
$member = array('egoing', 'k8805', 'sorialgi');
?>
```
하나의 변수에 3개의 데이터를 담았다. 각각의 데이터를 요소(element)라고 부른다. 

배열과 반복문을 사용하면 아주 편리하다!
```php
<?php
function get_members(){
    return ['egoing', 'k8805', 'sorialgi'];
}
 
$members = get_members();
 
for($i = 0; $i < count($members); $i++){
    echo ucfirst($members[$i]).'<br />';
}
 
?>
```
<br>
배열은 복수의 데이터를 효율적으로 관리, 전달하기 위한 목적으로 고안된 데이터 타입이다. 따라서 데이터의 추가/수정/삭제와 같은 일을 편리하게 할 수 있도록 돕는 다양한 기능을 가지고 있다. 몇가지 중요한 기능들만 살펴보자.

1. 배열의 크기
```php
<?php
$l = [1, 2, 3, 4, 5];
echo count($l);
?>
```
2. 배열의 추가
```php
<?php
$arr = ['a', 'b', 'c', 'd', 'e'];
array_push($arr, 'f');
var_dump($arr);
?>
```
복수의 데이터를 추가하려면
```php
<?php
$li = ['a', 'b', 'c', 'd', 'e'];
$li = array_merge($li, ['f','g']);
var_dump($li);
?>
```
다음은 배열의 시작점에 아이템을 추가하는 방법이다. 배열 li는 z, a, b, c, d, e가 됐다. insert의 첫번째 인자는 추가할 아이템의 위치를 의미하고 두번째 인자는 추가할 값을 의미한다.
```php
<?php
$li = ['a', 'b', 'c', 'd', 'e'];
array_unshift($li,'z');
var_dump($li);
?>
```
만약 두번째 인덱스 뒤에 대문자 B를 넣고 싶다면 아래와 같이한다.
```php
<?php
$li = ['a', 'b', 'c', 'd', 'e', 'z'];
array_splice($li, 2, 0, 'B');
var_dump($li);
?>
```
3. 배열의 제거

다음은 배열의 첫번째 요소를 제거하는 방법이다. 
```php
<?php
$li = ['a', 'b', 'c', 'd', 'e', 'z'];
array_shift($li);
var_dump($li);
?>
```
다음은 배열의 마지막 요소를 제거하는 방법이다. 
```php
<?php
$li = ['a', 'b', 'c', 'd', 'e', 'z'];
array_pop($li);
var_dump($li);
```
4. 배열의 정렬

다음은 정렬하는 방법이다. 결과는 a, b, c, d, e 다.
```php
<?php
$li = ['c','e','a','b','d'];
sort($li);
var_dump($li);
?>
```
역순으로 정렬하고 싶으면
```php
<?php
$li = ['c','e','a','b','d'];
rsort($li);
var_dump($li);
?>
```
<br>
지금까지 살펴본 배열은 아이템에 대한 식별자로 숫자를 사용했다. 데이터가 추가되면 배열 전체에서 중복되지 않는 인덱스가 자동으로 만들어져서 그 데이터에 대한 식별자가 되는 것이다. PHP에서는 인덱스로 문자를 사용하는 것도 가능하다. 일반적으로 다른 언어에서는 숫자를 인덱스로 사용하는 것을 일반적으로 배열, 혹은 indexed array라고 하고, 문자를 인덱스로 사용하는 것을 연관배열(associative array, hash, dictionary)라고 부르지만 PHP에서는 이를 특별히 구분하지 않고 있기 때문에 하나의 배열의 키 값으로 숫자와 문자 모두를 사용할 수 있다.

```php
<?php
$grades = array('egoing'=>10, 'k8805'=>6, 'sorialgi'=>80);
?>
```
위의 예제에서 egoing은 key가 되고, 10은 value가 된다.
```php
<?php
$grades = [];
$grades['egoing'] = 10;
$grades['k8805'] = 6;
$grades['sorialgi'] = 80;
var_dump($grades);
?>
```
이 방법으로도 연관배열을 만들 수 있다.
```php
<?php
$grades = array('egoing'=>10, 'k8805'=>6, 'sorialgi'=>80);
echo $grades['sorialgi'];
?>
```
이렇게 key 값을 가져 올 수 있다. 위 결과는 80이다.

반복문과 함께 사용할 수도 있다.
```php
<?php
$grades = array('egoing'=>10, 'k8805'=>6, 'sorialgi'=>80);
foreach($grades as $key => $value){
    echo "key: {$key} value:{$value}<br />";
}
?>
```
결과는 아래와 같다.

![image](https://user-images.githubusercontent.com/62539341/79411674-64de9f00-7fde-11ea-8f9d-806dbad91769.png)

-----------------------------------------------------------------

<h1>Write-up</h1>

1. webhacking.kr old 6

![image](https://user-images.githubusercontent.com/62539341/79440002-7771cc00-8010-11ea-99f6-8150dfa13f9f.png)

view-sourc를 클릭!

![image](https://user-images.githubusercontent.com/62539341/79440499-0aab0180-8011-11ea-81da-302c09323402.png)

현재 id는 guest, pw는 123qwe로 저장되어있다. 그리고 for문을 살펴보면, id와 pw를 base64_encode를 20번 반복한다...

![image](https://user-images.githubusercontent.com/62539341/79441594-65912880-8012-11ea-8768-3117cf678746.png)

이 부분을 보니까 decode_id가 admin 이고 decode_pw가 nimda이면 문제가 해결되는 것 같다.

우선 encode와 decode가 무엇인지 잘 모르겠어서 찾아보니 encode는 암호화, decode는 복호화라는 것을 알게 됬다.

다시 두번째 사진을 봤을 때, 복호화한 즉 디코딩한 값이 각각 admin, nimda 이어야 한다. 그러러면 디코딩하기 전, 인코딩한 값이 admin, nimda로 바뀌면... 되지 않을까?

php online compiler 에서
```php
 $val_id="guest";
  $val_pw="123qwe";
  for($i=0;$i<20;$i++){
    $val_id=base64_encode($val_id);
    $val_pw=base64_encode($val_pw);
  }
```
이 부분을 살짝 바꿔서 admin과 nimda를 20번 인코딩한 값을 쿠키 user와 password에 각각 넣고 새로고침했는데 

![image](https://user-images.githubusercontent.com/62539341/79446600-69747900-8019-11ea-8df8-71bd66f722e1.png)

오류가 떠서 문제를 풀지 못했다.. 브라우저를 웨일로 해서 그런가 생각하고 크롬으로 접속해서 다시 시도해봤는데 똑같은 오류가 났다...

2.webhacking.kr old-33

view-source 클릭!

![image](https://user-images.githubusercontent.com/62539341/79446940-0d5e2480-801a-11ea-8972-11c021adb043.png)

이번엔 엄청 코드가 간단해보이는데..

php 내부를 살펴보니 GET 방식으로 변수 get이 hehe로 값을 입력받으면
echo로 무언가?를 출력하는 것 같다.

![image](https://user-images.githubusercontent.com/62539341/79447450-d2a8bc00-801a-11ea-8f5a-6464bb3f07fa.png)

이렇게 get을 hehe로 입력하니깐 Next 버튼이 생겼다! Next 클릭!<br><Br>

![image](https://user-images.githubusercontent.com/62539341/79447641-20bdbf80-801b-11ea-8592-bb5d5f0e1707.png)

이번엔 POST 방식으로 post에 hehe, post2에 hehe2를 입력하면 다음 단계로 넘어가는가보다.

![image](https://user-images.githubusercontent.com/62539341/79452530-3cc55f00-8023-11ea-97e5-476d726797ea.png)

이렇게 기존 html 코드에 이 코드를 추가해서 post로 submit 할 수 있게 입력칸 두개랑 submit 버튼을 만들었다.

![image](https://user-images.githubusercontent.com/62539341/79452630-65e5ef80-8023-11ea-9210-49ee152b706d.png)
Next!<br><br>

![image](https://user-images.githubusercontent.com/62539341/79452725-92017080-8023-11ea-99f1-36f591736580.png)

GET방식으로 myip에 REMOTE_ADDR을 입력하면 문제가 풀리는 것 같다.
똑같이 입력했는데... 답이 아니라고 나왔다.

찾아보니 REMOTE_ADDR는 내 ip 주소를 입력하라는 것을 알게 되었다.
다시 ip 주소를 입력하니깐 문제 해결!

![image](https://user-images.githubusercontent.com/62539341/79453363-9417ff00-8024-11ea-8677-10f80619932f.png)

<br>이제 4번째 문제다.
![image](https://user-images.githubusercontent.com/62539341/79453408-a2feb180-8024-11ea-8d17-c9bc8c593ea9.png)

hint가 적혀있다.. 아직 어떻게 쓰일지 모르니 일단 view-source

![image](https://user-images.githubusercontent.com/62539341/79453487-bc9ff900-8024-11ea-9547-413ee749b8be.png)

이번에도 GET 방식으로 password 에 값을 입력하는 문제다
그런데 md5는 처음 보는 것이다. 

![image](https://user-images.githubusercontent.com/62539341/79453926-55cf0f80-8025-11ea-8d4c-05327208cfdf.png)

구글에 검색해서 hint의 숫자를 넣으니까 굉장히 복잡한 친구들이 출력됬다. 이 친구들을 password에 넣엇다. 근데 시간이 지나면 숫자가 바뀌어서 숫자를 넉넉하게 설정했다. 타이밍에 맞춰서 새로고침하니까 문제가 풀렸다!

![image](https://user-images.githubusercontent.com/62539341/79454324-f7566100-8025-11ea-911f-1d98b853965e.png)<br><br>

![image](https://user-images.githubusercontent.com/62539341/79454361-0d642180-8026-11ea-9b13-d3b5e8c93d90.png)

이번엔 GET이랑 POST랑 COOKIE랑 다같이 있는 문제다.

일단 GET은 imget을 URL에 추가하면 되고 POST 부분을 해결해야 되니까 페이지 소스를 조금 수정할 필요가 있다.

![image](https://user-images.githubusercontent.com/62539341/79455843-751b6c00-8028-11ea-925a-c1e2e70a1b70.png)


이렇게 post 할 수 있게 코드를 추가했다.

이제 imcookie의 이름으로 쿠키를 만들어줄 차례!

![image](https://user-images.githubusercontent.com/62539341/79455272-962f8d00-8027-11ea-9402-a533cabe345e.png)

![image](https://user-images.githubusercontent.com/62539341/79455918-9419fe00-8028-11ea-8ce1-e85c1c95bdd9.png)

submit을 하니 통과!<br><br>

![image](https://user-images.githubusercontent.com/62539341/79455991-b27ff980-8028-11ea-84fe-e637e4599948.png)

이번 문제에도 hint가 적혀있다. 브라우저마다 특정 숫자를 지정해놓은건가?

![image](https://user-images.githubusercontent.com/62539341/79456103-dfcca780-8028-11ea-87bf-45b2458e5d5b.png)

쿠키와 포스트 방식을 이용해서 문제를 풀어야 되겠다.

내 ip주소를 넣은 쿠키 'test'를 생성,
그리고 이제 post 방식으로 hint에 적힌 숫자를 넣어야 겠다.

![image](https://user-images.githubusercontent.com/62539341/79457473-3b983000-802b-11ea-98f6-26b2c5ef709b.png)

답이 아니라고 결과가 떴다. 어떻게 풀어야 되는 건지 잘 모르겠다...
