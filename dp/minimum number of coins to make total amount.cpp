#include<bits/stdc++.h>
using namespace std;

int dp[10004];
int fun(vector<int>& coins, int amount)
{
    if(amount==0)return 0;
    if(dp[amount]!=-1)return dp[amount];
    int ans=INT_MAX;
    for(auto c: coins)
    {
        if(amount-c>=0)
        {
            ans=min(ans+0LL,fun(coins,amount-c)+1LL);
        }
    }
    return dp[amount]=ans;
}
int main()
{
    vector<int>coins={1,2,5};
    int amount=11;
    memset(dp,-1,sizeof(dp));
    int ans=fun(coins,amount);
    // cout<<dp[3]<<endl;
    ans = (ans==INT_MAX)?-1:ans;
    cout<<ans<<endl;

}
