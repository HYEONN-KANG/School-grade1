#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *par;
    vector<Node *> chi_v;

    Node(int data)
    {
        this->data = data;
        this->par = NULL;
    }
};

class Tree
{
public:
    Node *root;
    vector<Node *> node_v;

    Tree(int);
    void insertNode(int, int);
    void preorder(Node *);
    void postorder(Node *);
};

int main()
{
    int T; // 테스트 케이스 수
    cin >> T;
    while (T > 0)
    {
        int N; // 삽입될 노드의 수
        cin >> N;
        Tree tree(1);
        for (int i = 0; i < N; i++)
        {
            int par, chi;
            cin >> par >> chi;
            tree.insertNode(par, chi);
        }

        tree.postorder(tree.root);

        --T;
    }

    return 0;
}

Tree::Tree(int data)
{
    Node *node = new Node(data);
    root = node;
    node_v.push_back(node);
}

void Tree::insertNode(int par_data, int data)
{
    for (int i = 0; i < node_v.size(); i++)
    {
        if (node_v[i]->data == par_data)
        {
            Node *node = new Node(data);
            node->par = node_v[i];
            node_v[i]->chi_v.push_back(node);
            node_v.push_back(node);
            return;
        }
    }
}

void Tree::preorder(Node *node)
{
    if (!node)
        return;

    cout << node->data << " ";
    for (int i = 0; i < node->chi_v.size(); i++)
    {
        preorder(node->chi_v[i]);
    }
}

void Tree::postorder(Node *node)
{
    if (!node)
        return;

    for (int i = 0; i < node->chi_v.size(); i++)
    {
        postorder(node->chi_v[i]);
    }
    if (node == root)
    {
        cout << 0 << endl;
        return;
    }

    cout << node->par->data << " ";
}