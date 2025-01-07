#include<bits/stdc++.h>
using namespace std;
void inserSort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && temp<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int main()
{
  int a[5]={2,1,5,3,6};
  inserSort(a,5);
  for(int i=0;i<5;i++)cout<<a[i]<<" ";
  cout<<endl;
}
