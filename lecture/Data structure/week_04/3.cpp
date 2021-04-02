#include <iostream>
#include <string>
using namespace std;

class arrQ
{
private:
    int *Q;       // Queue
    int _rear;    // rear
    int _front;   // front
    int capacity; // Queue size

public:
    arrQ(int capacity);
    void enqueue(int value);
    void dequeue();
    void front();
    void rear();
    int size();
    bool isFULL();
    bool isEmpty();
};

int main()
{
    int N = 0, T = 0; //  N : Queue size, T : Test case
    cin >> N >> T;

    arrQ queue(N);

    string ins = "";
    for (int i = 0; i < T; i++)
    {
        cin >> ins;
        if (ins == "enqueue")
        {
            int val = 0;
            cin >> val;
            queue.enqueue(val);
        }
        else if (ins == "dequeue")
        {
            queue.dequeue();
        }
        else if (ins == "isEmpty")
        {
            if (queue.isEmpty() == 1)
            {
                cout << "True" << endl;
            }
            else
            {
                cout << "False" << endl;
            }
        }
        else if (ins == "size")
        {
            cout << queue.size() << endl;
        }
        else if (ins == "front")
        {
            queue.front();
        }
        else if (ins == "rear")
        {
            queue.rear();
        }
    }
}

bool arrQ::isEmpty()
{
    return _front == _rear;
}

bool arrQ::isFULL()
{
    return _front == (_rear + 1) % capacity;
}

void arrQ::front()
{
    if (isEmpty())
        cout << "Empty" << endl;
    else
        cout << Q[(_front + 1) % capacity] << endl;
}

void arrQ::rear()
{
    if (isEmpty())
        cout << "Empty" << endl;
    else
        cout << Q[_rear] << endl;
}

int arrQ::size()
{
    return (_rear - _front + capacity) % capacity;
}

void arrQ::enqueue(int value)
{
    if (isFULL())
    {
        cout << "Full" << endl;
    }
    else
    {
        _rear = (_rear + 1) % capacity;
        Q[_rear] = value;
    }
}

void arrQ::dequeue()
{
    if (isEmpty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        _front = (_front + 1) % capacity;
        cout << Q[_front] << endl;
        Q[_front] = 0;
    }
}

arrQ::arrQ(int capacity)
{
    this->capacity = capacity + 1; // 원형 큐로, 셀이 하나 더 필요
    Q = new int[this->capacity];
    _front = _rear = 0; // 처음엔 index 0에서 시작

    for (int i = 0; i < capacity; i++)
    {
        Q[i] = 0;
    }
}
