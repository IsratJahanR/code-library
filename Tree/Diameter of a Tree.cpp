
#include<bits/stdc++.h>
#define   MOD 1000000007
using namespace std;
const int N = 100002;
vector<int>adj[N];
vector<bool>vis(N,false);
vector<int>dis(N,0);
int mm=0;
int u1;
void dfs(int node,int d=0)
{
  if(d>mm)
  {
      mm=d;
      u1=node;

  }
  vis[node]=true;
  for(auto v: adj[node])
  {
      if(!vis[v])dfs(v,d+1);
  }
}
int main()
{
    int tc=1;
    //cin>>tc;
    while(tc--)
    {
        int n,m;
        cin>>n;
        m=n-1;
        //cin>>m;
        //for(int i=1;i<=n;i++) adj[i].clear(),vis[i]=false;
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1);
        mm = 0;
        for(int i=1;i<=n;i++)vis[i]=false;
        dfs(u1);
        //cout<<u1<<endl;
        cout<<mm<<endl;


    }

}
