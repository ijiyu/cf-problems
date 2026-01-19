#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll x, y;
    cin >> x >> y;
    if (x == y) {
        cout << -1 << endl;
        return;
    }
    ll power = (1LL << 30);
    cout << power - max(x, y) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
