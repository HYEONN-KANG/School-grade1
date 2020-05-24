<h1>CSRF 강의 요약</h1>

CSRF(Cross Site Request Forgery)란 특정 사용자의 세션을 탈취하는 데에는 실패하였지만 스크립팅 공격이 통할 때 사용할 수 있는 해킹 기법이다. 피해자가 스크립트를 보는 것과 동시에 자기도 모르게 특정한 사이트에 어떠한 HTTP 요청(Request) 데이터를 보낸다는 것이 특징이다.

![image](https://user-images.githubusercontent.com/62539341/82747656-41c1bf00-9dd6-11ea-8c47-d19d898d82ec.png)

이 글을 보는 순간 자기도 모르게 다른 글을 작성 하게 하는 CSRF 공격이다.

![image](https://user-images.githubusercontent.com/62539341/82747664-5b630680-9dd6-11ea-95d2-5b3c34b66d3a.png)

<h3>CSRF 공격을 하기 위한 조건</h3>
1. 해당 웹 사이트가 쿠키를 이용한 인증 방식을 사용해야 한다.
2. 공격자가 사전에 알 수 없는 파라미터가 존재하면 안된다.
  - 자동입력 방지 문자를 넣어야 하는 요청은 공격자가 미리 알 수 없다.
  - 패스워드 변경 기능에서 기존 패스워드를 입력 받는다면? 이 또한 공격자가 미리 알 수 없다.

<h3>Mitigation</h3>
CSRF 공격을 막기 위한 방법
1. 세션 쿠키 대신 커스텀 헤더를 사용하여 사용자 인증
  - 사용자 인증만을 위한 헤더를 추가한다.(e.g. Authorization)
2. 공격자가 예측할 수 없는 파라미터 추가 및 검증
  - Same Origin에서만 접근 가능한 데이터를 삽입
  - CAPTCHA
  - 정상적인 사용자만 아는 기존의 값을 검증(예: 현재 비밀번호)

<h3>SameSite Cookie</h3>
CSRF 공격이 가능한 이유는 웹 브라우저가 크로스 사이트, 즉 다른 사이트로부터 시작된 요청에 쿠키를 함께 전송한다는 점에 있다. 웹 브라우저가 쿠키를 다른 사이트로 부터 시작된 요청에 삽입할지를 SameSite 쿠키 설정을 보고 결정

크로스 사이트에서 출발한 요청에 제한적으로 쿠키를 포함시키게 하는 옵션이다. 총 3가지(Strict, Lax, Normal) 값을 설정할 수 있다. 기본적으로 Strict는 모든 크로스 사이트에서 출발한 요청에 해당 쿠키를 삽입하지 않는다. Lax는 Link, Prerender, Form GET을 제외한 요청에는 삽입하지 않고 Normal은 기존과 같이 모든 요청에 삽입한다.

<h1>Wirte-up</h1>

<h3> 1. Root-me : CSRF- 0 protection</h3>
https://www.root-me.org/en/Challenges/Web-Client/CSRF-0-protection

일단 회원가입하고 로그인해서 프로필에 들어가보았다.

![image](https://user-images.githubusercontent.com/62539341/82747947-e47b3d00-9dd8-11ea-9258-ef28aedf1897.png)

현재 Status 가 비활성화 되어있다. 아무래도 Status를 활성화 시켜야 인터넷에 연결가능한 것 같다.

![image](https://user-images.githubusercontent.com/62539341/82747965-0e346400-9dd9-11ea-8c6b-2bf800251ea8.png)

checkbox의 disabled를 abled로 수정해보았다.

checkbox에 체크를 하고 submit을 해보았더니

![image](https://user-images.githubusercontent.com/62539341/82747985-3de36c00-9dd9-11ea-8fc2-0ce9ec922a7a.png)

admin이 아니라고 거부당했다.

```html
<form id="hello" action=“http://challeng01.root-me.org/web-client/ch22/index.php?action=profile” method=“post” enctype=“multipart/form-data”>                    
<input type="text" name="username" value="hello">
<input type="checkbox" name="status" checked>
</form> <script>document.getElementById("hello").submit();</script>
```

이렇게 contact에 입력하고 submit을 눌러봤는데도 바뀐 것이 없다.. 잘 모르겠다.

<h3>2. xss challenge : #1 ~ #5</h3>
http://xss-quiz.int21h.jp/

![image](https://user-images.githubusercontent.com/62539341/82748952-db8e6980-9de0-11ea-84e4-d72d6340e276.png)

alert(document.domain) 경고창을 띄우라는 문제인것 같다. script 태그를 사용해서 바로 실행시켜보았다.

![image](https://user-images.githubusercontent.com/62539341/82748985-1db7ab00-9de1-11ea-8f11-e48ab1cd1090.png)

![image](https://user-images.githubusercontent.com/62539341/82748996-2d36f400-9de1-11ea-950f-e63a0b58332b.png)

경고창이 잘 실행 되었다.

![image](https://user-images.githubusercontent.com/62539341/82749011-42138780-9de1-11ea-83f3-f07e697839e8.png)

이번에도 alert(document.domain) 경고창을 띄우는 문제이다.

![image](https://user-images.githubusercontent.com/62539341/82749029-5fe0ec80-9de1-11ea-97a5-95d33f6cb146.png)

아까와 같이 입력해보았으나 실패했다.

![image](https://user-images.githubusercontent.com/62539341/82749067-acc4c300-9de1-11ea-9168-ee914d12fbc4.png)

힌트를 확인해보니 현재 태그를 닫고 스크립트를 추가하라고 되어 있다.

![image](https://user-images.githubusercontent.com/62539341/82749285-10032500-9de3-11ea-8c05-0f6856bb1ccd.png)

이렇게 입력을 해주었다.

![image](https://user-images.githubusercontent.com/62539341/82749294-1beee700-9de3-11ea-9ee7-029607e35cd4.png)

![image](https://user-images.githubusercontent.com/62539341/82749318-5062a300-9de3-11ea-9207-c5bf04286ebf.png)

이번에도 경고창을 띄우는 문제인 것 같은데 옆에 국가를 고를 수 있다.

텍스트 창엔 아무리 해도 공격이 통하지 않는다. 옆에 국가 고를 수 있는 칸이 괜히 있는게 아니라는 생각이 들었다. 선택란에 alert를 실행시키는 것을 넣으면 되지 않을까

![image](https://user-images.githubusercontent.com/62539341/82749385-e8608c80-9de3-11ea-9cb8-34fbc164bef5.png)

콘솔창에 이렇게 넣어주었다.

![image](https://user-images.githubusercontent.com/62539341/82749407-029a6a80-9de4-11ea-8244-590653102493.png)

정말 내가 원하는 대로 옵션에 alert가 떴다! alert 문장을 선택해주고 아무거나 입력한뒤 search를 눌러보았다.

![image](https://user-images.githubusercontent.com/62539341/82749428-2362c000-9de4-11ea-94c7-551cbafeeddd.png)

통과!

![image](https://user-images.githubusercontent.com/62539341/82749439-39708080-9de4-11ea-95fe-4a696ca20dda.png)

3번 문제와 아주 유사한 모습을 하고 있다. 3번과 똑같은 방법을 시도해보았다.

![image](https://user-images.githubusercontent.com/62539341/82749459-5ad16c80-9de4-11ea-9b46-7800bb57a448.png)

![image](https://user-images.githubusercontent.com/62539341/82749471-7472b400-9de4-11ea-9188-d463f39faae1.png)

search 클릭!

![image](https://user-images.githubusercontent.com/62539341/82749492-89e7de00-9de4-11ea-83d3-fc1427a809ef.png)

이번엔 이 방법은 잘 통하지 않는 것 같다. 

페이지 소스를 한번 살펴보았다.

![image](https://user-images.githubusercontent.com/62539341/82749558-e945ee00-9de4-11ea-9adc-b9b206bee98d.png)

소스 중에 아주 수상한 문장을 발견했다. type이 hidden인데다가, value가 hackme로 되어 있는 걸 봐선 이 것을 수정해봐야 겠다. 우선 type이 hidden인 것을 text로 바꿔서 우리 눈에 보이게 만들어줬다.

![image](https://user-images.githubusercontent.com/62539341/82749594-26aa7b80-9de5-11ea-9526-a74f6433f5ea.png)

숨겨져있던 p3가 등장했다. 이 곳에 alert 문장을 넣고 search를 눌러보았다.

![image](https://user-images.githubusercontent.com/62539341/82749619-5194cf80-9de5-11ea-8535-1be851e6d98a.png)

실패...

아까 2번 풀때의 방법으로 다시 한번 시도해보았다.

![image](https://user-images.githubusercontent.com/62539341/82749695-eef00380-9de5-11ea-9b7d-2232e9defee0.png)

![image](https://user-images.githubusercontent.com/62539341/82749700-fb745c00-9de5-11ea-8917-a4e82ed32f91.png)

통과...

![image](https://user-images.githubusercontent.com/62539341/82749732-32e30880-9de6-11ea-81b0-0de7ebb86b00.png)

마지막 문제니까 어렵겠지 생각하면서 기본 script 문장을 넣어봤더니 뒤에 있는 글자들은 아예 날라가버렸다.

![image](https://user-images.githubusercontent.com/62539341/82749754-5f972000-9de6-11ea-8a0b-d04b8a947e05.png)

maxlength가 15밖에 안되서 뒤 글자들은 입력이 안된 것 같다. 넉넉히 60으로 늘려서 다시 시도해보았다.

![image](https://user-images.githubusercontent.com/62539341/82749831-e3e9a300-9de6-11ea-9e72-3434dd725b7c.png)

![image](https://user-images.githubusercontent.com/62539341/82749836-eea43800-9de6-11ea-860f-785cab760344.png)