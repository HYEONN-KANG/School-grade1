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
private:
    Node *head;
    Node *tail;
    int n; // stack size;

public:
    linkedStack()
    {
        this->head = NULL;
        this->tail = NULL;
        this->n = 0;
    }

    int empty();
    void push(int e);
    int pop();
    int size();
};

int main()
{
    int t = 0; // 수식의 수 t
    cin >> t;

    int fir = 0;
    int sec = 0;
    string s = "";
    // int answer = 0;
    for (int i = 0; i < t; i++)
    {
        linkedStack stack;
        cin >> s;
        // something...
        for (int j = 0; (unsigned int)j < s.length(); j++)
        {
            if (s[j] - '0' >= 1 && s[j] - '0' <= 9)
            {
                // if number...
                stack.push(s[j] - '0');
            }
            else
            {
                sec = stack.pop();
                fir = stack.pop();
                // +, -, *
                if (s[j] == '+')
                {
                    stack.push(fir + sec);
                }
                else if (s[j] == '-')
                {
                    stack.push(fir - sec);
                }
                else if (s[j] == '*')
                {
                    stack.push(fir * sec);
                }
            }
        }

        cout << stack.pop() << endl;
    }
}

int linkedStack::pop()
{
    if (empty())
        return -1;
    Node *temp = head;
    head = head->next;
    n--;
    return temp->data;
}

int linkedStack::size()
{
    return n;
}

void linkedStack::push(int e)
{
    Node *newNode = new Node(e);
    if (empty())
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

int linkedStack::empty()
{
    return n == 0;
}