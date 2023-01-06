#include<bits/stdc++.h>
#define ll long long
#define N 1004
#define mod 1000000007
using namespace std;

int dp[N][N];

void fun(vector<int> s1,vector<int>& s2)
{
    int n=s1.size();
    int m=s2.size();

    int lcs[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)lcs[i][j]=0;
            else if(s1[i-1]==s2[j-1])  lcs[i][j]=lcs[i-1][j-1]+1;

            else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);

        }
    }
    cout<<lcs[n][m]<<endl;



}


int main()
{
      int n,m;
      cin>>n;
      vector<int>a(n);
      for(int i=0;i<n;i++)cin>>a[i];

      cin>>m;
      vector<int>b(m);
      for(int i=0;i<m;i++)cin>>b[i];

      fun(a,b);

}
