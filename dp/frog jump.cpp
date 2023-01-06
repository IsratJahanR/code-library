///Frog Jump with 1 to kth distances:
#include<bits/stdc++.h>
#define N 1000006
#define ll long long
using namespace std;
vector<int>dp(N,-1);

ll get(int n,int k,vector<int>& h)
{

    if(n==1)return dp[n]=0;
    if(n==2)return dp[n]=abs(h[1]-h[2]);

    if(dp[n]!=-1)return dp[n];
    ll mn=INT_MAX;

    int kk = min(k,n-1);
    for(int i=1;i<=kk;i++)
    {
        mn=min(get(n-i,k,h)+abs(h[n]-h[n-i]),mn);
    }

    return dp[n]=mn;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>h(n+1);
    dp.resize(n+1);
    for(int i=1;i<=n;i++)cin>>h[i];
    ll ans=get(n,k,h);
    //for(auto x:dp)cout<<x<<endl;
    cout<<dp[n]<<endl;
}
