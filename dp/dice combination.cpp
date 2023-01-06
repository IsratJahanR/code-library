#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll dp[1000006];
ll fun(int n)
{
    //cout<<n<<endl;
    if(n==0)return 1;
    if(dp[n]!=-1)return dp[n];
    ll ans =0;
    for(int i=6;i>=1;i--)
    {
        if(n>=i)
        {
           ans=(ans+fun(n-i))%mod;
        }
    }
    return dp[n]=ans;
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<fun(n)<<endl;

}
