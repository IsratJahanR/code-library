#include<bits/stdc++.h>
using namespace std;

void Count(int a[],int n)
{
    int k=0;
    for(int i=0;i<n;i++)k=max(a[i],k);
    //cout<<k<<endl;
    int cnt[k+1];
    for(int i=0;i<=k;i++)cnt[i]=0;
    for(int i=0;i<n;i++)
    {
        cnt[a[i]]++;
    }
    // for(int i=0;i<=k;i++)cout<<cnt[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=k;i++)
    {
        cnt[i]+=cnt[i-1];
    }
    //for(int i=0;i<=k;i++)cout<<cnt[i]<<" ";
    int b[n];
    for(int i=n-1;i>=0;i--)
    {
        b[--cnt[a[i]]]=a[i];

    }
    for(int i=0;i<n;i++)a[i]=b[i];
    //for(int i=0;i<n;i++)cout<<a[i]<<" ";
}

int main()
{

    int arr[]={2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9};
    Count(arr,17);
    for(int i=0;i<17;i++)cout<<arr[i]<<" ";
    cout<<endl;

}

