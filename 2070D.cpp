#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> p(n+1);
    vector<vector<ll>> c(n+1);
    for (ll i = 2; i <= n; i++) {
        cin >> p[i];
        c[p[i]].push_back(i);
    }
    vector<vector<ll>> depths(n);
    depths[0].push_back(-1);
    queue<pair<ll, ll>> q;
    q.push({1, 0});
    ll max_depth = 0;
    while (!q.empty()) {
        ll node = q.front().first;
        ll depth = q.front().second;
        q.pop();
        depths[depth].push_back(node);
        max_depth = max(max_depth, depth);
        for (ll u : c[node])
            q.push({u, depth+1});
    }
    vector<ll> depth_sum(max_depth+2, 0);
    vector<ll> cont(n+1, 1);
    for (ll depth = max_depth; depth > 0; depth--) {
        for (ll node : depths[depth]) {
            cont[node] = add(cont[node], depth_sum[depth+1]);
            for (ll children : c[node])
                cont[node] = add(cont[node], MOD-cont[children]);
            depth_sum[depth] = add(depth_sum[depth], cont[node]);
        }
    }
    ll out = 1;
    for (ll children : c[1])
        out = add(out, cont[children]);
    cout << out << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
        solve();
}
