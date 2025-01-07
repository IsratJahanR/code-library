#include<bits/stdc++.h>
#define N 4
using namespace std;

bool isSafe(int a[N][N],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        if(a[i][col]==1)return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(a[i][j]==1)return false;
    }
    for(int i=row,j=col;i>=0 && j<N;i--,j++)
    {
        if(a[i][j]==1)return false;
    }
    return true;
}
bool MakeBoard(int a[N][N],int row)
{
    if(row>=N)return true;

    for(int i=0;i<N;i++)
    {
      if(isSafe(a,row,i))
      {
          a[row][i]=1;
          if(MakeBoard(a,row+1))return true;
          a[row][i]=0;   /// BACKTRACK
      }
    }
    return false;
}
void print(int a[N][N])
{
   for(int i=0;i<N;i++)
    {
        for(int j =0;j<N;j++)cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
void solve()
{
    int a[N][N]={0};
    if(MakeBoard(a,0))print(a);
}
int main()
{
    solve();
}

