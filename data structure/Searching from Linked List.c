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
struct node* Search(int k)
{
    struct node *p=head;
   int i=1;
   while(p->next!=NULL)
   {
       if(p->data==k)return i;
       i++;
       p=p->next;
   }
   return -1;
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
    Display();
    printf("%d ",Search(2));

}

