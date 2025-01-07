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
void DeleteFirst()
{
    struct node *p;
    p=head;
    head = p->next;
    free(p);
    printf("DATA Deleted at head SUCCESSFULLY\n");
}
void DeleteAtSpecifiedNode(int position)
{
    struct node *preNode=head;
    struct node *p=head;
    if(position==1)
    {
        head = p->next;
        free(p);
        return;
    }

    int i=1;
    while(i<position)
    {
        preNode =p;
        p=p->next;
        i++;
    }

    preNode->next =p->next;
    free(p);

    printf("DATA Deleted at specified node SUCCESSFULLY\n");
}
void DeleteAtEnd()
{
    struct node *preLast=head;
    struct node *p=head;
    while(p->next!=NULL)
    {
        preLast = p;
        p=p->next;
    }
    preLast->next=NULL;
    free(p);
    printf("DATA deleted at LAst SUCCESSFULLY\n");
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
    int Arr[]={1,2,3,4,5,6,7};
    Create(Arr,7);
    Display();
    DeleteFirst();
    Display();
    DeleteAtEnd();
    Display();
    DeleteAtSpecifiedNode(1);
    Display();

}
