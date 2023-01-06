#include<bits/stdc++.h>
using namespace std;
const int N = 10001;
vector<int>adj[N];
vector<bool>vis(N+1);
vector<vector<int>>cc;
vector<int>current_cc;

int cnt=0;
void dfs(int u)
{
    vis[u]=true;
    current_cc.push_back(u);
    for(auto v:adj[u])
    {
        if(!vis[v])dfs(v);
    }
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
           current_cc.clear();
           dfs(i);
           cnt++;
           cc.push_back(current_cc);
       }
    }
    for(auto i: cc)
    {
        for(int v: i)
        {
           cout<<v<<" ";
        }
        cout<<endl;
    }
    cout<<cnt<<endl;




}











