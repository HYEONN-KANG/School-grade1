#include <iostream>
#include <limits>

int main(){
    using namespace std;

    char c1(65);    // c1 = 65, c1{65} all same means.
    char c2('A');

    cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;
    
    // c-style casting
    cout << (char)65 << endl;
    cout << (int)'A' << endl;

    // cpp style
    cout << char(65) << endl;
    cout << int('A') << endl;

    cout << static_cast<char>(65) << endl;
    cout << static_cast<int>('A') << endl;

    char ch(97);
    cout << ch << endl;
    cout << static_cast<int>(ch) << endl; // can put variable in static_cast
    cout << ch << endl;

    // try to input char
    cin >> c1;
    cout << c1 << " " << static_cast<int>(c1) << endl;

    cin >> c1;
    cout << c1 << " " << static_cast<int>(c1) << endl;

    cin >> c1;
    cout << c1 << " " << static_cast<int>(c1) << endl;

    // char size ?
    cout << sizeof(char) << endl;
    cout << (int)std::numeric_limits<char>::max() << endl;
    cout << (int)std::numeric_limits<char>::lowest() << endl;

    // unsigned char size ?
    cout << sizeof(unsigned char) << endl;
    cout << (int)std::numeric_limits<unsigned char>::max() << endl;
    cout << (int)std::numeric_limits<unsigned char>::lowest() << endl;

    cout << int('\n') << endl;

    wchar_t c;  // window char. programmer hate it. don't use.
    char16_t c3;

    return 0;
}