#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k < abs(n-m) || k > max(n, m)) {
        cout << -1 << endl;
        return;
    }
    char char0 = '0';
    char char1 = '1';
    if (m > n) {
        int t = n;
        n = m;
        m = t;
        char0 = '1';
        char1 = '0';
    }
    for (int i = 0; i < k; i++)
        cout << char0;
    n -= k;
    while (n > 0 && m > 0) {
        cout << char1;
        m--;
        cout << char0;
        n--;
    }
    for (int i = 0; i < m; i++)
        cout << char1;
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
