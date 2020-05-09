#include <iostream>

int main(){
    using namespace std;

    // decimal : 0 1 2 3 4 5 6 7 8 9 10 ...
    // octal   : 0 1 2 3 4 5 6 7 10 11 12 13 ...
    // hexa    : 0 1 2 3 4 5 6 7 8 9 A B C D E F 10 11 ...

    int x = 012; // this means octal
    cout << x << endl; // output 10

    int y = 0xF; // this means hexa
    cout << y << endl;  // output 15

    int z = 0b1010; // this means binary
    cout << z << endl;

    const int price_per_item = 10;
    int num_items = 123;
    int price = num_items * price_per_item;

    return 0;
}