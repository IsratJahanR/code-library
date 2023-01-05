#include<bits/stdc++.h>
#define N 200005
using namespace std;
vector<int>g[N];
bool vis[N];
/*
input:
5 4
1 3
1 4
3 5
5 2
output:
1 3 5 2 4
*/
void dfs(int node)
{
    vis[node]=true;
    cout<<node<<" ";
    for(auto child: g[node])
    {
        if(!vis[child])dfs(child);
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);

    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])dfs(i);
    }
}
