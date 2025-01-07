#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    ///ptr = (int *)malloc(5*sizeof(int));
    ptr = (int *)calloc(5,sizeof(int));
    if(ptr==NULL)printf("Memory is not allocate");
    else printf("Memory is allocated successful");
}
