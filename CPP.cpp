
///Israt Jahan Reshma
///ID: 18CSE241
///BSMRSTU

#include<bits/stdc++.h>
#include<stdio.h>
#include<unordered_set>

using namespace std;


//.....................Keywords..................>
#define ll              long long
#define lli             long long int
#define ull             unsigned long long
#define ld              long double
#define vi              vector<int>
#define vll             vector<ll>
#define pii             pair<int,int>
#define vii             vector<pii>
#define tiii            tuple<int,int,int>
#define pb              push_back
#define F               first
#define S               second
#define MP              make_pair
#define I               insert
#define endl            "\n"
#define pob             pop_back
#define inf             1e9+9
#define setpoint(x)     setprecision(x)<<fixed
#define pi              acos(-1)

const int         N   = (int) 2e3 + 5;//100000
const int         MxN = (int) 1e6 + 5;
const int         MOD = (int) 1e9 + 7;
const int         INF = (int) 1e9 + 7;
const double      EPS = (double) 1e-9;
const long double PI  = 3.14159265358979;
const lli         M   =  1e6+2;  //998244353;

///.....................function..................>

#define fastio()        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define loop(a,b)       for(ll i=a;i<b;i++)
#define loopr(a,b)      for(ll i=a-1;i>=b;i--)
#define Ssort(a)         sort(a.begin(),a.end())
//sort(a,a+3,greater<ll>());
#define rsort(v)        sort(v.rbegin(),v.rend())
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define rev_sort(a)     sort(a.begin(),a.end(),greater<int>())
#define rev(a)      reverse(a.begin(),a.end())
#define sum_arr(a,n,s)  accumulate(a,a+n,s)
#define bin_one(n)      __builtin_popcount(n)
#define str(a)          a.begin(),a.end()
#define mem(a,b)        memset(a, b, sizeof(a) )
#define max_ele(a,n)    *max_element(a,a+n)
#define min_ele(a,n)    *min_element(a,a+n)
#define print(a,n)      for(ll i=0;i<n;i++)cout<<a<<" ";
#define pll             pair <ll, ll>
#define yes             cout<<"yes\n"
#define YES             cout<<"YES\n"
#define no              cout<<"no\n"
#define NO              cout<<"NO\n"
#define read(x)         int x; cin >> x


vector<int>prm[1005];
int vs[N+2];
vector<ll>prime;
void sieve()
{
    prime.push_back(2);
    for(int i=3; i*i<=N; i+=2)
    {

        if(!vs[i])
        {
            for(int j=i*i; j<=N; j+=i)
            {
                vs[j]=1;
            }
        }
    }
    for(int i=3; i<=N; i+=2)if(!vs[i])prime.push_back(i);
}
vector<pair<int,int>> getfact(int n)
{
    int i=0;
    int idx=n;
    vector<pair<int,int>>ans;
    while(prime[i]<=n && i<prime.size())
    {
        if(n%prime[i]==0 && prime[i]!=idx)
        {
            int tmp=0;
            //prm[idx].push_back(prime[i]);//
            //ans.push_back(prime[i]);
            while(n%prime[i]==0)
            {
                n/=prime[i];
                tmp++;
            }

            ans.push_back({tmp,prime[i]});


        }
        i++;
    }
    if(n>1)ans.push_back({1,n});

    return ans;



}


int grid[1005][1005];
int vis[1005][1005];
int curr_row;
int curr_col;
bool isValid(int i,int j,int n,int m)
{
    if((i==curr_row || i==n) && j>=curr_col && j<=m && !vis[i][j])return true;
    if((j==curr_col || j==m) && i>=curr_row && i<=n && !vis[i][j])return true;
    return false;
}
int dx[]= {0,1,0,-1};
int dy[]= {1,0,-1,0};
int vis_cnt=0;

void dfs(int i,int j,int n,int m,vector<int>&tmp)
{
    vis[i][j]=1;
    tmp.push_back(grid[i][j]);
    //cout<<grid[i][j]<<endl;
    for(int k=0; k<4; k++)
    {
        int x=dx[k]+i;
        int y=dy[k]+j;
        if(isValid(x,y,n,m))
        {
            dfs(x,y,n,m,tmp);
        }
    }

}


//vector<bool>vis(N,false);
int n,e,k;
vector<pair<int,int>>adj[N];
void diajkstra(int src)
{

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dis(N,INF);
    pq.push({0,src});
    dis[src]=0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for(auto v:adj[u])
        {
            int cost=v.second;
            int next_node=v.first;

            if(d+cost<dis[next_node])
            {
                dis[next_node]=d+cost;
                pq.push({dis[next_node],next_node});
            }
        }
    }
    if(dis[n]==INF)cout<<"Impossible"<<endl;
    else cout<<dis[n]<<" ";


}
void clean()
{
    for(int i=0;i<=n;i++)
    {
        adj[i].clear();
    }
}
int cas=1;
void solve()
{
    lli nn,mm,ans=0,i=0,j=0,sum=0,mn=INT_MAX,l,k,kk=0,mx=0,x=0,y=1,res=0,r,m1=0,m2=0;
    //ll n,m = 1;
    cin>>n>>e;
    clean();
    int u,v,w;
    for(int i=1;i<=e;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cout<<"Case "<<cas++<<": ";
    diajkstra(1);

}
int main()
{

    //fastio()
    int t=1;
    cin>>t;

    //sieve();
    while(t--)
    {

        solve();

    }

    return 0;
}
