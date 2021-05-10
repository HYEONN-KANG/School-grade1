#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum direction
{
    MIN = 1,
    MAX = -1
};

class Heap
{
private:
    vector<int> v;
    int heap_size;
    int root_index;
    int direction; // min, max에 따라 heap의 종류가 결정됨.

public:
    Heap(int direction)
    {
        v.push_back(-1); // dummy variable
        this->heap_size = 0;
        this->root_index = 1;
        this->direction = direction;
    }

    void swap(int idx1, int idx2)
    {
        v[0] = v[idx1];
        v[idx1] = v[idx2];
        v[idx2] = v[0];
    }

    void upHeap(int idx)
    { // for insert
        if (idx == root_index)
            return;
        else
        {
            int parent = idx / 2;
            if (v[parent] * direction > v[idx] * direction)
            {
                swap(parent, idx);
                upHeap(parent);
            }
        }
    }

    void downHeap(int idx)
    { // for remove
        int left = idx * 2;
        int right = idx * 2 + 1;
        if (right <= heap_size)
        { // 양쪽에 모두 값이 있는 경우
            // 자식을 비교하여 왼쪽 자식이 비교 대상이 되고 (자식의 값이 같은 경우 왼쪽을 비교)
            if (v[left] * direction <= v[right] * direction)
            {
                // 왼쪽 자식과 비교하여 heap 조건을 만족하지 않으면
                if (v[left] * direction < v[idx] * direction)
                {
                    swap(left, idx);
                    downHeap(left); // 왼쪽 자식노드에서 다시 downHeap
                }
                else
                    return;
            }
            else
            { // 오른쪽 자식이 더 비교대상이 되고
                // 오른쪽 자식과 자기 자신을 비교하여 heap 조건을 만족하지 않으면
                if (v[right] * direction < v[idx] * direction)
                {
                    swap(right, idx);
                    downHeap(right); // 오른쪽 자식노드에서 다시 downHeap
                }
                else
                    return;
            }
        }
        else if (left <= heap_size)
        { // 왼쪽에만 값이 있는 경우
            // 자신과 비교하여 자식의 값이 작으면
            if (v[left] * direction < v[idx] * direction)
            {
                swap(left, idx);
                downHeap(left); // 자식 노드에서 다시 downHeap을 함.
            }
            else
                return;
        }
        else
            return; // 양쪽 모두 없는 경우 finish
    }

    void insert(int e)
    {
        v.push_back(e);
        heap_size++;
        upHeap(heap_size);
    }

    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            int top = v[root_index];
            v[root_index] = v[heap_size];
            heap_size--;
            v.pop_back();
            downHeap(root_index);
            return top;
        }
    }

    int top()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return v[root_index];
        }
    }
    int size() { return heap_size; }
    bool isEmpty() { return heap_size == 0; }

    void print()
    {
        if (isEmpty())
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 1; i <= size(); i++)
            {
                cout << v.at(i) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Heap heapPQ(MAX);

    int T;
    cin >> T;
    string s;

    for (int i = 0; i < T; i++)
    {
        cin >> s;
        if (s == "insert")
        {
            int k;
            cin >> k;
            heapPQ.insert(k);
        }
        else if (s == "size")
        {
            cout << heapPQ.size() << endl;
        }
        else if (s == "isEmpty")
        {
            cout << heapPQ.isEmpty() << endl;
        }
        else if (s == "pop")
        {
            cout << heapPQ.pop() << endl;
        }
        else if (s == "top")
        {
            cout << heapPQ.top() << endl;
        }
        else if (s == "print")
        {
            heapPQ.print();
        }
    }
}