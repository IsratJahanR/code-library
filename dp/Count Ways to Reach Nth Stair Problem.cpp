#include<bits/stdc++.h>
#define N 10000006
#define ll long long
#define mod 1000000007
using namespace std;



long long get(int n , vector<long long >& dp)
{

    //if(n==1)return dp[n]=1;
    if(n<=2)return dp[n]=n;

    if(dp[n]!=-1)return dp[n]%mod;
    return dp[n]=(get(n-1,dp)%mod+get(n-2,dp)%mod)%mod;

}
long long countDistinctWays(int n)
{
    vector<long long >dp(n+1,-1);
    long long ans = get(n,dp);
    return dp[n];
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<countDistinctWays(n)<<endl;
    }

}

