#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> p(n);
    for (ll &i : p)
        cin >> i;
    vector<ll> dp(n, 1);
    for (ll i = n-2; i >= 0; i--)
        dp[i] = dp[i+1] + ((p[i] > p[i+1]) ? (n - i) : 1);
    ll out = 0;
    for (ll i : dp)
        out += i;
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
