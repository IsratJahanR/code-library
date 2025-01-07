#include<bits/stdc++.h>
using namespace std;
const int N = 20004;
vector<int>adj[N];
vector<bool>vis(N,false);
vector<int>dis(N,0);

void dfs(int node)
{
  vis[node]=true;
  for(auto v: adj[node])
  {
      if(!vis[v])dfs(v);
  }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(m!=n-1){cout<<"NO"<<endl;
    return 0;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
      if(!vis[i])
      {
          dfs(i);
          cnt++;
      }
    }
    if(cnt==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

