#include<bits/stdc++.h>
#define ll long long
#define INF 1e18
const int N = 505;
using namespace std;
ll dis[N][N];
/*
4 7
1 4 7
4 1 2
2 1 8
1 2 3
3 4 1
3 1 5
2 3 2

output:

0 3 5 6
5 0 2 3
3 6 0 1
2 5 7 0

*/
int main()
{
    ll i,j,k,n,e,u,v,w,q;
    cin>>n>>e;
    for(i=1;i<=n;i++)
    {
            for(j=1;j<=n;j++)
            {
                if(i==j)dis[i][j]=0;
                else dis[i][j]=INF;
            }
    }

    for(ll i=1;i<=e;i++)
    {
        cin>>u>>v>>w;
        dis[u][v]=min(dis[u][v],w);
        //dis[v][u]=min(dis[v][u],w);
    }

    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
              dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)cout<<dis[i][j]<<" ";
       cout<<endl;
   }
   /*cin>>q;
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        if(dis[x][y]==INF)cout<<-1<<endl;
        else cout<<dis[x][y]<<endl;
    }*/


}
