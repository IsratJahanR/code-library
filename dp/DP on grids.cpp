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
vector<string>s;
ll dp[1002][1002];

ll grid(int i,int j)
{
    if(i<0 || j<0 || s[i][j]=='#')return 0;
    if(i==0 && j==0)return 1;

    if(dp[i][j]!=-1)return dp[i][j];
    ll l = grid(i,j-1);
    l=l%mod;
    ll r = grid(i-1,j);
    r=r%mod;

    return dp[i][j]=(l+r)%mod;

}


int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        string ss;
        cin>>ss;
        s.pb(ss);
    }
    memset(dp,-1,sizeof(dp));
    ll ans = grid(n-1,m-1);
    cout<<ans<<endl;

}
