#include<bits/stdc++.h>
#define ll long long

using namespace std;


const int N = 10001;
vector<int>adj[N];
vector<int>color(N,0);

bool dfs(ll node)
{
  color[node]=1;
  for(auto v : adj[node])
  {
      if(color[v]==1)
      {
          return true;
      }
      else if(color[v]==0)
      {
          if(dfs(v))return true;
      }
  }
  color[node]=2;
  return false;
}
int main()
{
   int e,n;
    cin>>n>>e;
    while(e--)
    {
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
    }


    for(int i=1;i<=n;i++)
    {
       if(color[i]==0 && dfs(i))
        {
           cout<<"Loop Exist"<<endl;
            return 0;
        }
    }

    cout<<"Doesn't Exist Loop"<<endl;




}
