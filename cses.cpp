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
//vector<string>s;
//ll s[100002][100002];
//ll dp[100002][100002];

ll dp[1000002];
ll fun(vector<int>& coins, int amount)
{

    if(amount==0)return 0;

    if(dp[amount]!=-1)return dp[amount];

    ll ans=INT_MAX;

    for(auto c: coins)
    {
        if(amount-c>=0)ans=min(ans,fun(coins,amount-c)+1);

    }
    return dp[amount]=ans;
}
int main()
{
    int n,amount;
    cin>>n>>amount;
    vector<int>coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];
    memset(dp,-1,sizeof(dp));
    ll ans=fun(coins,amount);
    ans=(ans==INT_MAX)?-1:ans;
    cout<<ans<<endl;


}
