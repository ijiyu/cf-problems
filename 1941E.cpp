#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, ll> pii;
#define ff first
#define ss second

const ll N_MAX = 100;
const ll M_MAX = (ll) 2e5;

ll a[N_MAX][M_MAX];
ll minn[N_MAX];
ll dp[M_MAX];

void solve() {
    ll n, m, k, d;
    cin >> n >> m >> k >> d;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> a[i][j];
    for (ll i = 0; i < n; i++) {
        multiset<ll> mst = {1};
        dp[0] = 1;
        for (ll j = 1; j < m - 1; j++) {
            dp[j] = *mst.begin() + a[i][j] + 1;
            if (j - d - 1 >= 0)
                mst.erase(mst.find((dp[j - d - 1])));
            mst.insert(dp[j]);
        }
        dp[m-1] = *mst.begin() + 1;
        minn[i] = dp[m-1];
    }
    ll curr = 0;
    for (ll i = 0; i < k; i++)
        curr += minn[i];
    ll out = curr;
    for (ll i = k; i < n; i++) {
        curr += minn[i] - minn[i - k];
        out = min(out, curr);
    }
    cout << out << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) solve();
}
