# 연산자 오버로딩

### 연산자 오버로딩이란?
기존의 연산자를 재정의하여 사용자 정의 클래스로 사용하는 것을 말한다.
전역 함수 또는 클래스로 재정의 가능하다.

### 규칙
* \*\*와 같이 새로운 연산자를 정의할 수 없다.
* 기본 제공 데이터 형식에 적용할 때 연산자의 의미를 다시 정의할 수 없다.
* 오버로드 된 연산자는 비정적(non-static) 클래스 멤버 함수거나 전역 함수여야 한다.
* <span style="color:yellow">private 또는 protected 접근자의 전역함수는 해당 클래스의 friend로 선언해야 한다.</span>
* 멤버 함수로 오버로드된 연산자의 첫번째 파라미터는 항상 연산자가 호출되는 객체의 클래스 형식이다.


### 오버로딩 불가능한 연산자
연산자 | 이름
----------|--------------
.|멤버선택
.*|멤버 포인터 선택
::|범위
?:|조건
\#|문자열 전처리기 변환
\#\#|전처리기 연결

### 예시

```cpp
#include <iostream>
using namespace std;

class Point{
private :
    int x, y;

public:
    Point(int x_, int y_){
        x = x_;
        y = y_;
    }

    void print(){
        cout << "x : " << x << ", y : " << y << "\n";
    }
};

int main(){
    Point p1 = {1, 1};
    Point p2(2,2);
    
    Point p3 = p1 + p2;
    
    p3.print();

    return 0;
}
```
위 코드에서 Point class가 있고 그 내부에는 int x와 int y가 있다.
Point 객체 p1과 p2를 더해 p3에 넣고 싶은데, + 연산자에 대해 Point 객체는 지원해주고 있지 않다. + 연산자가 무엇을 의미하는지 모르기 때문이다.

이때 C++는 연산자 오버로딩을 사용할 수 있다.

```cpp
#include <iostream>
using namespace std;

class Point{
private :
    int x, y;

public:
    Point(int x_, int y_){
        x = x_;
        y = y_;
    }

    void print(){
        cout << "x : " << x << ", y : " << y << "\n";
    }

    Point operator + (Point& p){
        x = x + p.x;
        y = y + p.y;
        return Point(x,y);
    }
};

int main(){
    Point p1 = {1, 1};
    Point p2(2,2);
    
    Point p3 = p1 + p2;
    
    p3.print();

    return 0;
}
```
새로 생긴 `Point operator + (Point& p)` 함수를 살펴보자.
Point 객체를 반환하고, 함수의 이름을 operator로 함으로써 컴파일러에게 연산자 오버로드 함수인 것을 명시한다. 그 뒤에 연산자(여기서는 +)를 입력하고 매개변수로 Point 객체의 참조변수를 사용했다.

main 함수에서 `Point p3 = p1 + p2;` 를 보면 p1이 오버로드 된 + 연산자 함수를 호출하고, + 뒤에 있는 p2는 Point& p로 넘겨지는 것이다. 그리고 함수 내부의 결과값이 Poin 객체로 반환되어 이 값이 p3으로 넘어가게 된다.

### practice 1

```cpp
#include <iostream>
using namespace std;
 
class DIV {
private :
    int num, div;
public :
    DIV(int n, int d) {
        num = n;
        div = d;
    }
 
    operator double() const {
        return double(num) / double(div);
    }
};
 
 
int main(void) {
    DIV d(1, 3);
    double db = d;
    cout << d;
 
    return 0;
}
```

main 함수에서, double db를 선언하고 값을 DIV 객체인 d를 넘겨주었다. 어떻게 이게 가능할까? DIV class 안에서 double 키워드를 연산자 오버로딩하여 double 값을 반환하는 함수로 오버로딩했다. 그러무로 double 변수에 대입할 수 있는 것이다.

### practice 2

```cpp
#include <iostream>
using namespace std;
 
class Point {
private :
    int x, y;
 
public :
    Point(int x_, int y_) {
        x = x_;
        y = y_;
    }
 
    friend ostream& operator<<(ostream&, const Point&);
};
 
ostream& operator<<(ostream& os, const Point& p) {
    os << p.x << ", " << p.y;
    return os;
}
 
int main(void) {
    Point p(2, 3);
    
    cout << p;
 
    return 0;
}
```