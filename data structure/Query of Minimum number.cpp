#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N =          (int) 1e6 + 6;
const ll  MxN =       (int) 1e9 + 7;
vector<ll>arr(N);
vector<ll>tree(N*3);
void init(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}
ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b)return MxN;
    if(b>=i && e<=j)return tree[node];
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;
    ll p1 = query(left,b,mid,i,j);
    ll p2 = query(right,mid+1,e,i,j);
    return min(p1,p2);

}
int main()
{

     int n,q,i;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    init(1,1,n);
    //cout<<"Case "<<Case<<":"<<endl;
    while(q--)
    {
       int l,r;
       cin>>l>>r;
       cout<<query(1,1,n,l,r)<<endl;

    }



}
