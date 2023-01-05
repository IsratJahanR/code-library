#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5+10;

int par[N], Size[N];

///DSU---->Count connected components:
/* Inputs:
5 5
1 2
2 3
1 3
4 5
5 4
*/
void Make(int n)
{
    for(int i=0;i<=n;i++){
            par[i]=i;
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
  if(a!=b)par[a]=b;

}

int main()
{
    int n,e;
    cin>>n>>e;
    Make(n);
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    int cc=0;
    for(int i=1;i<=n;i++)
    {
       if(Find(i)==i)cc++;///counts how many roots having their own parenting:
    }
    cout<<cc<<endl;



}


