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
    void print();
    void find(int e);

    SequenceList::Iterator atIndex(int i) const; // index i를 갖는 원소의 위치를 반환
    int indexOf(const Iterator &p) const;        // 위치 p에 있는 원소의 index를 반환하는 함수
};

void SequenceList::print()
{
    if (empty())
        cout << "Empty" << endl;
    else
    {
        Iterator temp(begin());
        while (temp != end())
        {
            cout << temp.v->e << " ";
            ++temp;
        }
        cout << endl;
    }
}

void SequenceList::find(int e)
{
    if (empty())
        cout << "Empty" << endl;
    else
    {
        Iterator temp(begin());

        int idx = -1;

        while (temp != end())
        {
            if (temp.v->e == e)
            {
                idx = indexOf(temp);
                break;
            }
            ++temp;
        }
        if (temp.v->e == e)
        {
            idx = indexOf(temp);
        }
        cout << idx << endl;
    }
}

SequenceList::SequenceList()
{
    n = 0;
    header = new Node;
    trailer = new Node;
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

    SequenceList dl;
    SequenceList::Iterator iter = dl.begin();

    for (int i = 0; i < T; i++)
    {
        string oper;
        cin >> oper;

        if (oper == "insert")
        {
            int e;
            cin >> e;
            dl.insert(iter, e);
        }
        else if (oper == "erase")
        {
            dl.erase(iter);
        }
        else if (oper == "begin")
        {
            iter = dl.begin();
        }
        else if (oper == "end")
        {
            iter = dl.end();
        }
        else if (oper == "++")
        {
            ++iter;
        }
        else if (oper == "--")
        {
            --iter;
        }
        else if (oper == "find")
        {
            int e;
            cin >> e;
            dl.find(e);
        }
        else if (oper == "print")
        {
            dl.print();
        }
    }
}