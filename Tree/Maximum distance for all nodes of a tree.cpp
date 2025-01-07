#include <bits/stdc++.h>
#define FIO() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define N 200005

using namespace std;

int n, x, y;
vector<int>adj[N];
int vis[N];
int d[N];
int par[N];
int  ma = INT_MIN;
int diaNode=-1;

/*
Input:
5
1 2
1 3
3 4
3 5

Output:
2 3 2 3 3

*/
void dfs(int node,int p,int dis)
{
    vis[node]=1;
    d[node]=dis;
    if(d[node]>ma)
    {
        ma=d[node];
        diaNode=node;

    }
    for(auto v:adj[node])
    {
        if(v==p)continue;
        par[v]=node;
        dfs(v,node,dis+1);
    }
}


int main(){
    FIO()

    int t=1;
    // cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(par, 0, sizeof(par));
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));

        ///Finding 1st Node:
        dfs(1,0,0);
        int node1=diaNode;

        //for(int i=1;i<=n;i++)cout<<d[i]<<" ";
        ///Finding 2nd node:
        ma=INT_MIN;
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));

        dfs(node1 , 0 , 0);
        int node2=diaNode;


        //cout<<node1<<" "<<node2<<endl;
        //for(int i=1;i<=n;i++)cout<<par[i]<<" ";

        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        dfs(node1, 0 , 0);  ///find the distance of all node from node 1

       // for(int i=1;i<=n;i++)cout<<d[i]<<" ";
       // cout<<endl;

        int d1[n+1];

        for(int i=1;i<=n;i++){ ///Copy to the nodes distance on d1 array
            d1[i]=d[i];
        }
        //for(int i=1;i<=n;i++)cout<<d[i]<<" ";
        //cout<<endl;



        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));


        dfs(node2, 0 , 0); ///find the distance of all node from node 2


       // for(int i=1;i<=n;i++)cout<<d[i]<<" ";
       // cout<<endl;

        for(int i=1;i<=n;i++){
             cout<<max(d[i], d1[i])<<" ";
         }


    }
    return 0;
}
