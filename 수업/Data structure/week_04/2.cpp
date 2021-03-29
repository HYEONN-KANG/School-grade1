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
    int point = 0;
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
    void plusPoint();
};

void fight(LinkedQueue, LinkedQueue);

int main()
{
    LinkedQueue P1, P2;

    int T;
    cin >> T; // 테스트 케이스의 개수

    while (T > 0)
    {
        int N = 0, x = 0, y = 0;
        cin >> N; // 카드의 개수

        for (int i = 0; i < N; i++)
        {
            cin >> x;
            P1.enqueue(x);
        }

        for (int i = 0; i < N; i++)
        {
            cin >> y;
            P2.enqueue(y);
        }

        for (int i = 0; i < N; i++)
        {
            fight(P1, P2);
        }

        if (P1.Q->point == P2.Q->point)
            cout << 0 << endl;
        else
            cout << ((P1.Q->point > P2.Q->point) ? 1 : 2) << endl;

        P1.Q->point = 0;
        P2.Q->point = 0;
        --T;
    }
}

void LinkedQueue::plusPoint()
{
    Q->point++;
}

void fight(LinkedQueue P1, LinkedQueue P2)
{
    if (P1.Q->front->data > P2.Q->front->data)
    { // P1이 이겼다면
        P1.plusPoint();
        int temp = P1.Q->front->data - P2.Q->front->data;
        P1.dequeue();
        P2.dequeue();
        if (P1.Q->front != NULL)
            P1.Q->front->data += temp;
    }
    else if (P1.Q->front->data < P2.Q->front->data)
    { // P2가 이겼다면
        P2.plusPoint();
        int temp = P2.Q->front->data - P1.Q->front->data;
        P1.dequeue();
        P2.dequeue();
        if (P2.Q->front != NULL)
            P2.Q->front->data += temp;
    }
    else
    { // 무승부라면
        P1.dequeue();
        P2.dequeue();
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