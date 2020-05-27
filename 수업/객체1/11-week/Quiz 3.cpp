/* ppt p23~24의 샘플 코드를 구현하여 실행, 다음의 기능을 구현하는 copy3 함수를 추가
copy3은 배열2와 배열3을 연결하여[가운데 space 하나 넣어 주세요.] 배열1에 카피

Input array1: hello
Input array2: world

After copy3 function call.
Array3 is: hello world
*/

#include <iostream>
using namespace std;

void copy1(char *, const char *);
void copy2(char *, const char *);
void copy3(char *, const char *, const char *);

int main(){
    char string1[10];
    const char *string2 = "Hello";
    char string3[10];
    char string4[] = "Good Bye";

    copy1(string1, string2);
    cout << "string1 = " << string1 << endl;

    copy2(string3, string4);
    cout << "string3 = " << string3 << endl << endl;

    char array1[100];
    char array2[100];
    cout << "Input array1: ";
    cin >> array1;
    cout << "Input array2: ";
    cin >> array2;

    char array3[200];
    copy3(array3, array1, array2);
    cout << "\nAfter copy3 function call.\n";
    cout << "Array3 is: " << array3;

    return 0;
}

void copy3(char *s3, const char *s1, const char *s2){
    for(; *s1 != '\0'; s1++, s3++){
        *s3 = *s1;
    }
    *s3 = ' ';
    s3++;
    for(; *s2 != '\0'; s2++, s3++){
        *s3 = *s2;
    }
}

void copy1(char *s1, const char *s2){
    for(int i = 0; (s1[i] = s2[i]) != '\0'; i++){
        s1[i] = s2[i];
    }
}

void copy2(char *s1, const char *s2){
    for(; (*s1 = *s2) != '\0'; s1++, s2++){
        *s1 = *s2;
    }
}