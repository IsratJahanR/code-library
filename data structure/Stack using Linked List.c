#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void push(int data)
{
    struct node *NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode->data = data;
    NewNode->next = NULL;

    if(head==NULL)
    {
        head = NewNode;
        return;
    }

    ///Insert At End::
    /*struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=NewNode;*/

    ///Insert At first
    NewNode->next = head;
    head=NewNode;

}
void pop()
{
   /*struct node *p=head,*prelast=head;
   while(p->next!=NULL)
   {
       prelast =p;
       p=p->next;
   }
   prelast->next=NULL;
   free(p);*/
   if(head==NULL)return ;
   head=head->next;
}
bool empty()
{
    if(head==NULL)return true;
    else return false;
}
int top()
{
    /*struct node *p=head;
    while(p->next!=NULL)p=p->next;

    return p->data;*/
    return head->data;
}
void Display()
{
    ///Print From Last to First as Insertion method:
    struct node *p=head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");

}


void PopProcedure()
{

    ///Print by top value of Stack, then pop:
    while(!empty())
    {
       printf("%d ",top());
       pop();
    }
    printf("\n");
}
int main()
{
    push(1);
    push(2);
    push(3);
    if(!empty())printf("STACK is not EMPTY\n");
    printf("Top value of StACK %d\n",top());
    printf("Pop Precedience : ");
    PopProcedure();


    return 0;
}
