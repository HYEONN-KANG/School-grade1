#include <iostream>
#include <string>

using namespace std;

class Arr
{
private:
    int *array;
    int size = 0;

public:
    Arr(int len)
    {
        this->size = len;
        this->array = new int[this->size];
        for (int i = 0; i < size; i++)
        {
            this->array[i] = 0;
        }
    }

    void at(int i)
    {
        cout << this->array[i] << endl;
    }

    void add(int i, int value)
    {
        for (int k = this->size - 1; k > i; k--)
        {
            this->array[k] = this->array[k - 1];
        }
        this->array[i] = value;
    }

    void remove(int i)
    {
        for (int k = i; k < this->size - 1; k++)
        {
            this->array[k] = this->array[k + 1];
        }
        this->array[this->size - 1] = 0;
    }

    void set(int i, int value)
    {
        this->array[i] = value;
        cout << value << endl;
    }

    void print()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << this->array[i] << " ";
        }
        cout << endl;
    }

    void find_min()
    {
        int min = 10001;
        for (int i = 0; i < this->size; i++)
        {
            if (this->array[i] < min)
                min = this->array[i];
        }
        cout << min << endl;
    }
};

int main()
{
    int N;
    cin >> N;

    Arr A(N);

    int T;
    cin >> T;

    string s = "";
    int fir = 0, sec = 0;

    for (int test = 0; test < T; test++)
    {
        cin >> s;

        if (s == "set")
        {
            cin >> fir >> sec;
            A.set(fir, sec);
        }
        else if (s == "at")
        {
            cin >> fir;
            A.at(fir);
        }
        else if (s == "add")
        {
            cin >> fir >> sec;
            A.add(fir, sec);
        }
        else if (s == "remove")
        {
            cin >> fir;
            A.remove(fir);
        }
        else if (s == "print")
        {
            A.print();
        }
        else if (s == "find_min")
        {
            A.find_min();
        }
        s = "";
    }
}