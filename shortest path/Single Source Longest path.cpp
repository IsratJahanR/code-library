/*
Problem Name: High Score
Problem Link: https://cses.fi/problemset/task/1673
Author: Israt Jahan
*/

///Approach: Single source Longest Path in Graph
#include<bits/stdc++.h>
#define N 20005
#define pii pair<int,int>
#define vii vector<pii>
#define ll long long
//#define inf 1e10
const ll inf  =  1000000000000000000;
const ll ninf = -1000000000000000000;
//#define ninf inf*(-1)
using namespace std;

vector<pair<pair<int,int>,int>>adj;
ll mx = 0;
void Bellman_ford(ll src,ll node)
{
    vector<ll>dis(node+1,inf);
    dis[1]=0;
    int x,y;
    for(int i=1;i<node;i++)///for n-1 cycle
    {
      for(auto p : adj)
      {
          ll u=p.first.first;
          ll v=p.first.second;
          ll w=p.second;

          if(dis[u]==inf)continue;


          if(dis[u]+w<dis[v])dis[v]=dis[u]+w;



      }

    }
    ///detecting if there having any cycle in the path or not:
    for(int i=1;i<node;i++)
    {
      for(auto p : adj)
      {
          int u=p.first.first;
          int v=p.first.second;
          int w=p.second;

          if(dis[u]==inf)continue;


          if(dis[u]+w<dis[v])dis[v]=ninf;///more relaxation



      }

    }
    if(dis[node]==ninf)cout<<-1<<endl;
    else cout<<(-1)*dis[node]<<endl;

}
int main()
{
   int n,e;

   cin>>n>>e;

   for(int i=1;i<=e;i++)
   {
       ll u,v,w;
       cin>>u>>v>>w;
       adj.push_back({{u,v},(-1)*w});
   }
   //sort(adj.begin(),adj.end());
   Bellman_ford(1,n);
}
