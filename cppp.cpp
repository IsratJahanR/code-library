
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <map>
#include<bits/stdc++.h>

//.....................Keywords..................>

#define ll long long
using namespace std;


const int N = 1e5+2;
vector<int>g[N];
long long dp[N][2];
int n,m,k;

void dfs(vector<long long> &val,int u, int par=-1)
{
    for(auto v:g[u])
    {
        if(v==par)continue;
        dfs(val,v,u);
        dp[u][0] = max(dp[u][0],dp[v][0]);
        dp[u][1] = max(dp[u][1],dp[v][1]);

    }
    val[u] += (dp[u][1]-dp[u][0]);
    int idx=0;
    int sign = 1;
    if(val[u]<0)idx++,sign=-1;
    dp[u][idx] += (sign*val[u]);
}

int main()
{

    int tc=1;
    cin>>tc;
    while(tc--)
    {
        ll l,r=0,r2,k,m,n,u,d,x,ans = 0,b=0;
        cin>>n;

        ll a[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ans = a[0];
        for(int i=1;i<n;i++)
        {
            ans &=a[i];
        }
        cout<<ans<<endl;




    }

}
