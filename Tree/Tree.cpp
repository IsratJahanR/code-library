#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1001];
int depth[1001],height[1001];
void dfs(int vertex,int par=-1)
{
   for(auto child:adj[vertex])
   {
       if(child==par)continue;
       depth[child]=depth[vertex]+1;
       dfs(child,vertex);
       height[vertex]=max(height[vertex],height[child]+1);
   }
}
int main()
{
    int n,e;
    cin>>n; ///since any tree has n-1 edges.thats why we need not to declare no. of edges.
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i=1;i<=n;i++)cout<<depth[i]<<" "<<height[3]<<endl;
}
