#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int root)
{
    int largest=root;
    int left=root*2+1;
    int right=root*2+2;
    if(left<n && a[left]>a[largest])largest=left;

    if(right<n && a[right]>a[largest])largest=right;

    if(largest!=root)
    {
        swap(a[root],a[largest]);
        heapify(a,n,largest);
    }
}
void heap_sort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    heap_sort(a,n);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;

}
