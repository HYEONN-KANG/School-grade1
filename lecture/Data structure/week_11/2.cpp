#include <iostream>
#include <string>

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
    int cnt = 0; // sub tree 노드의 개수를 저장할 변수

    BST();
    Node *search(int); // 탐색
    void insert(int);  // 삽입
    void remove(int);  // 삭제 연산
    void inorder(Node *);
    void printSub(int);
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

void BST::remove(int data)
{
    Node *node = this->search(data);
    Node *parN = node->par;

    if (node == this->root)
    { // 삭제할 노드가 루트인 경우
        if (node->left == NULL && node->right == NULL)
        { // 둘 다 없을 경우
            node = NULL;
        }
        else if (node->left == NULL && node->right != NULL)
        { // 왼쪽만 없을 경우
            node->right->par = NULL;
            this->root = node->right;
            node = NULL;
        }
        else if (node->left != NULL && node->right == NULL)
        { // 오른족만 없을 경우
            node->left->par = NULL;
            this->root = node->left;
            node = NULL;
        }
        return;
    }
    // 삭제할 노드가 루트가 아닐 경우
    else if (node->left == NULL && node->right == NULL)
    { // 둘 다 없을 경우
        if (node->data < parN->data)
        { // 노드가 왼쪽 자식일때
            parN->setLeft(NULL);
            node = NULL;
        }
        else
        { // 노드가 오른쪽 자식일때
            parN->setRight(NULL);
            node = NULL;
        }
    }
    else if (node->left == NULL && node->right != NULL)
    { // 왼쪽만 없을 경우
        if (node->data < parN->data)
        { // 노드가 왼쪽 자식일때
            parN->setLeft(node->right);
            node->right->par = parN;
            node = NULL;
        }
        else
        { // 노드가 오른쪽 자식일때
            parN->setRight(node->right);
            node->right->par = parN;
            node = NULL;
        }
    }
    else if (node->left != NULL && node->right == NULL)
    { // 오른족만 없을 경우
        if (node->data < parN->data)
        { // 노드가 왼쪽 자식일때
            parN->setLeft(node->left);
            node->left->par = parN;
            node = NULL;
        }
        else
        { // 노드가 오른쪽 자식일때
            parN->setRight(node->left);
            node->left->par = parN;
            node = NULL;
        }
    }
    else
    { //  둘다 있을 경우
        // successor을 찾는다.
        Node *temp = node->right;
        Node *successor = temp;

        while (temp != NULL)
        {
            successor = temp;
            temp = temp->left;
        }

        if (successor->right == NULL)
        { // successor의 두 자식 모두 없을 경우
            node->data = successor->data;
            if (successor->data < successor->par->data)
            { // successor가 왼쪽자식일 경우
                successor->par->setLeft(successor->right);
            }
            else
            { // success가 오른쪽 자식일 경우
                successor->par->setRight(successor->right);
            }
            successor = NULL;
        }
        else
        { // successor의 오른쪽 자식 있을 경우
            node->data = successor->data;
            // successor 삭제
            Node *parS = successor->par; // successor의 부모
            if (successor->data < parS->data)
            { // successor가 왼쪽자식일 경우
                parS->setLeft(successor->right);
            }
            else
            { // success가 오른쪽 자식일 경우
                parS->setRight(successor->right);
            }
            successor->right->par = parS;
            successor = NULL;
        }
    }
}

void BST::inorder(Node *node)
{ // 중위순회
    Node *curN = node;
    if (curN->left != NULL)
    {
        inorder(curN->left);
    }
    this->cnt++;
    if (curN->right != NULL)
    {
        inorder(curN->right);
    }
}

void BST::printSub(int data)
{
    Node *node = this->search(data);
    if (node == NULL)
    { // 해당 data를 가진 노드가 없을 경우
        cout << 0 << endl;
        return;
    }

    this->inorder(node);

    cout << this->cnt << endl;

    this->cnt = 0;
}

int main()
{
    BST tree;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        if (s == "insert")
        {
            int x;
            cin >> x;
            tree.insert(x);
        }
        else if (s == "sub")
        {
            int x;
            cin >> x;
            tree.printSub(x);
        }
        else if (s == "delete")
        {
            int x;
            cin >> x;
            tree.remove(x);
        }
    }

    return 0;
}