#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    char ch;
    int f;
    Node *left, *right;
    Node(){
        left = NULL;
        right = NULL;
    }
    Node(char ch, int f, Node *left, Node *right) {
        this->ch = ch;
        this->f = f;
        this->left = left;
        this->right = right;
    }
    void print() {
        cout<<ch<<" "<<f<<endl;
    }
};

class cmp {
public:
bool operator() ( const Node* a, const Node* b) {
    return a->f > b->f;
}
};

void print_coding(Node *root, string code)
{
    if(root == NULL) return;
    if(root -> left == NULL && root -> right == NULL)
    {
        cout<<root->ch<<" "<<root->f<<" "<<code<<endl;
        return;
    }
    print_coding(root -> left, code + '0');
    print_coding(root -> right, code + '1');
}

int main() {

    priority_queue<Node*, vector<Node*>, cmp> pq;

    pq.push(new Node('a', 1, NULL, NULL));
    pq.push(new Node('b', 1, NULL, NULL));
    pq.push(new Node('c', 3, NULL, NULL));
    pq.push(new Node('d', 4, NULL, NULL));
    pq.push(new Node('e', 4, NULL, NULL));
    pq.push(new Node('f', 7, NULL, NULL));

    while(pq.size() != 1) {
        Node *a = pq.top();
        pq.pop();
        Node *b = pq.top();
        pq.pop();
        pq.push( new Node('_', a->f + b->f, b, a));
    }
    Node *res = pq.top();
    pq.pop();

   string code = "";
   print_coding(res, code);

    return 0;

}

