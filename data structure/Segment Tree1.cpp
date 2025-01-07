#include<bits/stdc++.h>

#define ll long long
#define pb push_back
const int         MxN = (int) 1e6 + 6;

ll arr[MxN];
ll tree[MxN*3];

using namespace std;

void init(int node,int l,int r)
{
   if(l==r){
        tree[node]=arr[l];
        return;
   }
   ll l1=node*2;
   ll r1=node*2+1;
   ll mid=(l+r)/2;
   init(l1,l,mid);
   init(r1,mid+1,r);
   tree[node]=tree[l1]+tree[r1];

}
ll query(int node,int l,int r,int i,int j)
{
   if(r<i || l>j )return 0;
   else if(l>=i && r<=j)return tree[node];
   ll left = node*2;
   ll right = node*2+1;
   ll mid = (r+l)/2;
   ll p1=query(left,l,mid,i,j);
   ll p2=query(right,mid+1,r,i,j);
   return p1+p2;
}
void update(ll node,ll l,ll r,ll pos,ll val)
{
    if(r<pos || l>pos )return ;
   else if(l>=pos && r<=pos){ tree[node]=val; return ; }
   ll left = node*2;
   ll right = node*2+1;
   ll mid = (r+l)/2;
   update(left,l,mid,pos,val);
   update(right,mid+1,r,pos,val);
   tree[node]=tree[left]+tree[right];
}
int main()
{
    int tc=1,Case=1;// cin>>tc;
    while(tc--)
    {
       ll n,i,j,k,m,x1,x2,x,y;
       cin>>n>>k;

       ll a[n];
       for(i=1;i<=n;i++)
       {
           cin>>arr[i];
       }
       init(1,1,n);
       while(k--)
       {
           cin>>x>>y;
           cout<<query(1,1,n,x,y)<<endl;

       }
    }

   return 0;
}
