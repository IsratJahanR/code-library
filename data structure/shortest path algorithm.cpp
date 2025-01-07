#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define inf 1e7
typedef pair<int,int>P;
int vis[100000]={0};
vector<int>d(10001,inf);
priority_queue<P,vector<P>,greater<P> >pq;
vector<P>adj[10001];
vector<P>::iterator it;

void short_dis(int s)
{
  pq.push(mp(0,s));
  d[s]=0;
  while(!pq.empty())
    {
        int u;
        u = pq.top().second;
        pq.pop();
        vis[u]=1;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            int v = it->first;
            int w = it->second;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                pq.push(mp(d[v],v));
            }
        }
    }
}

int main(){
    int e,v,x,y,w;
    cin>>v>>e;
    for(int i = 1;i<=e;i++)
    {
        cin>>x>>y>>w;
        adj[x].pb(mp(y,w));
    }
    short_dis(1);
    for(int i=2;i<=v;i++)
    {
       if(d[i]==inf)cout<<"1000000000 ";
       else cout<<d[i]<<" ";
    }

    cout<<endl;
}
