#include<bits/stdc++.h>

#define ll long long
#define pb push_back
const int         MxN = (int) 1e6 + 6;


using namespace std;

ll bit[MxN];

ll update(ll i,ll x)
{
    for(;i<=MxN;i+=i&(-i))bit[i]+=x;
}
ll sum(ll i)
{
    ll ans=0;
    for(;i>0;i-=i&(-i))ans+=bit[i];
    return ans;
}

int main()
{

    int tc=1,Case=1; //cin>>tc;
    while(tc--)
    {
       ll n,i,j,k,q,x,y,l,r,ans;
       cin>>n>>q;

       ll a[n];
       for(i=1;i<=n;i++)
       {
           cin>>a[i];
           update(i,a[i]);
       }
       while(q--)
       {
           cin>>l>>r;
           ans =sum(r)-sum(l-1);
           cout<<ans<<endl;

       }
    }

   return 0;
}
