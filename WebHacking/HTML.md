출처 : 생활코딩

```html
<h1>오늘의 명언</h1>
우리 모두는 <strong>자신의 힘</strong>으로 발견한 내용을 가장 쉽게 익힌다.(도널드 커누스)
```
<h1\> 이라는 태그를 열어 웹 브라우저는 오늘의 명언을 제목으로 처리한다. <h1\>이 끝날때까지 굵고 큰 문자로 꾸며주고 줄바꿈을 한번 한다. (<h1\>을 <h2\>로 바꾸면 글씨가 조금 작아진다.)

<strong\> 이라는 태그는 단어를 강조, 진하게 표시한다.

여기서 <strong\>은 시작태그, </strong\>은 닫히는 태그이다.

<a\> 태그를 걸어 문자가 링크라는 사실을 알려주고 웹 페이지로 이동할 수 있도록 한다.

```html
<a href="https://www.google.co.kr/" target="_blank" title="구글홈페이지">구글</a>
```
target은 '구글'을 클릭했을 때 해당 웹 페이지에서 바로 링크로 들어가지 않고 다음 탭에서 링크로 새로 열리도록 한다.

title은 마우스 포인터를 '구글'위로 올려 놨을때 구글홈페이지 워드가 뜨도록 한다.

![image](https://user-images.githubusercontent.com/62539341/82145108-75a35e80-9883-11ea-9f7f-c98e1bca55ff.png)


<li\> 태그를 사용하면 목록으로 표현<br>
<ul\> 태그로 같은 종류의 태그를 묶어 grouping 할 수 있다.<br>
<ol\>은 숫자가 붙고 <ul\>은 숫자가 붙지 않는다.

태그와 태그는 중첩해서 사용 가능하다.

```html
<ol>
    <li>기술소개</li>
    <li>기본문법</li>
    <li>하이퍼텍스트와 속성</li>
    <li>리스트와 태그의 중첩</li>
</ol>
<ul>
    <li>최진혁</li>
    <li>최유빈</li>
    <li>한이람</li>
    <li>한이은</li>
</ul>
```

![image](https://user-images.githubusercontent.com/62539341/82145202-12fe9280-9884-11ea-8fbf-6455759a38cc.png)

<title\> 태그를 이용해서 웹 페이지 제목을 멋있게 설정할 수 있다.

글씨가 이상하게 깨지는 경우가 있을 때는 <meta charset="utf-8"> 태그를 추가해주면 이 현상을 없앨 수 있다.

html은 부가적인 정보와 본문을 각각 다른 태그에 담도록 약속했다.

```html
<!DOCTYPE html>
<html>
    <head>
        <title>HTML - 수업</title>
        <meta charset="utf-8">
    </head>
    <body>
        <h1>HTML</h1>
        <ol>
            <li>기술소개</li>
            <li>기본문법</li>
            <li>하이퍼텍스트와 속성</li>
            <li>리스트와 태그의 중첩</li>
        </ol>
        <ul>
            <li>최진혁</li>
            <li>최유빈</li>
            <li>한이람</li>
            <li>한이은</li>
        </ul>
        HTML을 공부합니다.
    </body>
</html>
```

본문이 아닌 것은 <head\>태그 안에, 본문은 <body\>태그 안에 들어온다. 

그리고 <head\>와 <body\>를 <html\>태그로 감싸준다.

<\!DOCTYPE html\>은 document type declaration 의 약자

자신이 작성한 html 코드가 어떤 방식의 html 코드로 작성됬는지를 선언하는 것이다.

![image](https://user-images.githubusercontent.com/62539341/82145298-c9627780-9884-11ea-9152-ab5927305cf1.png)
