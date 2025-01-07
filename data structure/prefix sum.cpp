#include<bits/stdc++.h>

#define ll long long
#define pb push_back
const int         MxN = (int) 1e6 + 6;


using namespace std;

ll bit[MxN];



int main()
{

    int tc=1,Case=1; //cin>>tc;
    while(tc--)
    {
       ll n,i,j,k,q,x,y,l,r,ans;
       cin>>n>>q;

       ll sum[n+1];
       sum[0]=0;
       for(i=1;i<=n;i++)
       {
           cin>>x;
           sum[i]=sum[i-1]+x;
       }
       while(q--)
       {
           cin>>l>>r;

           cout<<sum[r]-sum[l-1]<<endl;

       }
    }

   return 0;
}
