#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define ff first
#define ss second

void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n), b(m);
    for (ll &i : a) cin >> i;
    for (ll &i : b) cin >> i;
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    vector<ll> pa(n+1), pb(m+1);
    for (ll i = 0; i < n; i++) pa[i+1] = pa[i] + a[i];
    for (ll i = 0; i < m; i++) pb[i+1] = pb[i] + b[i];
    vector<pll> pz(n+m+1);
    for (ll i = 0; i < n+m; i++) {
        if (pz[i].ff == n)
            pz[i+1] = {pz[i].ff, pz[i].ss+1};
        else if (pz[i].ss == m)
            pz[i+1] = {pz[i].ff+1, pz[i].ss};
        else {
            bool takeA = a[pz[i].ff] > b[pz[i].ss];
    pz[i+1] = {pz[i].ff + takeA, pz[i].ss + !takeA};
}
    }
    for (ll _ = 0; _ < q; _++) {
        ll x, y, z;
        cin >> x >> y >> z;
        int takeA = pz[z].ff;
        if (takeA > x) takeA = x;
        if (z - takeA > y) takeA = z - y;

        ll out = pa[takeA] + pb[z - takeA];
        cout << out << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) solve();
}
