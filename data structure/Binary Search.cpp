#include<bits/stdc++.h>
using namespace std;
int BinSearch(int A[],int l,int r,int k)
{
    int mid;
    while(l<=r)
    {
        //mid = l+(r-l)/2;
        mid = (l+r)/2;
        if(k==A[mid])return mid;
        if(k<A[mid])return BinSearch(A,l,mid-1,k);
        if(k>A[mid]) return BinSearch(A,mid+1,r,k);
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int k; //searched value:
    cin>>k;
    int index;
    index = BinSearch(a,0,n-1,k);
    cout<<index<<endl;
    return 0;
}
