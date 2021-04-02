#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    const int num = 20;

    int array[num];

    for (int i = 0; i < num; i++)
    {
        array[i] = rand() % 991 + 10;
    }

    cout << "랜덤으로 생성된 20개의 수는: ";

    for (int i = 0; i < num; i++)
    {
        cout << array[i] << " ";
    }

    int input;
    cout << "\n"
         << "찾으려는 수를 입력하세요: ";
    cin >> input;

    for (int i = 0; i < num; i++)
    {
        if (input == array[i])
        {
            cout << "찾으려는 수의 index값은: " << i << " 번째 입니다.\n";
            break;
        }
    }

    return 0;
}