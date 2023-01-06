#include<bits/stdc++.h>
using namespace std;
const int N = 1004;
vector<int>adj[N];
vector<bool>vis(N,false);
vector<int>dis(N,0);

void dfs(int src,int d=0)
{
  vis[src]=true;
  dis[src]=d;
  for(auto v: adj[src])
  {
      if(!vis[v])dfs(v,d+1);
  }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src=1;
    dfs(src);
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
    cout<<endl;
}
