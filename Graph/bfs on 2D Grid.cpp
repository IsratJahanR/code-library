#include<bits/stdc++.h>
using namespace std;
int m,n;
int vis[1001][1001]={false};
int dis[1001][1001];

bool isValid(int x,int y)
{
   if(x<0 || x>=n || y<0 || y>=m)return false;

   if(vis[x][y])return false ;

   return true;

}
int dx[] ={0,1,0,-1};
int dy[] ={-1,0,1,0};
void bfs(int i,int j)
{
    queue<pair<int,int>>Q;
    Q.push({i,j});
    dis[i][j]=0;
    vis[i][j]=true;

    while(!Q.empty())
    {
        int x= Q.front().first;
        int y= Q.front().second;
        Q.pop();
        for(i=0;i<4;i++)
        {
           int newX=x+dx[i];
           int newY=y+dy[i];
           if(isValid(newX,newY))
              {
                 Q.push({newX,newY});
                 dis[newX][newY]=dis[x][y]+1;
                 vis[newX][newY]=true;

              }
        }

    }
    cout<<"DIstance Array : "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }



}
int main()
{
    cin>>m>>n;
    bfs(2,2);
}
