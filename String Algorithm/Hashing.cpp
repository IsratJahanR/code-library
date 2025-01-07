#include<bits/stdc++.h>
#define mod 1000000007
#define N 1000006
#define ll long long
using namespace std;

ll dp[N];
ll p[N];
ll bigMod(ll base,ll pow)
{
    ll res=1;
    while(pow)
    {
        if(pow%2)res=(res*base)%mod,pow--;
        else base=(base*base)%mod,pow/=2;
    }
    //cout<<res<<endl;
    return res;
}
void Hash(string s)
{
    int n=s.size();
    p[0]=1;
    dp[0]=s[0]-'a'+1;
    //cout<<dp[0]<<endl;
    ll base=29;
    ll power=1;
    for(int i=1;i<n;i++)
    {
        int value=s[i]-'a'+1;
        power=(base*power)%mod;
        p[i]=bigMod(power,mod-2);
        dp[i]=(dp[i-1]+(value*power)%mod)%mod;
       // cout<<dp[i]<<" ";

    }
}
ll getHash(int l,int r)
{
    //cout<<dp[l]<<" "<<dp[r]<<endl;
    if(l==0)return dp[r];
    ll ans =dp[r]-dp[l-1]+mod;

    return ((ans*p[l]))%mod;

}
int main()
{
    string s;
    cin>>s;
    Hash(s);
    //for(int i=0;i<s.size();i++)cout<<dp[i]<<" ";
    //cout<<endl;
    int strt=0;
    int n=s.size();
    for(int i=0;i<n-1;i++)
    {
        ll sufix=getHash(0,i);
        ll prefix=getHash(n-i-1,n-1);
        //cout<<sufix<<" "<<prefix<<endl;
        if(sufix==prefix)
        {
            int j=1;

           for(int k=i+1;k<n-1;k++)
           {
              ll midfix=getHash(j,k);
              if(sufix==midfix)
              {
                  strt=i+1;
                  break;
              }
              j++;
           }
        }
    }
    if(strt)cout<<s.substr(0,strt)<<endl;
    else cout<<"Just a legend"<<endl;


    return 0;
}
