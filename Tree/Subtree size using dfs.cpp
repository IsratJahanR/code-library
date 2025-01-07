#include<bits/stdc++.h>
#define   MOD 1000000007
using namespace std;
const int N = 20002;
vector<int>adj[N];
vector<bool>vis(N,false);
int sub[N];

/* Input:
7
1 2
2 3
2 4
3 7
4 5
4 6



*/
int dfs(int node)
{

  int curr_sub=1;
  vis[node]=true;
  for(auto v:adj[node])
  {
      if(!vis[v]){
            curr_sub+=dfs(v);

      }

  }
  sub[node]=curr_sub;
  return curr_sub;
}
int main()
{
      int n,e;
      cin>>n;
      e=n-1;
      //cin>>e;
      for(int i=1;i<=e;i++)
      {
          int u,v;
          cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
      int root=1;
      dfs(root);
      for(int i=1;i<=n;i++)cout<<sub[i]<<" ";
      cout<<endl;


}

