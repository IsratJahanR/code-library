#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void Create(int A[],int n)
{
    struct node *temp = NULL, *newnode = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = A[0];
    head->next =NULL;
    newnode=head;

    for(int i=1;i<n;i++)
    {
       temp = (struct node*)malloc(sizeof(struct node));
       temp->data = A[i];
       temp->next = NULL;
       newnode->next = temp;
       newnode = temp;
    }
}
void InsertBeforeFirst(int NewData)
{
    struct node *NewHead = NULL;
    NewHead = (struct node*)malloc(sizeof(struct node));
    NewHead->data = NewData;
    NewHead->next =head;
    head = NewHead;
    printf("DATA INSERTED At  SUCCESSFULLY\n");
}
void InsertAtSpecifiedNode(int position,int NewData)
{
    struct node *NewSpecified = NULL;
    NewSpecified = (struct node*)malloc(sizeof(struct node));
    NewSpecified->data = NewData;
    NewSpecified->next =NULL;

    struct node *p=head;
    int i=1;
    while(i<position)
    {
        p=p->next;
        i++;
    }

    NewSpecified->next =p->next;
    p->next=NewSpecified;

    printf("DATA INSERTED SUCCESSFULLY\n");
}
void InsertAtEnd(int NewData)
{
    struct node *NewLast = NULL;
    NewLast = (struct node*)malloc(sizeof(struct node));
    NewLast->data = NewData;
    NewLast->next =NULL;

    struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=NewLast;

    printf("DATA INSERTED SUCCESSFULLY\n");
}
void Display()
{
    struct node *p;
    p = head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    int Arr[]={1,2,3};
    Create(Arr,3);
    //InsertAtEnd(30);
    //InsertAtEnd(30);
    Display();
    InsertBeforeFirst(15);
    Display();
    InsertAtSpecifiedNode(3,114);
    Display();
    InsertAtEnd(30);
    Display();

}
