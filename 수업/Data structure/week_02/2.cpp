#include <iostream>
#include <string>

using namespace std;

class Node
{
    int elem;
    Node *next;
    Node *prev;

    friend class D_LinkedList;
};

class D_LinkedList
{
public:
    D_LinkedList();
    int List_size();
    bool Empty();
    void Print();
    void Append(int elem);
    int Delete(int idx);
    void Print_reverse();
    void Max();

private:
    Node *head;
    Node *tail;
};

D_LinkedList::D_LinkedList()
{
    head = new Node;
    tail = new Node;

    head = NULL;
    tail = NULL;
}

bool D_LinkedList::Empty()
{
    return (head == NULL && tail == NULL); // 비어있으면 1 아니면 0을 return
}

int D_LinkedList::List_size()
{
    int list_size = 0;
    if (Empty())
    { // if empty
        return list_size;
    }

    else
    {
        Node *cur_node = head;
        while (cur_node->next != NULL)
        { // not include tail
            list_size++;
            cur_node = cur_node->next;
        }
        list_size++;
        return list_size;
    }
}

void D_LinkedList::Print()
{
    if (Empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        Node *cur_node = head;
        while (cur_node->next != NULL)
        {
            cout << cur_node->elem << ' ';
            cur_node = cur_node->next;
        }
        cout << cur_node->elem << endl;
    }
}

void D_LinkedList::Append(int elem)
{
    Node *new_node = new Node;
    new_node->elem = elem;
    new_node->next = NULL;

    if (Empty())
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail; // prev set
        tail = tail->next;
    }
    Print();
}
int D_LinkedList::Delete(int idx)
{
    int removeNum = 0;
    int cnt = 0;
    Node *cur_node;
    Node *pre_node;

    if (Empty() || List_size() <= idx)
    {
        removeNum = -1;
    }
    else if (idx == 0)
    {
        if (List_size() == 1)
        {
            removeNum = head->elem;
            tail = NULL;
            head = NULL;
        }
        else
        {
            cur_node = head;
            removeNum = cur_node->elem;
            head = cur_node->next;
            head->prev = NULL;
        }
    }
    else
    {
        pre_node = cur_node = head;
        while (cnt != idx)
        {
            pre_node = cur_node;
            cur_node = cur_node->next;
            cnt++;
        }
        removeNum = cur_node->elem;
        pre_node->next = cur_node->next;
        if (cur_node == tail)
        {
            tail = pre_node;
        }
        else
        {
            cur_node->next->prev = pre_node;
        }
    }

    return removeNum;
}

void D_LinkedList::Print_reverse()
{
    if (Empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        Node *cur_node = tail;
        while (cur_node != head)
        {
            cout << cur_node->elem << ' ';
            cur_node = cur_node->prev;
        }
        cout << cur_node->elem << endl;
    }
}

void D_LinkedList::Max()
{
    if (Empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        Node *cur_node = head;
        int Max = -10;
        while (cur_node->next != NULL)
        {
            if (cur_node->elem > Max)
            {
                Max = cur_node->elem;
            }
            cur_node = cur_node->next;
        }
        if (cur_node->elem > Max)
        {
            Max = cur_node->elem;
        }
        cout << Max << endl;
    }
}

int main()
{
    D_LinkedList DList;
    int M = 0, fir = 0, sec = 0;
    cin >> M;
    string s = "";

    for (int i = 0; i < M; i++)
    {
        cin >> s;
        if (s == "Print")
        {
            DList.Print();
        }
        else if (s == "Append")
        {
            cin >> fir;
            DList.Append(fir);
        }
        else if (s == "Delete")
        {
            cin >> fir;
            cout << DList.Delete(fir) << endl;
        }
        else if (s == "Print_reverse")
        {
            DList.Print_reverse();
        }
        else if (s == "Max")
        {
            DList.Max();
        }

        s = "";
    }
}
