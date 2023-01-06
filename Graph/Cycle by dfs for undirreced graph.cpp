#include<bits/stdc++.h>
using namespace std;
const int N = 10001;
vector<int>adj[N];
vector<bool>vis(N+1);
bool isCycle=false;
bool dfs(int u,int par)
{
    vis[u]=true;

    for(auto v:adj[u])
    {
        if(v==par)continue;
        if(vis[v])return true;
        isCycle=dfs(v,u);

    }
    return isCycle;
}
int main()
{
    int e,n;
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }


    for(int i=1;i<=n;i++)
    {
       if(!vis[i])
       {
           if(dfs(i,0))
           {
               cout<<"Loop Exist"<<endl;
               return 0;
           }
       }
    }

    cout<<"Doesn't Exist Loop"<<endl;




}












