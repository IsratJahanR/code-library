#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    char ch;
    int fr;
    Node *l,*r;
    Node()
    {
        l=NULL;
        r=NULL;
    }
    Node(char c,int f,Node *left,Node *right)
    {
        ch=c;
        fr=f;
        l=left;
        r=right;
    }
    void print()
    {
        cout<<ch<<" "<<fr<<endl;
    }
};
class compare
{
public:
    bool operator()(const Node *left , Node *right)
    {
        return left->fr > right->fr;
    }
};
void massagePrint(Node *root,string code)
{
    if(root==NULL)return;
    if(root->l ==NULL && root->r==NULL)
    {
        cout<<root->ch<<" "<<root->fr<<" "<<code<<endl;
        return;
    }
    massagePrint(root->l,code+'0');
    massagePrint(root->r,code+'1');
}
int main()
{
    priority_queue<Node*, vector<Node*>,compare>P;
    P.push(new Node('a', 1, NULL, NULL));
    P.push(new Node('b', 1, NULL, NULL));
    P.push(new Node('c', 3, NULL, NULL));
    P.push(new Node('d', 4, NULL, NULL));
    P.push(new Node('e', 4, NULL, NULL));
    P.push(new Node('f', 7, NULL, NULL));

    while(P.size()!=1)
    {
        Node *a = P.top();
        P.pop();
        Node *b =P.top();
        P.pop();
        P.push(new Node(' ',a->fr+b->fr,a,b));
    }
    Node* root = P.top();
    P.pop();

    massagePrint(root,"");

}
