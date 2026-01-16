#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(ll parent, ll node, vector<vector<ll>>& graph, vector<ll>& children) {
    for (ll u : graph[node]) {
        if (u != parent) {
            dfs(node, u, graph, children);
            children[node] += children[u];
        }
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> graph(n);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<ll> children(n, 1);
    dfs(-1, 0, graph, children);
    ll out = 0;
    for (ll i = 0; i < n; i++) {
        if (n - children[i] >= k)
            out += children[i]; 
        if (children[i] >= k)
            out += n - children[i]; 
    }
    cout << out + n << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
        solve();
}
