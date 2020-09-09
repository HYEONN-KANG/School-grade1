#include <iostream>

int *getPointer(int *x)
{
    return x;
}

int *getPointer(int x)
{
    return &x;
}

int main()
{
    using namespace std;

    int x = 10;
    int *xptr = &x;              // x의 포인터
    int *xptr2 = getPointer(&x); //x 주소가 저장
    cout << "x:" << x << endl;
    cout << "xptr:" << xptr << "\t";
    cout << "xptr:" << *xptr << endl;
    cout << "xptr2:" << xptr2 << "\t";
    cout << "*xptr2:" << *xptr2 << endl;
    int *xptr3 = getPointer(x); // 얘는 아예 새 주소
    cout << "xptr3:" << xptr3 << "\t";
    cout << "*xptr3:" << *xptr3 << endl;
    cout << endl
         << endl;
}
