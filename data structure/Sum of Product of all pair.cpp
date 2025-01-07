#include<bits/stdc++.h>

#define ll long long int
#define pb push_back

using namespace std;

const int         MxN = (int) 1e6 + 6;
const ll          MOD = 1e9+7;

int main()
{
    int tc=1,Case=1;// cin>>tc;
    while(tc--)
    {
       ll n,i,j,k,m,x1,x2,x,y,sum=0,ans=0;
       cin>>n;
       ll a[n];
       for(i=0;i<n;i++)
       {
           cin>>a[i];
           ans+=(a[i]*sum);
           ans%=MOD;
           sum+=a[i];
           sum%=MOD;
       }
       cout<<ans<<endl;
    }

   return 0;
}
