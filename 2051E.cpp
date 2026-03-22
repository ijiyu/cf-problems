#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, ll> pii;
#define ff first
#define ss second

ll n, k;

ll find_out(vector<ll> &v, vector<ll> &a, vector<ll> &b) {
    ll out = 0;
    for (ll price : v) {
        ll bought = n-static_cast<ll>(distance(b.begin(), lower_bound(b.begin(), b.end(), price)));
        ll pos = n-static_cast<ll>(distance(a.begin(), lower_bound(a.begin(), a.end(), price)));
        ll neg = bought-pos;
        if (neg <= k)
            out = max(out, price*bought);
    }
    return out;
}

void solve() {
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (ll &i : a) cin >> i;
    for (ll &i : b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll out = max(find_out(a, a, b), find_out(b, a, b));
    cout << out << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) solve();
}
