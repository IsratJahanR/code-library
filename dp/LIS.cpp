#include<bits/stdc++.h>
#define N 10004

using namespace std;

int dp[N];
int lis(int i,vector<int>& a)
{
    //if(i==0)return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=1;

    for(int j=0;j<i;j++)
    {
        if(a[j]<a[i])
        {
            ans= max(ans,lis(j,a)+1);
        }
    }
    return dp[i]=ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>arr[i];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(lis(i,arr),ans);
    }
    cout<<ans<<endl;



    return 0;
}
