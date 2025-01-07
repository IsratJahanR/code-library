#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
///insert,search
int trie[1000005][26];
bool endnode[1000005];
int dp[5005];
int cnt=0;

void insert(string s)
{
    int curr_node=0;
    for(auto ch:s)
    {
        if(trie[curr_node][ch-'a']==0)trie[curr_node][ch-'a']=++cnt;
        curr_node=trie[curr_node][ch-'a'];
    }
    endnode[curr_node]=1;

}
int search(int x,string s)
{
    int node=0,ans=0;
    for(int i=x;i<s.size();i++)
    {
       if(trie[node][s[i]-'a']==0)return ans;
       node=trie[node][s[i]-'a'];
       if(endnode[node])ans=(ans+(dp[i+1]%M))%M;
    }
    return ans;
}
int main()
{
    insert("abc");
    insert("ade");
    for(int i=0;i<7;i++)
    {
        cout<<endnode[i]<<" ";
        //for(int j=0;j<5;j++)cout<<trie[i][j]<<" ";
        cout<<endl;
    }

   /* string s;
    cin>>s;
    int k;
    cin>>k;
    while(k--)
    {
        string ss;
        cin>>ss;
        insert(ss);

    }
    int m=s.size();
    dp[m]=1;
    for(int i=m-1;i>=0;i--)
    {
        dp[i]=search(i,s);
    }
    cout<<dp[0]<<endl;
    */

}
