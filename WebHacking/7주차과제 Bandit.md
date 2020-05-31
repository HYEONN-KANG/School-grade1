출처 : https://overthewire.org/wargames/bandit/

![image](https://user-images.githubusercontent.com/62539341/83342096-0703dd80-a326-11ea-8f68-d1f1ff33baee.png)

<h3>Level 0</h3>

SSH를 사용해서 bandit0로 로그인해야 한다.

![image](https://user-images.githubusercontent.com/62539341/83342176-fd2eaa00-a326-11ea-937a-b03632cf4571.png)

> ssh bandit0@bandit.labs.overthewire.org -p2220 

(ssh서버에 포트2220을 사용해서 접속하겠다) 

![image](https://user-images.githubusercontent.com/62539341/83342301-c78ac080-a328-11ea-887b-08a8eb863162.png)

그러면 비밀번호를 입력하라고 뜨는데 문제에 적혀있는대로 badit0를 입력해주면 된다. 비밀번호를 입력할 때 화면에 비밀번호가 입력되는지 보이지 않아 입력되는건가 헷갈렸는데 일종의 보안기능인가보다. 비밀번호를 입력하면 다음과 같이 badit0로 로그인된다.

![image](https://user-images.githubusercontent.com/62539341/83342318-015bc700-a329-11ea-86fd-e981bb91c4b6.png)


<h3>Level 0 -> Level 1</h3>

SSH로 badit1에 로그인을 해야 한다.

![image](https://user-images.githubusercontent.com/62539341/83342145-9c9f6d00-a326-11ea-8c59-28bba9e3c45f.png)

다음 레벨로 가기 위한 패스워드는 readme에 있다고 한다. 밑에 이 문제를 풀기 위해 ls, cd, cat, file, du, find 명령어를 사용해야 한다고 적혀있다.

- ls : 현재 디렉토리에 있는 내용(디렉토리, 파일)등을 확인
  - ls - a : 숨겨진 디렉토리나 파일 모두 확인
  - ls - l : 자세한 내용 확인
- cd : 디렉토리로 이동
  - cd . : 현재 디렉토리
  - cd .. : 한 단계 상위 디렉토리
  - cd / :최상위 디렉토리
- cat :  파일 내용을 출력
- file : 파일의 종류(type)을 확인
- du : disk usage의 약자로써 현재 디렉토리 혹은 지정한 디렉토리의 사용량을 확인
- find : 파일 및 디렉토리를 검색

![image](https://user-images.githubusercontent.com/62539341/83342646-c65b9280-a32c-11ea-9a77-4af7512ae81d.png)

비밀번호가 바로 떴다. 통과!

<h3>Level 1 -> Level 2</h3>

![image](https://user-images.githubusercontent.com/62539341/83342832-d5434480-a32e-11ea-9219-3a4b20428484.png)

password는 파일 안에 존재한다고 한다.

일단 ls로 파일을 확인해보니 -의 이름을 가진 파일을 확인하였고 cat으로 파일의 내용을 확인하려했지만 무슨 이유에선지 내용이 보이지 않는다.

찾아보니 파일이름이 앞과는 다르게 특수문자여서 ~/ 절대경로로 파일을 인식시켜주면 된다고 한다.

![image](https://user-images.githubusercontent.com/62539341/83342836-e2f8ca00-a32e-11ea-8578-fde642274a35.png)

<h3>Level 2 -> Level 3</h3>

![image](https://user-images.githubusercontent.com/62539341/83343004-4c2d0d00-a330-11ea-9c61-4eb9d69d75f4.png)

이번엔 비밀번호가 들어있는 파일 이름이 spaces in this filename라고 적혀있다.

파일 이름안에 공백이 있으니 아까처럼 절대경로로 파일을 인식시킬 수 있지 않을까?

![image](https://user-images.githubusercontent.com/62539341/83343008-551dde80-a330-11ea-860a-0cd7cc26f35a.png)

구글링을 해보니 파일 이름의 공백은 큰 따옴표("")로 묶어주면 된다고 한다.

![image](https://user-images.githubusercontent.com/62539341/83343028-6bc43580-a330-11ea-93fb-808ae71851c9.png)

<h3>Level 3 -> Level 4</h3>

![image](https://user-images.githubusercontent.com/62539341/83343074-0e7cb400-a331-11ea-8e5c-4437a0de12d0.png)

inhere 디렉토리 안에 숨겨진 파일이 존재한다고 한다.

아까 ls 명령어에 대해 알아볼 때 모든 파일을 볼때는 옵션 -a를 쓴다고 했다. 숨겨진 파일이라고 했으니 ls로 봤을 때는 파일이 보이지 않고 옵션 -a를 추가하면 파일이 보일 것이다.

![image](https://user-images.githubusercontent.com/62539341/83343077-176d8580-a331-11ea-9494-8d44f0e4c26d.png)

<h3>Level 4 -> Level 5</h3>

![image](https://user-images.githubusercontent.com/62539341/83343253-b777de80-a332-11ea-8bc4-a24194351b66.png)

inhere 디렉토리 안에 사람만 읽을 수 있는 파일이 존재한다고 적혀있다.

파일 내용을 확인해보니 글자가 이상하게 생겼다. 사람은 읽을 수 있다고 했는데... 나는..?

![image](https://user-images.githubusercontent.com/62539341/83343256-c2327380-a332-11ea-82cb-b02f1a3ad16d.png)

![image](https://user-images.githubusercontent.com/62539341/83343263-d0808f80-a332-11ea-8d8b-075a7b6652fc.png)

아..! -file07번을 열어보니 읽을 수 있는 파일이다! 이게 비밀번호인가보다!

![image](https://user-images.githubusercontent.com/62539341/83343269-de361500-a332-11ea-9ad1-253c04487abd.png)

<h3>Level 5 -> Level 6</h3>

![image](https://user-images.githubusercontent.com/62539341/83343427-10487680-a335-11ea-9de4-97df819d953d.png)

inhere 디렉토리 안에 어디간에 비밀번호가 들어있는 파일이 존재한다. 그리고 파일은 사람이 읽을 수 있고, 실행 불가하고, 1033 바이트 사이즈를 가진다.

디렉토리가 19개나 있다... 아무래도 이걸 하나하나 다 확인해보아야 겠다.

![image](https://user-images.githubusercontent.com/62539341/83343430-176f8480-a335-11ea-990f-43f6076c2080.png)

디렉토리 안에 파일을 확인해보니 실행 불가능한 파일들만 살펴보면 되겠다.

![image](https://user-images.githubusercontent.com/62539341/83343433-21918300-a335-11ea-91df-5f0f2ed9744e.png)

하나 실행해보니 이건 노가다해서 될 게 아니라고 생각이 들었다.

힌트에 1033 바이트라고 했으니 du 명령어를 쓰면 된다고 생각을 못했다! 하마터면 헛수고를 할 뻔 했다. 이 많은 것들을 하나하나 해 보려고 했다니... ㄷㄷ

![image](https://user-images.githubusercontent.com/62539341/83343446-4128ab80-a335-11ea-8b31-c7c112bb4f65.png)

여기서 1033 바이트 사이즈를 가진 놈을 찾으면 된다. 파일 위치 확인!

![image](https://user-images.githubusercontent.com/62539341/83343453-5e5d7a00-a335-11ea-8efb-66a17494ce68.png)

![image](https://user-images.githubusercontent.com/62539341/83343462-7e8d3900-a335-11ea-93b4-e6ce3ddf8ba3.png)

<h3>Level 6 -> Level 7</h3>

![image](https://user-images.githubusercontent.com/62539341/83343574-438c0500-a337-11ea-9549-b8cef3875711.png)

이번엔 새롭게 grep 이라는 명령어가 등장했다.

- grep : 입력으로 전달된 파일의 내용에서 특정 문자열을 찾고자할 때 사용

![image](https://user-images.githubusercontent.com/62539341/83343577-4d156d00-a337-11ea-8c7c-db8e24701490.png)

이번엔 조금 헤매다가 find 옵션 다 적용해서 이렇게 찾아봤다.
size 33바이트고, bandit7이 주인이고, 그룹은 badit6

![image](https://user-images.githubusercontent.com/62539341/83343586-661e1e00-a337-11ea-8a34-ab872ec6c603.png)
 
누가 봐도 이것이 비밀번호가 있는 파일이다!

![image](https://user-images.githubusercontent.com/62539341/83343599-7afab180-a337-11ea-96d6-97c185a8c98b.png)

<h3>Level 7 -> Level 8</h3>

![image](https://user-images.githubusercontent.com/62539341/83343926-91a30780-a33b-11ea-843d-4d1d25687294.png)

이번에도 명령어가 몇개 더 추가됬다.

- sort : 명령어 결과 혹은 문서 내용을 정렬
- uniq : 중복된 내용의 행이 연속적으로 있다면 하나만 남기고 삭제한다. 전체적으로 분산된 중복은 찾지 못해 sort와 같이 쓰이기 좋다.
- strings : 프로그램 안에서 사용된 문자열을 출력
- base64 : 문자열을 base64로 디코드
- tr : translate 의 약어로서, 특정한 문자를 다른 문자로 바꾸거나 또는 특정 문자를 제거
- tar : 여러 개의 파일을 하나의 파일로 묶거나 풀 때 사용
- gzip : 파일을 압축 및 해제, tar과 함께 잘 사용된다.
- bzip2 : 파일을 압축 및 해제
- xxd : 바이너리 데이터를 16진수로, 16진수 데이터를 바이너리 데이터로 변환

ls로 확인해보면 data.txt가 존재한다. 이를 cat로 확인해보면 아~주 많은 데이터들이 출력된다.

![image](https://user-images.githubusercontent.com/62539341/83343928-9962ac00-a33b-11ea-84be-eb87f4ad62c2.png)

일단 저 명령어들은 어떻게 사용해야 할지 잘 모르겠고 아까 나왔던 grep 으로 millionth를 검색해봤다.

![image](https://user-images.githubusercontent.com/62539341/83343933-ac757c00-a33b-11ea-86c2-71476952bc05.png)

<h3>Level 8 -> Level 9</h3>

![image](https://user-images.githubusercontent.com/62539341/83344070-48ec4e00-a33d-11ea-8acd-eead7b8d14c1.png)

data.txt를 확인해보니 또 엄청 많은 데이터들이 쏟아져 나온다.

텍스트가 하나만 나온다고 했으니 아까 찾아본 uniq를 사용해보아야 겠다.

![image](https://user-images.githubusercontent.com/62539341/83344079-51448900-a33d-11ea-8760-705bce0dbfbd.png)

<h3>Level 9 -> Level 10</h3>

![image](https://user-images.githubusercontent.com/62539341/83344200-78e82100-a33e-11ea-97b9-13aa858d22ef.png)

이번엔 strings를 사용해서 문자열을 찾아보면 되겠다!

![image](https://user-images.githubusercontent.com/62539341/83344209-8ef5e180-a33e-11ea-96e2-ffa116c9cc9d.png)

<h3>Level 10 -> Level 11</h3>

![image](https://user-images.githubusercontent.com/62539341/83344286-923d9d00-a33f-11ea-9e10-10c375045064.png)

이번엔 base64를 디코드하면 될 것 같다!

![image](https://user-images.githubusercontent.com/62539341/83344289-9d90c880-a33f-11ea-98e6-02b6e0fe8fa7.png)

왜 안되지..? base64는 base64로 디코드한다고 했는데 안 되는 이유를 모르겠다.

![image](https://user-images.githubusercontent.com/62539341/83344293-ab464e00-a33f-11ea-8271-092367039d96.png)
