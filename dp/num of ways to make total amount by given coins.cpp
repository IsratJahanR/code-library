
#include<bits/stdc++.h>
using namespace std;

int dp[305][10004];
int fun(int idx,vector<int>& coins, int amount)
{
    if(amount==0)return 1;
    if(idx<0)return 0;
    if(dp[idx][amount]!=-1)return dp[idx][amount];
    int ans=0;
    for(int i=0;i<=amount;i+=coins[idx])
    {
        ans+=fun(idx-1,coins,amount-i);

    }
    return dp[idx][amount]=ans;
}
int main()
{
    vector<int>coins={1,2,5};
    int amount=11;
    memset(dp,-1,sizeof(dp));
    int n=coins.size();
    int ans=fun(n-1,coins,amount);

    cout<<ans<<endl;

}
