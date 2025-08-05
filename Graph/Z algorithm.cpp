#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define MOD 1000000007

using namespace std;

auto z_algo(string s)
{
    int sz=s.size();
    vector<int>z(sz);
    int l,r;
    l=r=0;
    z[0]=0;
    for(int i=1;i<sz;i++)
    {
        if(i>r)
        {
            l=r=i;
            while(r<sz && s[r]==s[r-l])r++;
            z[i]=r-l;
            r--;
        }
        else
        {
            int idx = i-l;
        }
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cout<<i<<" ";
        cout<<endl;
    }

}
