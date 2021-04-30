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
    void removeMin();
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
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << ' ';
    }
    cout << endl;
}

void PQ::insert(int e)
{
    v.push_back(e);
}

int PQ::min()
{
    vector<int>::iterator p = v.begin();
    isLess C;
    int m_value = *v.begin();

    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        if (!C(m_value, *iter))
        {
            m_value = *iter;
            p = iter;
        }
    }
    return *p;
}

void PQ::removeMin()
{
    vector<int>::iterator p = v.begin();
    isLess C;
    int m_value = *v.begin();

    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        if (!C(m_value, *iter))
        {
            m_value = *iter;
            p = iter;
        }
    }

    v.erase(p);
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
        PQ sq;

        for (int i = 0; i < N; i++)
        { // 정렬하지 않고 삽입
            int n;
            cin >> n;
            pq.insert(n);
        }

        for (int i = 0; i < N; i++)
        {
            sq.insert(pq.min());
            pq.removeMin();
        }

        sq.print();
    }

    return 0;
}