#include<bits/stdc++.h>
using namespace std;

string kmp(string pattern)
{
    string s=pattern+"?";
    reverse(pattern.begin(),pattern.end());
    s+=pattern;
    int n=s.size();
    string ss="";
    vector<int>lps(n,0);
    int ind=0;
    int i=1;
    while(i<n)
    {
        if(s[i]==s[ind])
        {
            ind++;
            lps[i]=ind;
            i++;
        }
        else
        {
            if(ind)
            {
                ind=lps[ind-1];
            }
            else
            {
                lps[i]=ind;
                i++;
            }
        }
    }
    return s.substr(0,lps[n-1]);
}
int main()
{
    string s="abcbaxyz";
    cout<<kmp(s)<<endl; ///output:abcba

}

