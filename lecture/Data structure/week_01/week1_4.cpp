// 얘도 다시 풀기
#include <iostream>

using namespace std;

int main()
{
    int N, T, D, x;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N >> D;
        int *Arr = new int[N];
        // set
        for (int k = 0; k < N; k++)
        {
            cin >> x;
            Arr[k] = x;
        }

        // shift
        for (int shift = 0; shift < D; shift++)
        {
            x = Arr[0];
            for (int j = 0; j < N - 1; j++)
            {
                Arr[j] = Arr[j + 1];
            }
            Arr[N - 1] = x;
        }
        // print
        for (int p = 0; p < N; p++)
        {
            cout << Arr[p] << " ";
        }
        cout << endl;
    }
}