
#include<bits/stdc++.h>
#define N 200005
#define mod 1000000007
#define pb push_back
#define ll long long
#define vi vector<int>

#define pii pair<int,int>
#define vsi vector<set<pii>>
#define vii vector<pii>
#define pll pair<ll,ll>
#define vll vector<pll>
#define inf 1e10
#define floop(i,n) for(ll i=1;i<=n;i++)

using namespace std;
vector<int>adj[100005];
int dp[100005];
int vis[100005];


void dfs(int node)
{
    vis[node]=1;
    dp[node]=0;
    for(auto v:adj[node])
    {
        if(!vis[v])
        {
            dfs(v);
        }
            dp[node]=max(dp[node],dp[v]+1);

    }



}


int main()
{
    int n,m,k;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        //adj[y].push_back(x);

    }



    //memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
           dfs(i);
        }
    }
    ll ans = *max_element(dp,dp+n+1);
    cout<<ans<<endl;

}
