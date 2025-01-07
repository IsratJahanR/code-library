#include<bits/stdc++.h>
using namespace std;
#definr N 1005
vector<int<adj[N];
int level[N];
int lca[N][11];
void dfs(int node,int par,int lev)
{
    level[node]=lev;
    for(auto v: adj[node])
    {
        if(v==par)continue;
        dfs(v,node,lev+1);
    }
}
int main()
{
    int n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
