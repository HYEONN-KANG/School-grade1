#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int e)
    {
        this->data = e;
        this->next = NULL;
    }
};

class linkedStack
{
public:
    Node *head;
    Node *tail;
    int n;

    linkedStack()
    {
        this->head = NULL;
        this->tail = NULL;
        this->n = 0;
    }

    int size();
    bool empty();
    int top();
    void push(int e, int sz);
    int pop();
};

int main()
{
    linkedStack Stack;
    int t = 0; // t = stack max size
    cin >> t;
    int N = 0; // N = instruction count
    cin >> N;

    int element = 0;

    string s = ""; // input string
    for (int i = 0; i < N; i++)
    {
        cin >> s;

        if (s == "empty")
        {
            cout << Stack.empty() << endl;
        }
        else if (s == "top")
        {
            cout << Stack.top() << endl;
        }
        else if (s == "push")
        {
            cin >> element;
            Stack.push(element, t);
        }
        else if (s == "pop")
        {
            cout << Stack.pop() << endl;
        }
    }

    return 0;
}

int linkedStack::size()
{
    return n;
}

bool linkedStack::empty()
{
    return n == 0;
}

int linkedStack::top()
{
    if (empty())
        return -1;
    else
    {
        return head->data;
    }
}

void linkedStack::push(int e, int sz)
{
    Node *newNode = new Node(e);
    if (size() == sz)
        cout << "FULL" << endl;
    else if (empty())
    {
        head = tail = newNode;
        n++;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        n++;
    }
}

int linkedStack::pop()
{
    if (empty())
        return -1;
    else
    {
        Node *temp = head;
        head = head->next;
        n--;
        return temp->data;
    }
}