#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define ff first
#define ss second

void solve() {
    int n;
    cin >> n;
    ll sum = n*(n+1)*(4*n-1)/6;
    cout << sum << ' ' << 2*n << '\n';
    for (int i = n; i >= 1; i--) {
        for (int c = 1; c <= 2; c++) {
            cout << c << ' ' << i << ' ';
            for (int pi = 1; pi <= n; pi++) {
                cout << pi << ' ';
            }
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
