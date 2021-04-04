#include <iostream>
#include <string>
using namespace std;

class SequenceList
{
private:
    struct Node
    {
        int e;
        Node *prev;
        Node *next;
    };

public:
    class Iterator // 반복자 클래스
    {
    private:
        Node *v; // 반복자가 가리키는 노드를 저장하기 위한 포인터 변수
        Iterator(Node *u);

    public:
        int &operator+();
        bool operator==(const Iterator &p) const;
        bool operator!=(const Iterator &p) const;
        Iterator &operator++();
        Iterator &operator--();

        // SequenceList class 가 Iterator class에 접근 가능하도록 friend 선언
        friend class SequenceList;
    };

private:
    int n;         // list size
    Node *header;  // header sentinel node
    Node *trailer; // trailer sentinel node

public:
    SequenceList();
    int size() const;
    bool empty() const;
    Iterator begin() const;
    Iterator end() const;
    void insertFront(const int &e);
    void insertBack(const int &e);
    void insert(const Iterator &p, const int &e);
    void eraseFront();
    void eraseBack();
    void erase(const Iterator &p);

    SequenceList::Iterator atIndex(int i) const; // index i를 갖는 원소의 위치를 반환
    int indexOf(const Iterator &p) const;        // 위치 p에 있는 원소의 index를 반환하는 함수

    void convolution();
};

void SequenceList::convolution()
{
    Iterator iter(begin());
    while (iter != end())
    {
        Node *v = iter.v;
        Node *u = v->prev;
        Node *w = v->next;

        cout << 1 * (u->e) + 3 * (v->e) + 1 * (w->e) << " ";

        ++iter;
    }
    cout << endl;
}

SequenceList::SequenceList()
{
    n = 0;
    header = new Node;
    trailer = new Node;
    header->e = 0;
    trailer->e = 0;
    header->next = trailer;
    trailer->prev = header;
}

void SequenceList::insert(const SequenceList::Iterator &p, const int &e)
{
    Node *w = p.v;
    Node *u = w->prev;
    Node *v = new Node;
    v->e = e;
    v->next = w;
    w->prev = v;
    v->prev = u;
    u->next = v;
    this->n++;
}

void SequenceList::insertFront(const int &e)
{
    insert(begin(), e);
}

void SequenceList::insertBack(const int &e)
{
    insert(end(), e);
}

void SequenceList::erase(const Iterator &p)
{
    if (empty())
        cout << "Empty" << endl;
    else
    {
        Node *v = p.v;
        Node *w = v->next;
        Node *u = v->prev;
        u->next = w;
        w->prev = u;
        delete v;
        this->n--;
    }
}

void SequenceList::eraseFront()
{
    erase(begin());
}
void SequenceList::eraseBack()
{
    erase(--end());
}

int SequenceList::size() const
{
    return n;
}

bool SequenceList::empty() const
{
    return (n == 0);
}

SequenceList::Iterator::Iterator(Node *u)
{
    v = u;
}

SequenceList::Iterator SequenceList::begin() const
{
    return Iterator(header->next);
}

SequenceList::Iterator SequenceList::end() const
{
    return Iterator(trailer);
}
int &SequenceList::Iterator::operator+()
{
    return v->e;
}

bool SequenceList::Iterator::operator==(const Iterator &p) const
{
    return v == p.v;
}

bool SequenceList::Iterator::operator!=(const Iterator &p) const
{
    return v != p.v;
}

SequenceList::Iterator &SequenceList::Iterator::operator++()
{
    v = v->next;
    return *this;
}

SequenceList::Iterator &SequenceList::Iterator::operator--()
{
    v = v->prev;
    return *this;
}

SequenceList::Iterator SequenceList::atIndex(int i) const
{
    Iterator p = begin();
    for (int j = 0; j < i; j++)
    {
        ++p;
    }
    return p;
}

int SequenceList::indexOf(const Iterator &p) const
{
    Iterator q = begin();
    int j = 0;

    while (q != p)
    {
        ++q;
        ++j;
    }
    return j;
}

int main()
{
    int T;
    cin >> T;

    for (int k = 0; k < T; k++)
    {
        SequenceList dl;
        SequenceList::Iterator iter = dl.begin();

        int N; // 입력 받을 자연수의 개수
        cin >> N;
        int p; // 입력 받을 자연수
        for (int i = 0; i < N; i++)
        {
            cin >> p;
            dl.insert(iter, p);
        }

        dl.convolution();
    }
}