// 60���� ����غ���
// 10�� : ��, ��, ��, ��, ��, ��, ��, ��, ��, ��
// 12�� : ��, ��, ��, ��, ��, ��, ��, ��, ��, ��, ��, ��
#include <iostream>
using namespace std;

string gann10(int);
string ji12(int);
string ttti(int);

int main(){   
    int year;
    cout << "������ �Է����ּ��� : ";
    cin >> year;
    
    cout << "�ش� �⵵�� 60���ڴ� : ";
    
    cout << gann10(year) << ji12(year) << "��" << endl;
    cout << ttti(year) << "�� ���Դϴ�." << endl;
}

string gann10(int when){
    string gann;
    int count;
    count = when % 10;
    switch(count){
        case 4:
            gann = "��";
            break;
        case 5:
            gann = "��";
            break;
        case 6:
            gann = "��";
            break;
        case 7:
            gann = "��";
            break;
        case 8:
            gann = "��";
            break;
        case 9:
            gann = "��";
            break;
        case 0:
            gann = "��";
            break;
        case 1:
            gann = "��";
            break;
        case 2:
            gann = "��";
            break;
        case 3:
            gann = "��";
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
            ji = "��";
            break;
        case 5:
            ji = "��";
            break;
        case 6:
            ji = "��";
            break;
        case 7:
            ji = "��";
            break;
        case 8:
            ji = "��";
            break;
        case 9:
            ji = "��";
            break;
        case 10:
            ji = "��";
            break;
        case 11:
            ji = "��";
            break;
        case 0:
            ji = "��";
            break;
        case 1:
            ji = "��";
            break;
        case 2:
            ji = "��";
            break;
        case 3:
            ji = "��";
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
            thi = "���";
            break;
        case 5:
            thi = "�Ҷ�";
            break;
        case 6:
            thi = "ȣ���̶�";
            break;
        case 7:
            thi = "�䳢��";
            break;
        case 8:
            thi = "���";
            break;
        case 9:
            thi = "���";
            break;
        case 10:
            thi = "����";
            break;
        case 11:
            thi = "���";
            break;
        case 0:
            thi = "�����̶�";
            break;
        case 1:
            thi = "�߶�";
            break;
        case 2:
            thi = "����";
            break;
        case 3:
            thi = "������";
            break;
    }
    return thi;
}