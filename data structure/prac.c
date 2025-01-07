#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void create(int a[],int n)
{
  int i;
  struct node *newnode= NULL,*temp = NULL;

  head = (struct node *)malloc(sizeof(struct node));
  head->data = a[0];
  head->next = NULL;
  newnode = head;

  for(i=1;i<n;i++)
  {
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a[i];
    temp->next = NULL;

    newnode->next = temp;
    newnode= temp;
  }
}
void display()
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
int Count()
{
    int c=0;
    struct node *p;
    p = head;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;

}
int main()
{
    int arr[] = {2,3,4,5};
    create(arr,4);
    display();
    int Num_of_Node = Count();
    printf("Number Of Nodes : %d",Num_of_Node);

   return 0;
}
