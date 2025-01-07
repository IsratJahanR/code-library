#include<bits/stdc++.h>
#define N 101
using namespace std;

int dp[N];
int getmin(int n)
{
   if(n<=1)return 1;
   if(dp[n]!=-1)return dp[n];
   int ans =0;
   for(int i=1;i<=n;i++)
   {
      ans +=getmin(i-1)*getmin(n-i);
   }
   return dp[n]=ans;
}

int main()
{
   int n;
   cin>>n;
   memset(dp,-1,sizeof(dp));
   cout<<getmin(n)<<endl;


}
