#include <iostream>
using namespace std;

int main()
{
    int i, j, k, l;
    int num;
    cout << "Input number : ";
    cin >> num;
    
    for (i = 1; i <= num; i++)
    {
        for (j = num; j > i; j--)
        {
            cout << " " ;
        }
        for (k = i; k >= 1; k--)
        {
            cout << k;
        }
        for (l = 2; l <= i; l++)
        {
            cout << l;
        }
        cout << endl;
    }

    return 0;
}