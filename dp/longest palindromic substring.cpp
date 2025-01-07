 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    int lenght(string &s,int l,int r)
    {
        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            l--;
            r++;
        }
        return r-l-1;
    }

     string longestPalindrome(string s) {
         int n=s.size();
         int ans =0;
         int strt=-1;
         for(int i=0;i<n;i++)
         {
             int ck1=lenght(s,i,i);
             int ck2=lenght(s,i,i+1);
             //cout<<i<<" "<<ck1<<" "<<ck2<<endl;
             if(ck1>ans)
             {
                 ans = ck1;
                 strt=i-ck1/2;
             }
             if(ck2>ans)
             {
                 ans = ck2;
                 strt=i-ck2/2+1;
             }

         }

         return s.substr(strt,ans);

    }
};
int main()
{
    string s;
    cin>>s;
    Solution obj;
    string ans;
    ans = obj.longestPalindrome(s);
    cout<<ans<<endl;

}
