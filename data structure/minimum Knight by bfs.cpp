#include<bits/stdc++.h>
using namespace std;

int p,q;
int vis[10][10];
int dis[10][10];

bool isValid(int x,int y)
{
   if(x<1 || x>8 || y<1 || y>8)return false;

   if(vis[x][y])return false ;

   return true;

}
int dx[] ={1,1,2,2,-2,-2,-1,-1};
int dy[] ={-2,2,-1,1,-1,1,-2,2};
int bfs(int i,int j)
{
    queue<pair<int,int>>Q;
    Q.push({i,j});
    dis[i][j]=0;
    vis[i][j]=true;

    while(!Q.empty())
    {
        int x= Q.front().first;
        int y= Q.front().second;
        //cout<<x<<" "<<y<<endl;
        Q.pop();

        if(x==p && y==q)
        {
          return dis[x][y];
        }
        for(int k=0;k<8;k++)
        {
           int newX=x+dx[k];
           int newY=y+dy[k];
           //cout<<newX<<" "<<newY<<endl;
           if(isValid(newX,newY))
              {

                 Q.push({newX,newY});
                 dis[newX][newY]=dis[x][y]+1;
                 vis[newX][newY]=true;

              }
        }

    }
    /*cout<<"DIstance Array : "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }*/



}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        for(int i=1;i<=8;i++)
        {
          for(int j=1;j<=8;j++)vis[i][j]=false;
        }
        char c1,c2;
        int a1,a2,b1,b2;
        cin>>c1>>a1>>c2>>a2;

        b1=c1-'0'-48;
        b2=c2-'0'-48;

        p=a2;
        q=b2;
        //cout<<a1<<b1<<endl;
        cout<<bfs(a1,b1)<<endl;
    }


}

