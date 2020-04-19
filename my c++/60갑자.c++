// 60갑자 계산해보기
// 10간 : 갑, 을, 병, 정, 무, 기, 경, 신, 임, 계
// 12지 : 자, 축, 인, 묘, 진, 사, 오, 미, 신, 유, 술, 해
#include <iostream>
using namespace std;

string gann10(int);
string ji12(int);
string ttti(int);

int main(){   
    int year;
    cout << "연도를 입력해주세요 : ";
    cin >> year;
    
    cout << "해당 년도의 60갑자는 : ";
    
    cout << gann10(year) << ji12(year) << "년" << endl;
    cout << ttti(year) << "의 해입니다." << endl;
}

string gann10(int when){
    string gann;
    int count;
    count = when % 10;
    switch(count){
        case 4:
            gann = "갑";
            break;
        case 5:
            gann = "을";
            break;
        case 6:
            gann = "병";
            break;
        case 7:
            gann = "정";
            break;
        case 8:
            gann = "무";
            break;
        case 9:
            gann = "기";
            break;
        case 0:
            gann = "경";
            break;
        case 1:
            gann = "신";
            break;
        case 2:
            gann = "임";
            break;
        case 3:
            gann = "계";
            break;
    }
    return gann;
}

string ji12(int when){
    string ji;
    string thi;
    int count;
    count = when % 12;
    switch(count){
        case 4:
            ji = "자";
            break;
        case 5:
            ji = "축";
            break;
        case 6:
            ji = "인";
            break;
        case 7:
            ji = "묘";
            break;
        case 8:
            ji = "진";
            break;
        case 9:
            ji = "사";
            break;
        case 10:
            ji = "오";
            break;
        case 11:
            ji = "미";
            break;
        case 0:
            ji = "신";
            break;
        case 1:
            ji = "유";
            break;
        case 2:
            ji = "술";
            break;
        case 3:
            ji = "해";
            break;
    }
    return ji;
}

string ttti(int when){
    string thi;
    int count;
    count = when % 12;
    switch(count){
        case 4:
            thi = "쥐띠";
            break;
        case 5:
            thi = "소띠";
            break;
        case 6:
            thi = "호랑이띠";
            break;
        case 7:
            thi = "토끼띠";
            break;
        case 8:
            thi = "용띠";
            break;
        case 9:
            thi = "뱀띠";
            break;
        case 10:
            thi = "말띠";
            break;
        case 11:
            thi = "양띠";
            break;
        case 0:
            thi = "원숭이띠";
            break;
        case 1:
            thi = "닭띠";
            break;
        case 2:
            thi = "개띠";
            break;
        case 3:
            thi = "돼지띠";
            break;
    }
    return thi;
}