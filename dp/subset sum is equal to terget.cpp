#include<bits/stdc++.h>
#include<stdio.h>
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
#define inf 1e9
#define floop(i,n) for(ll i=0;i<n;i++)
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl


using namespace std;
vector<int>a;
int dp[105][105];
bool subset_sum(int n,int target)
{
    if(target==0)return 1;
    if(n==0) return a[0]==target;
    if(dp[n][target]!=-1)return dp[n][target];
    bool notTake = subset_sum(n-1,target);
    bool take =false;
    if(target>=a[n])
    {
        take = subset_sum(n-1,target-a[n]);
    }
    return dp[n][target]=take or notTake;
}


int main()
{
    int n,target; cin>>n>>target;
    floop(i,n){
        int x;
        cin>>x;
        a.pb(x);
    }
    memset(dp,-1,sizeof(dp));
    if(subset_sum(n-1,target))yes;
    else no;

}

