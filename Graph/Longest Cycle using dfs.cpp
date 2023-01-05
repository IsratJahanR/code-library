///Finding Longest Cycle from a connected graph:


#include<bits/stdc++.h>
#define N 100005
#define ll long long
#define pii pair<int,int>
#define vii vector<pii>
#define pll pair<ll,ll>
#define vll vector<pll>
#define inf 1e10

using namespace std;

int vis[100005]={0};
int dis[100005]={0};
vector<int>adj[100005];
int f=-1;
void dfs(int node,int cnt=0)
    {
        dis[node]=cnt;
       vis[node]=true;
       for(auto v:adj[node])
       {
          if(vis[v]==1)
          {
              f=cnt-dis[v]+1;
          }
          else if(vis[v]==0)dfs(v,cnt+1);
       }
       vis[node]=2;

}

void longestCycle() {
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int ans=-1;
    for(int i=0;i<n;i++)
    {
            f=-1;
            if(!vis[i])dfs(i);

            ans= max(f,ans);
    }
    cout<<ans<<endl;
}


int main()
{

longestCycle();
return 0;

}
