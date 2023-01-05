#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int l,int r)
{
    int pivot = a[r];
    int i=l,j=l;
    while(j<r)
    {
        if(a[j]<=pivot)
        {
            swap(a[i],a[j]);
            i++;
        }
        j++;
    }
    swap(a[i],a[r]);
    return i;
}
void quick_sort(int a[],int l,int r)
{
    if(l<r)
    {
        int pos=partition(a,l,r);
        quick_sort(a,l,pos-1);
        quick_sort(a,pos+1,r);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;

}
