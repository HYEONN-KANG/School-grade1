#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *par;
    Node *left;
    Node *right;

public:
    Node(int);
    void setLeft(Node *);  // 왼쪽 자식 설정
    void setRight(Node *); // 오른쪽 자식 설정

    friend class BST;
};

class BST
{
public:
    Node *root;

    BST();
    Node *search(int); // 탐색
    void insert(int);  // 삽입
    void inorder(Node *);
};

Node::Node(int data)
{ // 생성자
    this->data = data;
    this->par = NULL;
    this->left = NULL;
    this->right = NULL;
}

void Node::setLeft(Node *node)
{ // 왼쪽 자식 설정
    if (node == NULL)
        this->left = NULL;
    else
    {
        this->left = node;
        node->par = this;
    }
}

void Node::setRight(Node *node)
{ // 오른쪽 자식 설정
    if (node == NULL)
        this->right = NULL;
    else
    {
        this->right = node;
        node->par = this;
    }
}

BST::BST()
{ // 생성자
    this->root = NULL;
}

Node *BST::search(int data)
{ // 탐색, 찾으려는 노드가 있으면 그 노드를 리턴
    Node *curN = this->root;
    while (curN != NULL)
    {
        if (data == curN->data)
            return curN;
        else if (data > curN->data)
            curN = curN->right;
        else
            curN = curN->left;
    }
    return NULL;
}

void BST::insert(int data)
{ // 삽입
    Node *node = new Node(data);
    if (this->root == NULL)
    {
        this->root = node;
        return;
    }

    Node *parN = NULL;
    Node *curN = this->root;

    while (curN != NULL)
    {
        if (data > curN->data)
        {
            parN = curN;
            curN = curN->right;
        }
        else
        {
            parN = curN;
            curN = curN->left;
        }
    }

    if (data > parN->data)
        parN->setRight(node);
    else if (data < parN->data)
        parN->setLeft(node);
}

void BST::inorder(Node *node)
{ // 중위순회
    Node *curN = node;
    if (curN->left != NULL)
    {
        inorder(curN->left);
    }
    cout << curN->data << " ";
    if (curN->right != NULL)
    {
        inorder(curN->right);
    }
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        BST tree;
        int input;
        for (int j = 0; j < N; j++)
        {
            cin >> input;
            tree.insert(input);
        }

        tree.inorder(tree.root);
        cout << endl;
    }

    return 0;
}