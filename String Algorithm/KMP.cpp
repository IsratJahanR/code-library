///Knuth–Morris–Pratt (KMP): string Matching algorithm
#include<bits/stdc++.h>
using namespace std;
vector<int> createArray(string pattern)///returns lps vector:
{
    int n=pattern.size();
    vector<int>lps(n);
    int ind=0;
    for(int i=1;i<n;)
    {
        if(pattern[i]==pattern[ind])
        {
            lps[i]=ind+1;
            i++;
            ind++;
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
    return lps;
}
int KMP(string text,string pattern) ///return how many pattern are mached:
{
    int ans=0;
    vector<int>lps=createArray(pattern); ///Get lps vector
    int n1=text.size();
    int n2=pattern.size();
    int i=0;
    int j=0;
    int k=0;
    while(i<n1)
    {
       cout<<k++<<endl;
       if(text[i]==pattern[j])i++,j++;
       else
       {
           if(j) j=lps[j-1];
           else i++;
       }
       if(j==n2)
       {
           ans++;
           j=lps[j-1];
       }
    }
    return ans;
}
int main()
{
    string text,pattern;
    cin>>text>>pattern;

    int ans = KMP(text,pattern);
    cout<<ans<<endl;
}
