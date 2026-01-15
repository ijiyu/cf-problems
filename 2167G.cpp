#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;
    vector<ll> c(n);
    ll total = 0;
    for (ll &i : c) {
        cin >> i;
        total += i;
    }
    vector<ll> dp(n);
    dp[0] = c[0];
    ll out = dp[0];
    for (ll i = 1; i < n; i++) {
        ll maxx = 0;
        for (ll j = 0; j < i; j++)
            maxx = max(maxx, (a[j] <= a[i]) * dp[j]);
        dp[i] = c[i] + maxx;
        out = max(dp[i], out);
    }
    cout << total - out << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--)
        solve();
}
