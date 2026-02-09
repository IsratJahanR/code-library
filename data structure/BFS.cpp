#include<bits/stdc++.h>
using namespace std;
vector<int> adjcent[100];
int vertex,edge;
bool visited[100]={false};

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
       adjcent[n1].push_back(n2);
       adjcent[n2].push_back(n1);

    }
}
void bfs(int node)
{
    visited[node] = true;
    queue<int> q;
    q.push(node);

    while(!q.empty())
    {
        int temp = q.front();
        cout<<temp<<" ";
        q.pop();
        for(int i=0;i<adjcent[temp].size();i++)
        {
            if(visited[adjcent[temp][i]]==false)
            {
                q.push(adjcent[temp][i]);
                visited[adjcent[temp][i]]=true;
            }
        }

    }


}
int main()
{
    graph_inp();
    for(int i=1;i<=vertex;i++)
    {
        if(visited[i]==false)bfs(i);
    }
    return 0;
}

