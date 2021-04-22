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

Tree maketree(vector<int>, vector<int>);

int main()
{
    int T; // 테스트 케이스 수
    cin >> T;
    while (T > 0)
    {
        int N; // 삽입될 노드의 수
        cin >> N;
        vector<int> results;
        vector<int> depth;
        // 전위순회한 결과와 각 노드들의 깊이 입력
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            results.push_back(x);
        }
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            depth.push_back(x);
        }

        // 트리 구조 생성
        Tree tree = maketree(results, depth);
        // 후위순회
        tree.postorder(tree.root);
        cout << endl;
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
    cout << node->data << " ";
}

Tree maketree(vector<int> post, vector<int> depth)
{
    int N = post.size();
    Tree t(post[0]);

    // 일단 depth가 1인 수를 차례로 루트 아래에 삽입
    for (int i = 0; i < N; i++)
    {
        if (depth[i] == 1)
            t.insertNode(1, post[i]);
    }

    int max_depth = depth[0]; // depth의 최댓값 max_depth
    for (int i = 1; i < depth.size(); i++)
    {
        if (max_depth < depth[i])
            max_depth = depth[i];
    }

    for (int i = 1; i < max_depth; i++)
    {
        vector<int> parent; // 부모의 index
        vector<int> child;  // 자식의 index
        for (int j = 0; j < N; j++)
        {
            if (depth[j] == i)
                parent.push_back(j);
            else if (depth[j] == i + 1)
                child.push_back(j);
        }
        for (int p = parent.size() - 1; p >= 0; p--)
        {
            for (int k = 0; k < child.size(); k++)
            {
                if (parent[p] < child[k])
                {
                    t.insertNode(post[parent[p]], post[child[k]]);
                    child.erase(child.begin() + k);
                    k--;
                }
            }
        }
    }

    return t;
}