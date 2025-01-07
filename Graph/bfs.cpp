#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
const int         N   = (int) 2e5 + 5;

using namespace std;

bool vis[N];
vector<int>adj[N];
void bfs(int u)
{
    vis[u]=1;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
      int f = q.front();
      q.pop();

      cout << f << " ";
      for(auto x : adj[u]){
          if(!vis[x]){
              q.push(x);
              vis[x]=1;
          }
      }
    }
}
int main()
{
    int n,e,u,v;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
       cin>>u>>v;
       adj[u].pb(v);
       adj[v].pb(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])bfs(i);
    }


   return 0;
}
