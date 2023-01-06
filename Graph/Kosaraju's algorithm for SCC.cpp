#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define pll pair<ll,ll>
#define vll vector<pll>
#define inf 1e10
#define floop(i,n) for(ll i=1;i<=n;i++)

using namespace std;

vi ar[N];
vi tr[N];
vi vis(N,0);
vi order;
vi scc;
vector<bool>isCount(N,false);
int ans=0;
void dfs(int node)
{
    vis[node]=1;
    for(auto v:ar[node])
    {
       if(!vis[v])dfs(v);

    }
    order.push_back(node);

}
void dfs1(int node)
{
    vis[node]=1;
    for(auto v: tr[node])
    {
        if(!vis[v])dfs1(v);
    }
    scc.push_back(node);
}
int main()
{
    int t,tc=1; //cin>>t;
    while(tc--)
    {
       int n,e,i;
       cin>>n>>e;
       floop(i,n)ar[i].clear(),tr[i].clear(),vis[i]=false;
       for(int i=1;i<=e;i++)
       {
           int u,v;
           cin>>u>>v;;
           ar[u].push_back(v);
           tr[v].push_back(u);
       }
       for(int i=1;i<=n;i++)
       {
           if(!vis[i])dfs(i);
       }
       floop(i,n)vis[i]=0;
       //for(auto v: order)cout<<v<<" ";
       //cout<<endl;
       for(int i=n-1;i>=0;i--)
       {
           int v=order[i];
           if(!vis[v])
           {
               scc.clear();

               dfs1(v);
               for(auto x: scc)cout<<x<<" ";
               cout<<endl;
           }
       }


    }



}

