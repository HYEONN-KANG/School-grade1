/*
bitwise operators 직접 사용해보기
0110 >> 2 -> decimal
5 | 12
5 & 12
5 ^ 12
*/

#include <iostream>
#include <bitset>
using std::cout;
using std::endl;

int main(){
    unsigned int val = 0b0110;

    cout << std::bitset<4>(val >> 2) << " " << (val >> 2) << endl << endl;

    cout << std::bitset<4>(5 | 12) << endl;
    cout << std::bitset<4>(5 & 12) << endl;
    cout << std::bitset<4>(5 ^ 12) << endl << endl;

    cout << (5 | 12) << endl;
    cout << (5 & 12) << endl;
    cout << (5 ^ 12) << endl;
}