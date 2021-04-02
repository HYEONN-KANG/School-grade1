#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data);
};

class LinkedList
{
public:
    Node *front;
    Node *rear;
    LinkedList();
    void addEnd(int data);
    void removeFront();
};

class LinkedQueue
{
public:
    LinkedList *Q;
    int n; // 큐 안의 원소의 개수
    LinkedQueue();
    int size();          // 큐의 원소의 개수를 확인
    bool isEmpty();      // 큐가 비었는지 확인
    void _front();       // 큐의 front를 확인
    void _rear();        // 큐의 rear을 확인
    void enqueue(int e); // 큐의 맨 뒤에 원소 삽입
    void dequeue();      // 큐의 맨 앞에 원소 제거
};

int main()
{
    LinkedQueue q;

    int T; // 테스트 케이스 수
    cin >> T;

    while (T > 0)
    {
        string s = "";
        cin >> s;

        if (s == "enqueue")
        {
            int var;
            cin >> var;
            q.enqueue(var);
        }
        else if (s == "dequeue")
            q.dequeue();
        else if (s == "isEmpty")
            cout << ((q.isEmpty() == 1) ? "True" : "False") << endl;
        else if (s == "size")
            cout << q.size() << endl;
        else if (s == "front")
            q._front();
        else if (s == "rear")
            q._rear();
        T--;
    }
}

void LinkedQueue::enqueue(int e)
{
    Q->addEnd(e);
    n++;
}

void LinkedQueue::dequeue()
{
    if (isEmpty())
        cout << "Empty" << endl;
    else
    {
        Q->removeFront();
        n--;
    }
}

int LinkedQueue::size()
{
    return n;
}
bool LinkedQueue::isEmpty()
{
    return n == 0;
}
void LinkedQueue::_front()
{
    if (isEmpty())
        cout << "Empty" << endl;
    else
    {
        cout << Q->front->data << endl;
    }
}

void LinkedQueue::_rear()
{
    if (isEmpty())
        cout << "Empty" << endl;
    else
    {
        cout << Q->rear->data << endl;
    }
}

LinkedQueue::LinkedQueue()
{
    this->Q = new LinkedList();
    this->n = 0;
}

void LinkedList::removeFront()
{
    if (front != NULL)
    {
        Node *tmp = front;
        front = front->next;
        cout << tmp->data << endl;
        delete tmp;
    }
}

void LinkedList::addEnd(int data)
{
    Node *newNode = new Node(data);
    if (front == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

LinkedList::LinkedList()
{
    this->front = NULL;
    this->rear = NULL;
}

Node::Node(int data)
{
    this->data = data;
    this->next = NULL;
}