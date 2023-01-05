#include<bits/stdc++.h>
#define N 200005
#define inf 1e18
#define ll long long

using namespace std;

vector<pair<int,int>>adj[N];
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
void Diajkstra(int src,int n)
{
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
   vector<ll>dis(n+1,inf);
   pq.push({0,src});
   dis[src]=0;
   while(!pq.empty())
   {
       int w=pq.top().first;
       int u=pq.top().second;
       pq.pop();
       for(auto x: adj[u])
       {
          int v=x.first;
          int w1=x.second;
          if(dis[v]>w+w1)
          {
              dis[v]=w+w1;
              pq.push({dis[v],v});
          }
       }
   }
   for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
   cout<<endl;
}

int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
       int u,v,w;
       cin>>u>>v>>w;
       adj[u].push_back({v,w});
       adj[v].push_back({u,w});
    }
    int src=1;
    Diajkstra(src,n);
}
