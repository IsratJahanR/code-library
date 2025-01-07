#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool vis[N]={false};
vector<int> adj[N];
int vertex,edge;
void graph_inp()
{
    cout<<"Number of vertex : ";
    cin>>vertex;

    cout<<"Number of edge : ";
    cin>>edge;

    int n1,n2;
    for(int i=0;i<edge;i++)
    {
       cin>>n1>>n2;
       adj[n1].push_back(n2);
       adj[n2].push_back(n1);

    }
}
void dfs(int node)
{
    //vis[node]=true;

    stack<int> stk;
    stk.push(node);

    while(!stk.empty())
    {
        //cout<<temp<<" ";
        int last = stk.top();
        stk.pop();
        if(!vis[last])
        {
            cout<<last<<" ";
            vis[last] = true;

        //int v;
        for(int i=adj[last].size()-1;i>=0;i--)
        {
            if(!vis[adj[last][i]])stk.push(adj[last][i]);
        }
        }

    }

    ///PreOrder:


}

int main()
{
    graph_inp();
    for(int i=1;i<=vertex;i++)
    {
        if(vis[i]==false)dfs(i);
    }
    return 0;
}
