#include<bits/stdc++.h>

using namespace std;
vector<int>adj[1004];
int vis[1004];
vector<int>ans;
void clr(int n)
{
    for(int i=0;i<=n;i++){
            adj[i].clear();
            vis[i]=0;
    }
    ans.clear();
}


void solve()
{
    int m,n,k,p;

    cin>>n>>m;

    if( (m-n==1) || ((n+1)%9 == m%9 && m<n))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;



}

int main()
{
    int t;
    cin>>t;
    while(t--)solve();

    return 0;
}
