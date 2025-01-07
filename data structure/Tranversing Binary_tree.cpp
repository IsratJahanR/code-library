#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* leftNode;
    node* rightNode;

    node(int item){
        data=item;
        leftNode=NULL;
        rightNode=NULL;
    }
};
void preorder(node* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->leftNode);
    preorder(root->rightNode);
}

void inorder(node* root)
{
    if(root==NULL) return;

    inorder(root->leftNode);
    cout<<root->data<<" ";
    inorder(root->rightNode);
}
void postorder(node* root)
{
    if(root==NULL) return;

    postorder(root->leftNode);
    postorder(root->rightNode);
    cout<<root->data<<" ";
}
int main()
{
    node* root=new node(1);

    root->leftNode=new node(2);
    root->rightNode=new node(3);

    root->leftNode->leftNode=new node(4);
    root->leftNode->rightNode=new node(5);
    //root->rightNode=new node(5);
    cout<<"Preorder traversing: ";
    preorder(root);

    cout<<endl<<"inorder traversing: ";
    inorder(root);

    cout<<endl<<"Postorder traversing: ";
    postorder(root);
    cout<<endl;


}
