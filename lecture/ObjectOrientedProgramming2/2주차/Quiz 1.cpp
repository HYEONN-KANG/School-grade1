#include <iostream>

using namespace std;

void charCall(char *c)
{
    cout << "size of pointer c: " << sizeof(c) << endl;
}
void charCall(char &c)
{
    cout << "size of reference value c: " << sizeof(c) << endl;
}

int main()
{

    char ch = 'a';
    char &reference = ch;

    charCall(&ch);
    charCall(reference);
}
