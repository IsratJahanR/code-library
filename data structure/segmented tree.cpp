///                      Author: Israt Jahan Reshma
///                            ID:18ICTCSE041
///                             Dept.of CSE
///                                BSMRSTU

///......................****************************............................///


#include<bits/stdc++.h>
#include<set>
#include<iostream>
using namespace std;


//.....................Keywords..................>
#define pb              push_back
#define ll              long long
#define lli             long long int
#define F               first
#define S               second
//#define mp              make_pair
#define I               insert
#define endl            '\n'
#define pob             pop_back
#define inf             1e9+9
#define setpoint(x)     setprecision(x)<<fixed

const int         N   = (int) 2e5 + 5;
const int         MxN = (int) 1e6 + 6;
const int         MOD = (int) 1e9 + 7;
const int         INF = (int) 1e9 + 9;
const double      EPS = (double) 1e-9;
const long double PI  = 3.14159265358979;
const lli M =998244353;

///.....................function..................>

#define fastio()        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define loop(a,b)       for(ll i=a;i<b;i++)
#define loopr(a,b)      for(ll i=a-1;i>=b;i--)
//#define sort(a)         sort(a.begin(),a.end())
//sort(a,a+3,greater<ll>());
#define rsort(v)        sort(v.rbegin(),v.rend())
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define yes             cout<<"YES\n";
#define no              cout<<"NO\n";
#define rev_sort(a)     sort(a.begin(),a.end(),greater<>())
#define reverse(a)      reverse(a.begin(),a.end())
#define mem(a,b)        memset(a, b, sizeof(a) )
#define max_ele(a,n)    *max_element(a,a+n)
#define min_ele(a,n)    *min_element(a,a+n)
#define print(a,n)      for(ll i=0;i<n;i++)cout<<a<<" ";
#define pll             pair <ll, ll>

ll arr[MxN];
ll tree[MxN*3];

void update(int node,int l,int r,int pos,int val)
{
    if(pos>r || pos<l)return;
    else if(pos>=r && pos<=l)
    {
        tree[node]+=val;
        return;
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(l+r)/2;
    update(left,l,mid,pos,val);
    update(right,mid+1,r,pos,val);
    tree[node]=tree[left]+tree[right];
}

ll query(int node,int l,int r,int i,int j)
{
    if(i>r || j<l)return 0;
    else if(l>=i && j>=r)return tree[node];
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(l+r)/2;
    ll p1=query(left,l,mid,i,j);
    ll p2=query(right,mid+1,r,i,j);
    return p1+p2;
}


int main(){

   	//fastio()
   	ll tc;
    cin>>tc;
    memset(tree,0,sizeof tree);

    while(tc--)
    {
        lli n,m,j,mx1=0,mx=0,mn=inf,i,res,temp=0,tmp1,tmp2,ii,nn=-1,k,sum=0,ans=0,m1,m2,x;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            update(1,1,n,i,x);
        }
        ll a,b;
        cin>>a>>b;
        cout<<query(1,1,n,a,b)<<endl;




    }
 }
