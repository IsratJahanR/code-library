#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+10;
const ll INF=1e9+7;
//vector<bool>vis(N,false);
int n,e,k;
vector<pair<int,int>>adj[N];

///Input

/*
6 9
1 2 4
1 6 2
2 3 5
2 6 1
6 3 8
6 5 10
3 4 6
3 5 3
5 4 9

output:0 3 8 14 11 2

*/
void diajkstra(int src)
{

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dis(N,INF);
    pq.push({0,src});
    dis[src]=0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for(auto v:adj[u])
        {
            int cost=v.second;
            int next_node=v.first;

            if(d+cost<dis[next_node])
            {
                dis[next_node]=d+cost;
                pq.push({dis[next_node],next_node});
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";


}


int main()
{

    cin>>n>>e;
    int u,v,w;
    for(int i=1;i<=e;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    diajkstra(1);



}
