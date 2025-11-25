#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

const int MOD = 998244353; // Not used in current code but kept for future use

// Graph and auxiliary global variables
vector<vector<int>> graph;
vector<int> leafLevel, subtreeCount, delta, degree;
int n;

// Initialize/reset graph data structures for a new test case
void clearGraph(int size) {
    graph.assign(size + 1, {});
    leafLevel.assign(size + 1, 0);
    subtreeCount.assign(size + 1, 0);
    delta.assign(size + 1, 0);
    degree.assign(size + 1, 0);
}

// DFS to compute subtree sizes and leaf levels
void dfs(int node, int parent = -1) {
    if (degree[node] == 1) leafLevel[node] = 1;
    subtreeCount[node] = 1;
    delta[node] = 0;

    for (int neighbor : graph[node]) {
        if (neighbor == parent) continue;
        dfs(neighbor, node);
        subtreeCount[node] += subtreeCount[neighbor];
        if (subtreeCount[neighbor] > 1) delta[node] += leafLevel[neighbor];
        leafLevel[node] += leafLevel[neighbor];
    }
}

// Solve a single test case
void solve() {
    cin >> n;
    clearGraph(n);

    bool hasStarNode = false;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
        if (degree[u] == n - 1 || degree[v] == n - 1) {
            hasStarNode = true;
        }
    }

    if (hasStarNode) {
        cout << 0 << "\n";
        return;
    }

    dfs(1);

    ll minVal = delta[1];
    ll currentVal = minVal;

    for (int i = 2; i <= n; i++) {
        ll rest = (ll)n - subtreeCount[i];
        if (rest > 1) {
            currentVal = delta[i] + leafLevel[1] - leafLevel[i];
        }
        minVal = min(minVal, currentVal);
    }

    cout << minVal << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        solve();
    }

    return 0;
}
