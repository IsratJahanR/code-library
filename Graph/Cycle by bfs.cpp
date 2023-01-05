#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<bool>vis(N+1);
vector<int>adj[N];
int parent[N+1];

int main()
{

    int n,e;
    cin>>n>>e;
    memset(parent,-1,sizeof(parent));
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int flag=0;
    int s=1;
    vis[s]=true;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(auto v:adj[u])
        {
           if(vis[v]==true && parent[u]!=v)
           {
               flag=1;
               break;
           }
           if(vis[v]==false)
           {
               parent[v]=u;
               vis[v]=true;
               Q.push(v);
           }
        }
    }
    if(flag)cout<<"Cycle"<<endl;
    else cout<<"NO Cycle"<<endl;
}
