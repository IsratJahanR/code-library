#include<bits/stdc++.h>
#define ll long long
#define N 1004
#define mod 1000000007
using namespace std;


string lcs(string& s1,string& s2)
{
    int n=s1.size();
    int m=s2.size();
    int len=0;
    int start=-1;
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])  dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=0;
            if(dp[i][j]>len)
            {
                len=dp[i][j];
                start=i-len;
            }

        }
    }
    string ans;
    ans = s1.substr(start,len);
    return ans;

}


int main()
{
      string s1,s2;
      cin>>s1;
      cin>>s2;

      string ans=lcs(s1,s2);
      cout<<ans<<endl;

}
