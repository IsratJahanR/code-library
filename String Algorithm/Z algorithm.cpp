#include<bits/stdc++.h>
using namespace std;
vector<int> Z_algo(string s)
{
    vector<int>z(s.size(),0);
    int i=1;
    int l=0,r=0;

    while(i<s.size())
    {
        if(i<=r)  ///সিগমেন্টে z[i] = z[i-L] থেকে কম বা সমান হতে পারে *শর্ত চেক
        {
            z[i]=min(z[i-l],r-i+1);
        }
        while(i+z[i]<s.size() && s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1>r)
        {
            r=i+z[i]-1;
            l=i;
        }

        i++;


    }
    return z;

}

int main()
{
    string s="qwertyqwertyqwerty";
    vector<int> z;
    z=Z_algo(s);
    for(auto x:z)cout<<x<<" ";
    cout<<endl;

    return 0;
}
