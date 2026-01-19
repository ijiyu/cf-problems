#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
    return x;
}

int mul(int x, int y) {
    return x * 1LL * y % MOD;
}

int binpow(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int divide(int x, int y) {
    return mul(x, binpow(y, MOD - 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> byR(m + 1);
    vector<int> dp(m + 1);

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;

        int prob = divide(p, q);
        byR[r].push_back({l - 1, prob});
        dp[0] = mul(dp[0], add(1, -prob));
    }

    for (int i = 1; i <= m; i++) {
        for (auto [l, p] : byR[i]) {
            int cur = dp[l];
            cur = divide(cur, add(1, -p));
            cur = mul(cur, p);
            dp[i] = add(dp[i], cur);
        }
    }

    cout << dp[m] << '\n';
}
