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
    if (n == 2) {
        cout << "1 1\n1 2\n\n";
        return;
    }
    if (n == 3) {
        cout << "2 1\n2 3\n3 1\n\n";
        return;
    }
    for (int i = 1; i <= n-2; i++)
        cout << i << ' ' << i << '\n';
    cout << n-1 << ' ' << n << '\n' << n << ' ' << n << "\n\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
