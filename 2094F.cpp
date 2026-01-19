#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (m % k != 0) {
        for (int i = 1; i <= n*m; i++) {
            cout << ((i-1)%k+1) << " ";
            if (i % m == 0)
                cout << endl;
        }
        return;
    }
    bool parity = true;
    for (int row = 0; row < n; row++) {
        for (int rpt = 0; rpt < m/k; rpt++)
            for (int i = 1; i <= k; i++)
                cout << (i+parity-1)%k+1 << " ";
        cout << endl;
        parity = !parity;
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

