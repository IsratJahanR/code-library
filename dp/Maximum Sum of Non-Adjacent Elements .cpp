#include<bits/stdc++.h>
#define ll long long
#define N 10004
#define mod 1000000007
using namespace std;
vector<int>a(N);
int dp[10004];
int fun(int n)
{
    if(n<0)return 0;
    if(n==0)return dp[0]=a[0];
    if(dp[n]!=-1)return dp[n];
    int n1=fun(n-1);
    int n2=fun(n-2)+a[n];
    return dp[n]=max(n1,n2);
}

int main()
{
  int n;
  cin>>n;
  memset(dp,-1,sizeof(dp));

  for(int i=0;i<n;i++)cin>>a[i];
  //cout<<dp[n-1]<<endl;

  int ans=fun(n);

  for(int i=0;i<n;i++)cout<<dp[i]<<" ";

}

