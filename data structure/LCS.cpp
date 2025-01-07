

/**
 * @author  Israt Jahan
 * https://leetcode.com/problems/longest-common-subsequence/submissions/

 */


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int LCS(string x,string y)
{
    int m=x.size();
    int n=y.size();
    int LCS_Table[m+1][n+1];
    //vector<char>ch;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)LCS_Table[i][j]=0;
            else if(x[i-1]==y[j-1])
            {
                LCS_Table[i][j]=LCS_Table[i-1][j-1]+1;
                //ch.push_back(x[i]);
            }
            else LCS_Table[i][j]=max(LCS_Table[i-1][j],LCS_Table[i][j-1]);
        }
    }
    /*for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)cout<<LCS_Table[i][j];
        cout<<endl;
    }*/
    int res = LCS_Table[m][n];
    return res;

}
int main()
{
    string s1,s2;

    //string s1="PROVIDENCE",s2="PRESIDENT";

    cin>>s1>>s2;
    int res;
    res=LCS(s1,s2);
    cout<<res<<endl;

     return 0;

}
