#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+10;
const ll INF=1e9+7;

vector<int>adj[N];

vector<int>ind(N,0);

void Kahn(int n)
{
    vector<int>res;
    ///priority_queue<int,vector<int>,greater<int>>q;
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)q.push(i);
    }
    while(!q.empty())
    {
        ///int curr=q.top();
       int curr=q.front();
       res.push_back(curr);
       q.pop();
       for(auto i : adj[curr])
       {
           ind[i]--;
           if(ind[i]==0)q.push(i);
       }
    }
    if(res.size()<n){
            cout<<"Sorting Doesn't Possible "<<endl;
            return;
    }
    for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
    cout<<endl;
}

int main()
{
    int tc=1; //cin>>tc;
    while(tc--)
    {
        ll n,e,k;
        cin>>n>>e;
        ll u,v,w;
        for(int i=1;i<=e;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            ind[v]++;
        }
        Kahn(n);


    }




}
