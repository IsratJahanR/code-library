#include<bits/stdc++.h>
using namespace std;
#define N 3

bool vis[N][N]={false};

bool isValid(int x,int y)
{
    if(x<1 || y<1 || x>N || y>N)return false;
    if(vis[x][y])return false ;

    return true;
}
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void dfs(int x,int y)
{
    vis[x][y]=1;
    cout<<x<<" "<<y<<endl;
    for(int i=0;i<4;i++)
    {
        if(isValid(x+dx[i],y+dy[i]))dfs(x+dx[i],y+dy[i]);
    }
}
int main()
{
   dfs(1,1);
}
