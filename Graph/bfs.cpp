/*
5 4
1 3
1 4
3 5
5 2
output:
1 3 4 5 2
*/
#include<bits/stdc++.h>
#define N 200005
using namespace std;
vector<int>g[N];
bool vis[N];
void bfs(int src)
{
   queue<int>q;
   q.push(src);
   vis[src]=true;
   while(!q.empty())
   {
       int f=q.front();
       q.pop();
       cout<<f<<" ";
       for(auto v:g[f])
       {
           if(!vis[v])
           {
               vis[v]=true;
               q.push(v);
           }
       }
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
    int src=1;
    bfs(src);
}
