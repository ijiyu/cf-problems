#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, ll> pii;
#define ff first
#define ss second

const ll MOD = 1e9+7;

ll dp[300001];

void solve() {
    ll n, k;
    cin >> n >> k;
    unordered_set<ll> used;
    for (ll i = 0; i < k; i++) {
        ll r, c;
        cin >> r >> c;
        used.insert(r);
        used.insert(c);
    }
    ll m = n-used.size();
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i <= m; i++)
        dp[i] = (dp[i-1] + 2ll * (i-1) * dp[i-2] % MOD) % MOD;
    cout << dp[m] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) solve();
}
