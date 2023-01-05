#include<bits/stdc++.h>
#define N 100
using namespace std;
int dp[N][N];
int lcs(string& s1,string& s2,int i,int j)
{
    if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans =0;
    ans = max(ans,lcs(s1,s2,i-1,j));
    ans = max(ans,lcs(s1,s2,i,j-1));
    ans = max(ans,lcs(s1,s2,i-1,j-1)+(s1[i]==s2[j]));
    return dp[i][j]= ans;

}
void lcs1(string& s1,string& s2,int n,int m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)dp[i][j]=0;
            else if(s1[i]==s2[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

}
int main()
{
    string s1="PBCWEDEUY",s2="KXBWDUYL";
    //cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    memset(dp,-1,sizeof(dp));
    //int ans=lcs(s1,s2,n-1,m-1);
    lcs1(s1,s2,n,m);
    //cout<<dp[n][m]<<endl;


    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    string res ="";
    int i=n-1,j=m-1;
    while(i>0 && j>0)
    {
       if(j>0 && dp[i][j]==dp[i][j-1])j--;
       else if(i>0 && dp[i][j]==dp[i-1][j])i--;
       else res.push_back(s1[i]),i--,j--;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;


}
