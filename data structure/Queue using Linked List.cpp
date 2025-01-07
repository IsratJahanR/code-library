#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;
void EnQue(int Data)
{
    struct node *NewNode=NULL;
    NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode->data = Data;
    NewNode->next =NULL;

    if(tail==NULL)head = tail=NewNode;
    else
    {
        tail->next=NewNode;
        tail=NewNode;
    }
}
void DeQue()
{
    if(head==NULL)
    {
        cout<<"QUEUE is Empty "<<endl;
        return;
    }
    struct node *p=head;
    head = head->next;
    free(p);

}
void Display()
{
    struct node *p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    EnQue(1);
    EnQue(2);
    EnQue(3);
    Display();
    DeQue();
    Display();
}
