#include<bits/stdc++.h>
#define ll long long
#define N 1004
#define mod 1000000007
using namespace std;

int dp[N][N];
string s1,s2;

///Using tabulation approach:
void fun(string& s1,string& s2)
{
    int n=s1.size();
    int m=s2.size();

    int lcs[n+1][m+1];
    //for(int i=0;i<=n;i++)lcs[i][0]=0;
    //for(int i=0;i<=m;i++)lcs[0][i]=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)lcs[i][j]=0;
            else if(s1[i-1]==s2[j-1])  lcs[i][j]=lcs[i-1][j-1]+1;

            else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);

        }
    }

    int i=n,j=m;
    vector<char>ch;
    /*cout<<lcs[i][j]<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)cout<<lcs[i][j]<<" ";
        cout<<endl;
    }*/
    ///abcd agbd
    while(i>0 && j>0)
    {
       if(lcs[i][j]==lcs[i][j-1])j--;
       else if(lcs[i][j]==lcs[i-1][j])i--;
       else
       {
          ch.push_back(s2[j-1]);
          i--;
          j--;
       }
    }
    reverse(ch.begin(),ch.end());
    for(auto c:ch)cout<<c;
    cout<<endl;

}

///using top down approach:
int lcs(int i,int j,string& s1,string& s2)
{
    if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans =0;
    ans=max(ans,lcs(i-1,j,s1,s2));
    ans=max(ans,lcs(i,j-1,s1,s2));
    ans=max(ans,lcs(i-1,j-1,s1,s2)+(s1[i]==s2[j]));
    return dp[i][j]=ans;

}
int main()
{
      cin>>s1>>s2;
      memset(dp,-1,sizeof(dp));
      int n=s1.size();
      int m=s2.size();
      fun(s1,s2);
      //int ans=lcs(n-1,m-1,s1,s2);
      //cout<<ans<<endl;

}
