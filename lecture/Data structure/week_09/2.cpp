#include <iostream>
#include <vector>
using namespace std;

class isLess
{ // 비교자
public:
    bool operator()(const int a, const int b) const
    {
        if (a < b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class PQ
{
private:
    vector<int> v;

public:
    int size();
    bool empty();
    void insert(int e);
    int min();
    int max();
    void removeMin();
    void removeMax();
    void print();
};

int PQ::size()
{
    return v.size();
}

bool PQ::empty()
{
    return v.size() == 0;
}

void PQ::print()
{
    for (vector<int>::iterator iter = --v.end(); iter != v.begin(); --iter)
    {
        cout << *iter << ' ';
    }
    cout << *v.begin() << endl;
}

void PQ::insert(int e)
{
    vector<int>::iterator p = v.begin();
    isLess C;

    if (v.empty())
    {
        v.insert(p, e);
    }
    else
    {
        while (p != v.end() && C(e, *p))
        {
            ++p;
        }
        v.insert(p, e);
    }
}

int PQ::min()
{
    return v.back();
}

int PQ::max()
{
    return v.front();
}

void PQ::removeMin()
{
    v.pop_back();
}

void PQ::removeMax()
{
    v.erase(v.begin());
}

int main()
{
    int T;
    cin >> T;

    for (int test = 0; test < T; test++)
    {
        int N;
        cin >> N;

        PQ pq;
        vector<int> s;

        for (int i = 0; i < N; i++)
        { // 정렬하지 않고 삽입
            int n;
            cin >> n;
            pq.insert(n);
        }

        for (int i = 0; i < N; i++)
        {
            s.push_back(pq.max());
            pq.removeMax();
        }

        for (int i = 0; i < N; i++)
        {
            cout << s.at(i) << " ";
        }
        cout << endl;
    }

    return 0;
}