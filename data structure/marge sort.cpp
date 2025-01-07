#include<bits/stdc++.h>
using namespace std;
void Merge(string a[],int l,int m,int r)
{
    int i,j,k;
    int n1,n2;
    n1=m-l+1;
    n2=r-m;
    string L[n1],R[n2];
    for(i=0;i<n1;i++)L[i]=a[l+i];
    for(i=0;i<n2;i++)R[i]=a[m+1+i];

    i=0; j=0; k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<R[j] && i<n1)a[k]=L[i],i++;
        else if(j<n2) a[k]=R[j],j++;
        k++;

    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;

    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;

    }
}
void merge_sort(string a[],int l,int r)
{
    if(l<r)
    {
        //cout<<l<<r<<endl;
        int mid = l+(r-l)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);
        Merge(a,l,mid,r);
    }
}
int main()
{
    string a[]={"abc","cahd","bgfd"};
    merge_sort(a,0,2);
    for(int i=0;i<3;i++)cout<<a[i]<<" ";
}
