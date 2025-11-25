#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 998244353

vector<vector<int>> g;
vector<int> lvl0, cnt, dlt, deg;
int n;

void clear_graph(int n)
{
    g.assign(n+1, {});      // n+1 empty adjacency lists
    lvl0.assign(n+1, 0);
    cnt.assign(n+1, 0);
    dlt.assign(n+1, 0);
    deg.assign(n+1, 0);
}

void dfs(int node, int par = -1)
{
    if (deg[node] == 1) lvl0[node] = 1;
    cnt[node] = 1;
    dlt[node] = 0;

    for (auto v : g[node])
    {
        if (v == par) continue;
        dfs(v, node);
        cnt[node] += cnt[v];
        if (cnt[v] > 1) dlt[node] += lvl0[v];
        lvl0[node] += lvl0[v];
    }
}

void base()
{
    cin >> n;
    clear_graph(n);

    int nop = 0;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
        if (deg[u] == n-1 || deg[v] == n-1)
            nop = 1;
    }

    if (nop)
    {
        cout << 0 << "\n";
        return;
    }

    dfs(1, -1);

    ll mn = dlt[1];
    ll curr = mn;
    for (int i = 2; i <= n; i++)
    {
        ll rest = (ll)n - cnt[i];
        if (rest > 1) curr = dlt[i] + lvl0[1] - lvl0[i];
        mn = min(mn, curr);
    }
    cout << mn << "\n";
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--)
    {
        base();
    }
    return 0;
}

