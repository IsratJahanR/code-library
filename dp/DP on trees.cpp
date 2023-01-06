#include<bits/stdc++.h>
using namespace std;
#define N 200005

vector<int>g[N];
int subTree[N];
int vis[N];
long long dp[N];
int n;
void dfs(int node)
{
    vis[node]=1;
    subTree[node]=1;
    for(auto v: g[node])
    {
        if(!vis[v])
        {
           dfs(v);
           subTree[node]+=subTree[v];
           dp[node]+=dp[v]+subTree[v];

        }


    }

}
void dfs1(int node)
{
    vis[node]=1;
    for(auto v: g[node])
    {
        if(!vis[v])
        {
          dp[v]=dp[node]+(n-subTree[v])-subTree[v];
          dfs1(v);
        }


    }

}
int main()
{

    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    memset(vis,0,sizeof(vis));
    dfs1(1);
    for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    cout<<endl;
}
