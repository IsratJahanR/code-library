#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
//#define N 100005
class Trie {
    public:
        Trie *ch[26] = {};
        int visited = 0;
};
class Solution1 {
public:
    const long long int mod=1e18;
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        int n=words.size();
        vector<int>ans;
        for (auto s: words)
        {
            auto t = &trie;
            for (auto c: s)
            {
                if(!t->ch[c-'a'])t->ch[c-'a']=new Trie();
                t->ch[c-'a']->visited++;
                t=t->ch[c-'a'];
            }
        }
        for (auto s: words)
        {
            auto t = &trie;
            int cnt=0;
            for (auto c: s)
            {

                cnt+=t->ch[c-'a']->visited;
                t=t->ch[c-'a'];
            }
            ans.push_back(cnt);
        }
        return ans;

    }
};


class Solution111 {

    ///With KMap Algorithm:
public:

    vector<int> kmp(string s)
    {

        //reverse(s.begin(),s.end());
        int n= s.size();
        vector<int>lps(n,0);
        int i=1,idx=0;
        while(i<n)
        {
            if(s[i]==s[idx])
            {
                lps[i]=idx+1;
                i++;
                idx++;
            }
            else{
                if(idx)idx=lps[idx-1];
                else lps[i]=idx,i++;
            }
        }
        return lps;
    }
    long long sumScores(string s) {
        int n=s.size();
        vector<int>lps;
        lps = kmp(s);
        int i=n-1;
        //long long ans=0;
        vector<int>ans(n,0);
        for(int  j=0;j<n;j++)
        {
            if(lps[j])ans[j]=ans[lps[j]-1]+1;
        }
        ans[0]=n;
        //for(auto x:ans)cout<<x<<" ";
        //cout<<endl;





        return accumulate(ans.begin(),ans.end(),0LL);

    }
};

class Solution7{
public:

    int dp[22][22];
    int ok;
    int m,n;
    int fun(int i,int j,vector<vector<int>>& grid,int zero)
    {
        if( i<0 || j<0 || i>=m || j>=n|| grid[i][j]==-1 || grid[i][j]==3)return 0;
        if(grid[i][j]==2)
        {

            cout<<zero<<endl;

            if(zero==0)return 1;
            return 0;
        }




        //if(dp[i][j]!=-1)return dp[i][j];
        grid[i][j]=3;


        int d=fun(i+1,j,grid,zero-1);
        int r=fun(i,j+1,grid,zero-1);
        int u=fun(i-1,j,grid,zero-1);
        int l=fun(i,j-1,grid,zero-1);
        grid[i][j]=0;

        return l+u+d+r;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {

        m=grid.size();
        n=grid[0].size();
        //memset(dp,-1,sizeof(dp));
        int x,y;
        int zero=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    x=i,y=j;
                   // break;
                }
                else if(grid[i][j]==0)zero++;
            }

        }
        //cout<<x<<" "<<y<<endl;

        cout<<zero<<endl;
        //return dp[x][y];//
        return fun(x,y,grid,zero);

    }
};

class Solution {
public:
    int mn=100005;
    vector<pair<int,int>>adj[100005];
    int vis[100005];
    void dfs(int node)
    {
        vis[node]=1;
        for(auto child:adj[node])
        {
            int v=child.first;
            int w=child.second;
            mn=min(mn,w);
            if(!vis[v])dfs(v);


        }

    }
    int minScore(int n, vector<vector<int>>& roads) {

        for(int i=0;i<roads.size();i++)
        {
            int x=roads[i][0];
            int y=roads[i][1];
            int w=roads[i][2];
            adj[x].push_back({y,w});
            adj[y].push_back({x,w});
        }
        dfs(1);
        return mn;

    }
};
int main()
{
    Solution obj;
    vector<vector<int>>vv={{1,2,2},{1,3,4},{3,4,7}};
    vector<int>v={1,2,5};

    cout<<obj.minScore(3,vv)<<endl;

}
