#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *par;            // 부모노드
    vector<Node *> chi_v; // 자식노드를 저장할 벡터

    Node(int data)
    {
        this->data = data;
        this->par = NULL;
    }
};

class Tree
{
public:
    Node *root;            // 루트 노드
    vector<Node *> node_v; // 모든 노드를 저장할 벡터

    Tree(int);
    void insertNode(int, int);
    void delNode(int);
    void printChi(int);
    void printPar(int);
    void printDepth(int);
    void printLevel(int);
};

Tree::Tree(int data)
{
    Node *node = new Node(data);
    this->root = node;
    this->node_v.push_back(node);
}

void Tree::insertNode(int par_data, int data)
{
    Node *node = new Node(data);
    for (unsigned int i = 0; i < node_v.size(); i++)
    {
        if (node_v[i]->data == par_data)
        {
            node_v[i]->chi_v.push_back(node);
            node_v.push_back(node);
            node->par = node_v[i];
            return;
        }
    }
    cout << -1 << endl;
}

void Tree::delNode(int data)
{
    Node *curNode;
    Node *parNode;
    for (unsigned int i = 0; i < node_v.size(); i++)
    {
        if (node_v[i]->data == data)
        {
            if (node_v[i] == root)
            {
                cout << -1 << endl;
                return;
            }

            // 자식 노드들을 부모 노드의 chi_v에 넣기
            curNode = node_v[i];
            parNode = curNode->par;
            for (Node *child : curNode->chi_v)
            {
                parNode->chi_v.push_back(child);
                child->par = parNode;
            }

            // 현재 노드에서 삭제할 노드 삭제
            for (unsigned int j = 0; j < parNode->chi_v.size(); j++)
            {
                if (parNode->chi_v[j]->data == data)
                    parNode->chi_v.erase(parNode->chi_v.begin() + j);
            }

            // node_v에서 삭제
            node_v.erase(node_v.begin() + i);
            delete curNode;
            return;
        }
    }
    cout << -1 << endl;
}

void Tree::printChi(int data)
{
    for (unsigned int i = 0; i < node_v.size(); i++)
    {
        if (node_v[i]->data == data)
        {
            if (node_v[i]->chi_v.empty())
            {
                cout << -1 << endl;
                return;
            }
            for (Node *child : node_v[i]->chi_v)
            {
                cout << child->data << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
}

void Tree::printPar(int data)
{
    for (unsigned int i = 0; i < node_v.size(); i++)
    {
        if (node_v[i]->data == data)
        {
            if (node_v[i] == root)
            {
                cout << -1 << endl;
                return;
            }
            cout << node_v[i]->par->data << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    int N;
    cin >> N;

    Tree T(1);

    for (int i = 0; i < N; i++)
    {
        string oper;
        cin >> oper;
        if (oper == "insert")
        {
            int x, y;
            cin >> x >> y;
            T.insertNode(x, y);
        }
        else if (oper == "delete")
        {
            int x;
            cin >> x;
            T.delNode(x);
        }
        else if (oper == "print")
        {
            int x;
            cin >> x;
            T.printChi(x);
        }
    }

    return 0;
}