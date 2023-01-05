#include<bits/stdc++.h>
#define inf 1e10
#define ll long long
using namespace std;
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


    int n,e;
    cin>>n>>e;
    ll dis[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)dis[i][j]=0;
            else dis[i][j]=inf;
        }
    }
    for(int i=1;i<=e;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=min(dis[u][v],w);
        //dis[v][u]=min(dis[v][u],w);

    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
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

}
