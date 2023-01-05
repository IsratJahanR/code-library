#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int par[N];
int Size[N];

void Make(int n)
{
    for(int i=1;i<=n;i++){
            par[i]=i;
            Size[i]=1;
    }
}
int Find(int v)
{
   if(par[v]==v)return par[v];
   return par[v]= Find(par[v]); ///Path compression:
}
void Union(int a,int b)
{
   a=Find(a);
   b=Find(b);
   if(Size[a]<Size[b])swap(a,b);
    par[b]=a;
      Size[a]+=Size[b];

}
int main()
{
    int n,e,i;
    cin>>n>>e;
    Make(n);
    for(i=0;i<e;i++)
    {
       int u,v;
       cin>>u>>v;
       Union(u,v);
    }
    int connected_comp=0;
    for(i=1;i<=n;i++)
    {
      if(Find(i)==i)connected_comp++;
    }
    cout<<connected_comp<<endl;

}
