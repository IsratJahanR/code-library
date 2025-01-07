#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5+10;

int par[N], Size[N];

///DSU---->
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
   if(a!=b)
   {
        if(Size[a]<Size[b])swap(a,b);
        par[b]=a;
        Size[a]+=Size[b];
   }

}

int main()
{
    int n,e,i,x;
    cin>>n>>e;
    Make(n);
    vector<pair<int,pair<int,int>>> edg;
    int u,v,w;
    for(i=0;i<e;i++)
    {
       cin>>u>>v>>w;
       edg.pb({w,{u,v}});
    }

    sort(edg.begin(),edg.end());


    int min_cost=0;
    for(auto &p : edg)
    {
       w= p.first;
       u=p.second.first;
       v=p.second.second;
       if(Find(u)!=Find(v))
       {
          Union(u,v);
          //cout<<u<<" "<<v<<" "<<w<<endl;
          min_cost+=w;
       }
    }
      cout<<min_cost<<endl;

}

