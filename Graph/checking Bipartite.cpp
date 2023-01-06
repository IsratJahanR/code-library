///  Israt Jahan Reshma
///  ID: 18ICTCSE041
///  BSMRSTU
///****************************\\\


#include<bits/stdc++.h>

using namespace std;

typedef long long           ll;

const int         N   = (int) 2e5 + 5;

#define pb              push_back



bool vis[N];
vector<int>adj[N];
int clr[N];

bool dfs(int u){
	vis[u]=1;
	for(auto i : adj[u])
    {
        if(clr[i]==clr[u])return false;
        if(!vis[i]){
                clr[i]=clr[u]^1;
                if(!dfs(i))return false;
        }
    }
    return true;
}

void solve()
{
   ll i,x,y,e,v,u,n;
   cin>>n>>e;
   for(i=0;i<e;i++)
   {
       cin>>u>>v;
       adj[u].pb(v);
       adj[v].pb(u);
   }
   clr[1]=1;
   if(dfs(1))cout<<"Bipartite"<<endl;
   else cout<<"Not Bipartite"<<endl;

}

int main()
{

    memset(clr,-1,sizeof(clr));
    solve();
    return 0;

}
