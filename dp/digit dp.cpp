#include<bits/stdc++.h>
#include<string>
#define ll long long
using namespace std;
int dp[9][73][2];

///max 8 digit
///max sum(99999999=72)
///tight/not tight flag

int prime[21]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73};
bool isPrime(int sum)
{
    for(int i=0;i<21;i++)if(prime[i]==sum)return true;
    return false;
}
string toString(ll num)
{
    stringstream stream;
    stream << num;
    string str;
    stream >> str;
    return str;

}
int g(string str,int pos=0,int sum=0,int tight=1)
{
    if(str.size()==pos)
    {
        if(isPrime(sum))return 1;
        return 0;
    }
    else if(dp[pos][sum][tight]!=-1)return dp[pos][sum][tight];
    else if(tight)
    {

        int res=0;
        for(int i=0;i<=str[pos]-'0';i++)
        {
            if(i==str[pos]-'0')res+=g(str,pos+1,sum+i,1);
            else res+=g(str,pos+1,sum+i,0);
        }
        return dp[pos][sum][tight]=res;
    }
    else
    {
        int res=0;
        for(int i=0;i<=9;i++)
        {
            res+=g(str,pos+1,sum+i,0);
        }
        return dp[pos][sum][tight]=res;
    }
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {


      ll l,r;
      cin>>l>>r;

    memset(dp,-1,sizeof(dp));
    string b=toString(r);
    int ans1=g(b);

    memset(dp,-1,sizeof(dp));
    string a=toString(l-1);
    int ans2=g(a);
    //cout<<a<<" "<<b<<endl;

    cout<<ans1-ans2<<endl;


    }


}
