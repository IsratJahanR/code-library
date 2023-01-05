#include<bits/stdc++.h>
#define inf 1e10
#define ll long long
using namespace std;
vector<pair<pair<int,int>,int>>edge;
/*
5 8
1 2 -1
1 3 4
2 3 3
2 5 2
2 4 2
4 3 5
4 2 1
5 4 -3

output: 0 -1 2 -2 1
*/
void Bellman_ford(int src,int n,int e)
{
    vector<ll>dis(n+1,inf);
    dis[src]=0;
    bool relax;
    for(int i=1;i<n;i++)
    {
       relax=false;
       for(auto x: edge)
       {
           int u=x.first.first;
           int v=x.first.second;
           int w=x.second;
           if(dis[u]+w<dis[v])
           {
               dis[v]=dis[u]+w;
               relax=true;
           }
       }
       if(!relax)break;
    }
    for(auto x: edge)
    {
        int u=x.first.first;
        int v=x.first.second;
        int w=x.second;
        if(dis[u]+w<dis[v])
        {
            cout<<"Have negative Cycle"<<endl;
            return;
        }
    }
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
    cout<<endl;
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({{u,v},w});

    }
    int src=1;
    Bellman_ford(src,n,e);
}
