#include<bits/stdc++.h>
using namespace std;
int LSearch(int A[],int n,int k)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(A[i]==k)return i;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int k;
    cin>>k;
    int index;
    index = LSearch(a,n,k);
    cout<<index<<endl;
    return 0;
}

