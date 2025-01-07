#include<bits/stdc++.h>
#define ll long long
const int N = 10005;

using namespace std;
int timer;
vector<int>adj[N];
vector<bool>vis(N,false);
int in[N];
int low[N];
void dfs(int node,int par=-1)
{
    vis[node]=true;
    in[node]=low[node]=timer;
    timer++;
    for(auto child: adj[node])
    {
      if(child==par)continue;
      if(vis[child]) ///having back edge:
      {
        low[node]=min(low[node],in[child]);
      }
      else
      {
          dfs(child,node);
          if(low[child]>in[node])cout<<"Bridge between : "<<node<<"->"<<child<<endl;
          low[node]=min(low[node],low[child]);
      }
    }

}



int main()
{
    int n,e;
    cin>>n>>e;
    int u,v;
    while(e--)cin>>u>>v,adj[u].push_back(v),adj[v].push_back(u);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])dfs(i);
    }


}

