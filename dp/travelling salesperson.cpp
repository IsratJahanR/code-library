#include <bits/stdc++.h>
#define inf 1e9+7

using namespace std;

int n;
int adj[13][13];

int tsp(int idx, int mask, vector<vector<int>> &dp){

    if(mask == ((1<<(n))-1))return adj[idx][0];

    if(dp[mask][idx]!=-1)return dp[mask][idx];

    int cost=inf;

    for(int i=0; i<n; i++)
    {
        if((mask&(1<<i))==0)
        {
            cost = min(cost, tsp(i,(mask | (1<<i)), dp) + adj[idx][i]);
        }
    }

    return dp[mask][idx] = cost;
}


int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin>>adj[i][j];
            }
        }
        vector<vector<int>> dp(1<<n, vector<int> (n, -1));
        cout<<tsp(0, 1, dp)<<endl;
    }
    return 0;
}
