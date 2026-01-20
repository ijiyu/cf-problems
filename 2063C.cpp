#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<int> deg(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int out = 0;

    for (int root = 0; root < n; root++) {
        int ans = deg[root];

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
