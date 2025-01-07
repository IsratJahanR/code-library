#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define MOD 1000000007

using namespace std;
ll dp[N];
ll inv[N];
ll Pow(ll b,ll p)
{
    ll res=1;
    while(p)
    {
         if(p%2)res=(res*b)%MOD,p--;
         else b = (b*b)%MOD,p/=2;
    }
    return res;

}
void getHash(string s)
{
    ll p=1;
    ll power=31;
    dp[0]=s[0]-'a'+1;
    inv[0]=1;
    for(int i=1;i<s.size();i++)
    {
        int val=s[i]-'a'+1;
        p=(p*power)%MOD;
        ll temp=(val*p)%MOD;

        dp[i]=(dp[i-1]+temp)%MOD;

        inv[i]=Pow(p,MOD-2);

    }
    //return ans;
}
ll subString(ll l,ll r)
{
    ll res=dp[r];
    if(l>0)res-=dp[l-1];
    res=(res*inv[l])%MOD;
    return res;
}
int main()
{
    int t=1,i; cin>>t;
    string s;
    cin>>s;
    getHash(s);
    while(t--)
    {
        ll n,e,k,ans=0;
        ll l,r;
        cin>>l>>r;
        cout<<subString(l,r)<<endl;

    }


}
