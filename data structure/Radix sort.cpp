   /// SUBMITTED BY: Israt Jahan Reshma
   /// Dept. CSE(SHIICT)
   ///ID: 18ICTCSE041
   ///selection _ sort

#include<bits/stdc++.h>
using namespace std;
int FindMax(int a[],int n)
{
    int max = a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)max = a[i];
    }
    return max;
}
void PassDigit(int a[],int n,int digit)
{
   int sortedArr[n],i;
   int count[10] = {0};
   //for(i=0;i<10;i++)cout<<count[i]<<" ";
   for(i=0;i<n;i++)
   {
       count[(a[i]/digit)%10]++;
       //cout<<count[(a[i]/digit)%10]<<" ";
   }
   for(i=1;i<10;i++)
   {
       count[i]+=count[i-1];
       //cout<<count[i]<<" ";
   }
   for(i=n-1;i>=0;i--)
   {
       sortedArr[count[(a[i]/digit)%10]-1]=a[i];
       count[(a[i]/digit)%10]--;
   }
   for(i=0;i<n;i++)
   {
       a[i]  = sortedArr[i];
   }
}
void RadixSort(int a[],int n)
{
    int i;
    int MaxElement = FindMax(a,n);
    //cout<<MaxElement<<endl;
    for(i=1;(MaxElement/i)>0;i*=10)
    {
      cout<<i<<endl;
      PassDigit(a,n,i);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<"Before Sorting : "<<endl;
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    RadixSort(a,n);
    cout<<"After Sorting : "<<endl;
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;


}
