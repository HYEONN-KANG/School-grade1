#include <iostream>
#include <cstring>

using namespace std;

int typing(char *, char *);

int main()
{
    char str[] = "Hello World!";
    char str_input[50] = "";
    while (true)
    {
        cout << str << endl;
        cout << "type sentence above: ";
        cin.getline(str_input, strlen(str) + 1);

        if (typing(str, str_input) == 0)
        {
            break;
        }
        else
        {
            continue;
        }
    }

    return 0;
}

int typing(char *str1, char *str2)
{
    int result = 0;
    if (strcmp(str1, str2) == 0)
    {
        cout << "Correnct Answer!" << endl
             << endl;
        result = 0;
    }
    else
    {
        cout << "Incorrenct Answer!" << endl
             << endl;
        result = -1;
    }

    return result;
}