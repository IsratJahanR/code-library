///solution approach: Longest palindromic subsequence is longest common subsequence of given string and its reverse
#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int lps(int i,int j,string s,string r)
{
    if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    if(s[i]==r[j])ans = max(ans,lps(i-1,j-1,s,r)+1);
    ans = max(ans,lps(i-1,j,s,r));
    ans = max(ans,lps(i,j-1,s,r));
    return dp[i][j]=ans;



}
int main()
{
    string s;
    cin>>s;
    string r=s;
    reverse(r.begin(),r.end());
    int n=s.size();
    int m=r.size();
    memset(dp,-1,sizeof(dp));
    int ans = lps(n-1,m-1,s,r);
    cout<<ans<<endl;

}
