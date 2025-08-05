///Finding Longest Cycle from a connected graph:

/*

Case:1

8 9
0 1
1 2
2 3
3 4
4 5
5 1
0 6
6 7
7 0

Case:2

8 10
0 1
1 2
2 3
3 4
4 5
5 1
0 6
6 7
7 0
2 5

*/
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
void dfs(int node,int lvl=0)
    {
        dis[node]=lvl;
       vis[node]=true;
       for(auto v:adj[node])
       {
          if(vis[v]==1)
          {
              f=max(f,lvl-dis[v]+1);
          }
          else if(vis[v]==0)dfs(v,lvl+1);
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
