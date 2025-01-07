/*13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11*/

#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100005];
vector<bool>vis(100005,false);

vector<int>par(100005);

 int n,mx=0,p=0,e,q=0;
 void dfs(int vertex,int parent=-1)
 {
     par[vertex]=parent;
     vis[vertex]=true;

     for(auto v : adj[vertex])
     {
         if(v!=parent)dfs(v,vertex);
     }

 }
 vector<int> path(int v)
 {
     vector<int>ans;
     while(v!=-1)
     {
         ans.push_back(v);
         v=par[v];
     }
     reverse(ans.begin(),ans.end());
     return ans;
 }

int main()
{

   cin>>n;

   for(int i=1;i<n;i++)
   {
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   dfs(1);
   int x,y;
   cin>>x>>y;
   vector<int>path_x =path(x);
   vector<int>path_y = path(y);
   int ans;
   for(int i=0;i<min(path_x.size(),path_y.size());i++)
   {
       if(path_x[i]==path_y[i])ans=path_x[i];
       else break;
   }
   cout<<ans<<endl;








}

