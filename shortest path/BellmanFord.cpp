#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define inf 1e18
#define ll long long



/*INPUT
5 8
1 2 -1
1 3 4
2 3 3
2 5 2
2 4 2
4 3 5
4 2 1
5 4 -3

*/
vector<pair<pair<int,int>,int>>adj;

void Bellman_ford(int src,int node,int edge,int des)
{
    vector<ll>dis(node+1,inf);
    vector<ll>d(node+1,-1); ///for storing the path of shorting distance:
    dis[src]=0;
    bool any_relux;
    for(int i=1;i<node;i++) ///check n-1 node
    {
        any_relux=false;
        for(auto p:adj)
        {
            int u=p.first.first;
            int v=p.first.second;
            int w=p.second;
            if(dis[u]!=inf && dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                any_relux=true;
                d[v]=u;
            }
        }
        if(!any_relux)break;
    }
    /*vector<int>path;
    if(dis[des]!=inf)
    {
        path.push_back(des);
        int i=des;
        while(d[i]!=-1)
        {
          path.push_back(d[i]);
          i=d[i];
        }
        reverse(path.begin(),path.end());
        for(auto x :path)cout<<x<<" ";
        cout<<endl;
        return ;
    }*/
    for(int i=1;i<=node;i++)cout<<dis[i]<<" ";
    cout<<endl;
    //cout<<" NO path from source to distance"<<endl;

}
int main()
{
  int n,e;
  cin>>n>>e;
  for(int i=1;i<=e;i++)
  {
      int u,v,w;
      cin>>u>>v>>w;
      adj.push_back({{u,v},w});

  }
  int destination = 3;///finding shortest distance from node 1 to 3
  Bellman_ford(1,n,e,destination);
}
