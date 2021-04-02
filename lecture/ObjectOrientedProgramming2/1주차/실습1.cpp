#include <iostream>

using namespace std;

int main()
{
    for (int second = 1; second <= 9; second++)
    {
        for (int first = 2; first <= 5; first++)
        {
            cout << first << " " << char(88) << " " << second << " = " << first * second << "\t";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int second = 1; second <= 9; second++)
    {
        for (int first = 6; first <= 9; first++)
        {
            cout << first << " " << char(88) << " " << second << " = " << first * second << "\t";
        }
        cout << "\n";
    }

    return 0;
}