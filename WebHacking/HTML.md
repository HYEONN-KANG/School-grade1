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

<p\> 태그는 paragraph 의 줄임말로 단락이란 뜻이다. <p\> 태그를 이용하여 단락을 지정할 수 있다.<br>
<br\> 태그를 이용하면 줄바꿈을 할 수 있다.

```html
<html>
    <body>
        <meta charset="utf-8">
        <p>
            Hypertext Markup Language (HTML) is the standard markup language for documents designed to be displayed in a web browser. 
            hnologies such as Cascading Style Sheets (CSS) and scripting languages such as JavaScript.
        </p>
        <p>
            Web browsers receive HTML documents from a web server or from local storage and render the documents into multimedia web pages. 
            HTML describes the structure of a web page semantically and originally included cues for the appearance of the document.
        </p>
        <p>
            HTML elements are the building blocks of HTML pages. With HTML constructs, images and other objects such as interactive forms 
            may be embedded into the rendered page. HTML provides a means to create structured documents 
            by denoting structural semantics for text such as headings, paragraphs, lists, links, quotes and other items. <br>
            HTML elements are delineated by tags, written using angle brackets. Tags such as <img\> and <input\> directly introduce content into the page. 
            Other tags such as <p\> surround and provide information about document text and may include other tags as sub-elements. 
            Browsers do not display the HTML tags, but use them to interpret the content of the page.
        </p>
        <img src="img.jpg" height="300" alt="이미지" title="image">
    </body>
</html>
```

<img\>를 용해 이미지를 웹 페이지에 나타낼 수 있다. height는 높이, width는 폭을 설정해서 사진의 크기를 조절할 수 있다. alt라는 속성을 사용하면 이미지가 깨졌을 때 텍스트를 표시해준다. title은 마우스 포인터를 사진 위로 올렸을 때 텍스트를 표시해준다.

![image](https://user-images.githubusercontent.com/62539341/82179911-66232480-991a-11ea-9a37-73b3e5acc8fa.png)

form은 사용자가 입력한 정보를 서버로 전송할 때 사용하는 것이다.

<input\>으로 사용자의 입력을 받아올 수 있다.

text로 형식을 지정하면 사용자가 입력하는 text를 받아올 수 있다.

password로 type을 하면 사용자가 입력하는 글자는 보이지 않는다.

submit은 제출 버튼을 생성해준다.

사용자가 입력한 정보를 어디로 보낼 것인가를 form 태그 안에 써주면 된다.