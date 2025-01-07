#include<bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int edit(string& s1,string& s2,int i,int j)
{
    if(i==s1.size())return s2.size()-j;
    if(j==s2.size())return s1.size()-i;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    if(s1[i]==s2[j])
    {
        return edit(s1,s2,i+1,j+1);
    }
    else
    {
        ///insert:
        int insertAns=1+edit(s1,s2,i,j+1);
        ///delete
        int deleteAns=1+edit(s1,s2,i+1,j);
        ///update
        int updateAns=1+edit(s1,s2,i+1,j+1);

        ans=min(insertAns,min(deleteAns,updateAns));

    }
   return dp[i][j]=ans;
}
int main()
{
   string s1,s2;
   cin>>s1>>s2;

   memset(dp,-1,sizeof(dp));
   cout<< edit(s1,s2,0,0);

}
