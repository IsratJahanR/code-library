#include<bits/stdc++.h>
using namespace std;

void pass_digit(int a[],int n,int digit)
{
    int sorted[n];
    int cnt[10]={0};
    for(int i=0;i<n;i++)
    {
        cnt[(a[i]/digit)%10]++;
    }
    for(int i=1;i<10;i++)cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--)
    {
        sorted[--cnt[(a[i]/digit)%10]]=a[i];
    }
    for(int i=0;i<n;i++)a[i]=sorted[i];
}
void radix_sort(int a[],int n)
{
    int mx=0;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,a[i]);
    }
    for(int i=1;mx/i>0;i*=10)
    {
        pass_digit(a,n,i);
    }

}
int main()
{
    int arr[]={103,6785,10002,13,7};
    radix_sort(arr,5);
    for(int i=0;i<5;i++)cout<<arr[i]<<" ";
    cout<<endl;

}

