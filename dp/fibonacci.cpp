#include<bits/stdc++.h>
using namespace std;
///TC: O(n)
long long getfib(int n,vector<int>&dp)
{
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=getfib(n-1,dp)+getfib(n-2,dp);
}
int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    for(int i=0;i<=n;i++)cout<<getfib(i,dp)<<endl;
}
