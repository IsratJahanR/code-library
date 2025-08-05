
#include<bits/stdc++.h>
#define N 100005

using namespace std;

int vis[N]={0};
vector<int>adj[N];
vector<int>temp;
bool dfs(int node,int par=-1)
{
    vis[node]=true;
    temp.push_back(node);
    for(auto v:adj[node])
    {
        if(v==par)continue;
        if(vis[v]){
                temp.push_back(v);
                return true;
        }
        else if(dfs(v,node))
        {
            return true;
        }
    }
    temp.pop_back();
     return false;
}

int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int f=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            temp.clear();
            dfs(i);
            int x=temp.size();
            int last=temp[x-1];
            vector<int>ans;
            ans.push_back(last);
            for(int j=x-2;j>=0;j--)
            {
                ans.push_back(temp[j]);
                if(temp[j]==last)break;
            }
            if(ans.size()>2)
            {
                f=1;
                cout<<ans.size()<<endl;
                for(auto v:ans)cout<<v<<" ";
                cout<<endl;
                break;
            }

        }
    }
    if(!f)cout<<"IMPOSSIBLE"<<endl;
}

