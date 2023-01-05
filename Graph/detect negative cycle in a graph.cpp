#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define inf 1e18
#define ll long long
/*INPUT
5 10
1 3 1000
2 4 1000
3 5 1000
4 1 1000
5 2 1000
1 2 -2
2 3 -2
3 4 -2
4 5 -2
5 1 -2
*/
vector<pair<pair<int,int>,int>>adj;

void Bellman_ford(int src,int node,int edge)
{
    vector<ll>dis(node+1,inf);
    vector<ll>path(node+1,-1); ///for storing the path of shorting distance:
    dis[src]=0;
    int x;
    for(int i=1;i<=node;i++)
    {
        x=-1;
        for(auto p:adj)
        {
            ll u=p.first.first;
            ll v=p.first.second;
            ll w=p.second;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                x=v;
                path[v]=u;
            }
        }
       // cout<<x<<" ";
        //if(x==-1)break;
    }
    vector<int>ans;
    if(x==-1)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int y=x;
    for(int i=1;i<=node;i++)y=path[y];

   //for(int i=1;i<=node;i++)cout<<path[i]<<" ";
    x=path[y];
    ans.push_back(x);
    while(x!=y)
    {
        //cout<<x<<" ";
        ans.push_back(path[x]);
        x=path[x];
    }
    ans.push_back(path[x]);
    reverse(ans.begin(),ans.end());
    for(auto p: ans)cout<<p<<" ";
    cout<<endl;

}
int main()
{
  int n,e;
  cin>>n>>e;
  for(int i=1;i<=e;i++)
  {
      ll u,v,w;
      cin>>u>>v>>w;
      adj.push_back({{u,v},w});

  }

  Bellman_ford(1,n,e);
}
